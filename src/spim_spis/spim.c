/*
 * SPI master (nrfx SPIM3 / SPIM4) used by the display panel.
 *
 * Original path: src/spim_spis/spim.c (from the __FILE__ string of the
 * NRFX_SUCCESS assertion).  Link order: after imu_fusion.c
 * (align-4 0x28388..0x28693, align-2 0x7fdf0..0x7fe2d).
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/irq.h>
#include <nrfx_spim.h>

#include <g1_log.h>

/* spi_interface_t (GlassesState + 0xb10) */
struct spi_master_ctx {
	int (*init_cb)(struct spi_master_ctx *ctx);				/* 0x00 */
	int (*deinit_cb)(struct spi_master_ctx *ctx);				/* 0x04 */
	int (*xfer_cb)(struct spi_master_ctx *ctx, const uint8_t *tx, size_t tx_len,
		       uint8_t *rx, size_t rx_len);				/* 0x08 */
	nrfx_spim_t spim;							/* 0x0c */
	uint32_t is_initialized;						/* 0x14 */
	uint8_t bus;								/* 0x18: 3 or 4 */
	uint8_t sck;								/* 0x19 */
	uint8_t mosi;								/* 0x1a */
	uint8_t miso;								/* 0x1b */
	uint8_t ss;								/* 0x1c */
	uint8_t speed_mhz;							/* 0x1d */
	volatile uint8_t xfer_done;						/* 0x1e */
	uint8_t pad_1f;
};
static uint8_t spim4_irq_connected;

static uint8_t spim3_irq_connected;

static void spim_event_handler(nrfx_spim_evt_t const *p_event, void *p_context)
{
	struct spi_master_ctx *ctx = p_context;

	if (p_event->type == NRFX_SPIM_EVENT_DONE) {
		ctx->xfer_done = 1;
	}
}

int spi_master_trans_data_tx_rx(struct spi_master_ctx *ctx, const uint8_t *tx,
				       size_t tx_len, uint8_t *rx, size_t rx_len)
{
	nrfx_spim_xfer_desc_t desc = NRFX_SPIM_XFER_TRX(tx, tx_len, rx, rx_len);
	nrfx_err_t err;

	if (!ctx->is_initialized) {
		G1_LOG_ERR("wait init_done.\n");
		return -1;
	}

	err = nrfx_spim_xfer(&ctx->spim, &desc, 0);
	if (err != NRFX_SUCCESS) {
		G1_LOG_ERR("sipm(bus=%d)-sync fail: status: %d -- %d\n", ctx->bus, err,
			   NRFX_SUCCESS);
		return -1;
	}

	return 0;
}

static int spi_master_deinit(struct spi_master_ctx *ctx)
{
	nrfx_spim_t spim3;
	nrfx_spim_t spim4;
	uint8_t bus, sck, mosi, miso, ss, speed;

	spim3.p_reg = NRF_SPIM3;
	spim3.drv_inst_idx = NRFX_SPIM3_INST_IDX;
	spim4.p_reg = NRF_SPIM4;
	spim4.drv_inst_idx = NRFX_SPIM4_INST_IDX;
	if (!ctx->is_initialized) {
		return 0;
	}
	bus = ctx->bus;
	sck = ctx->sck;
	mosi = ctx->mosi;
	miso = ctx->miso;
	ss = ctx->ss;
	speed = ctx->speed_mhz;

	switch (bus) {
	default:
		G1_LOG_ERR(" SPIM BUS ERR!\n");
		return 0;
	case 4:
		memcpy(&ctx->spim, &spim4, sizeof(nrfx_spim_t));
		break;
	case 3:
		memcpy(&ctx->spim, &spim3, sizeof(nrfx_spim_t));
		break;
	}

	G1_LOG_INF("*SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n", bus,
		   speed, sck, mosi, miso, ss);
	nrfx_spim_uninit(&ctx->spim);
	G1_LOG_INF("spim(bus=%d): uninit finish\n", ctx->bus);
	ctx->is_initialized = 0;

	return 0;
}

static int spi_master_init(struct spi_master_ctx *ctx)
{
	nrfx_spim_t spim3 = NRFX_SPIM_INSTANCE(3);
	nrfx_spim_t spim4 = NRFX_SPIM_INSTANCE(4);
	nrfx_spim_config_t config = {
		.irq_priority = 7,
		.orc = 0xff,
		.dcx_pin = NRF_SPIM_PIN_NOT_CONNECTED,
		.rx_delay = 2,
		.ss_duration = 2,
	};
	nrfx_err_t status;
	uint8_t bus;

	if (ctx->is_initialized == 1) {
		return 0;
	}
	config.frequency = ctx->speed_mhz * 1000000;
	bus = ctx->bus;
	config.sck_pin = ctx->sck;
	config.mosi_pin = ctx->mosi;
	config.miso_pin = ctx->miso;
	config.ss_pin = ctx->ss;

	switch (bus) {
	default:
		G1_LOG_ERR(" SPIM BUS ERR!\n");
		return 0;
	case 4:
		memcpy(&ctx->spim, &spim4, sizeof(nrfx_spim_t));
		break;
	case 3:
		memcpy(&ctx->spim, &spim3, sizeof(nrfx_spim_t));
		break;
	}

	G1_LOG_INF("*SPIM(%d)speed=%dM, sck=%d, mosi=%d, miso=%d, ss=%d\n", bus,
		   ctx->speed_mhz, ctx->sck, ctx->mosi, ctx->miso, ctx->ss);

	if (ctx->bus == 3) {
		status = nrfx_spim_init(&ctx->spim, &config, spim_event_handler, ctx);
	} else {
		status = nrfx_spim_init(&ctx->spim, &config, NULL, NULL);
	}
	/* vendor line of this assertion (our struct definitions above make the file longer) */
#line 104 "../src/spim_spis/spim.c"
	__ASSERT_NO_MSG(status == NRFX_SUCCESS);

	if (ctx->bus != 3) {
		if (!spim4_irq_connected) {
			spim4_irq_connected = 1;
			IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_SPIM4), 6, nrfx_isr, nrfx_spim_4_irq_handler, 0);
		}
	} else {
		if (!spim3_irq_connected) {
			spim3_irq_connected = 1;
			IRQ_CONNECT(NRFX_IRQ_NUMBER_GET(NRF_SPIM3), 6, nrfx_isr, nrfx_spim_3_irq_handler, 0);
		}
	}

	G1_LOG_INF("spim(bus=%d): init finish\n", ctx->bus);
	ctx->is_initialized = 1;

	return 0;
}

void spi_master_register_context(struct spi_master_ctx *ctx)
{
	ctx->init_cb = spi_master_init;
	ctx->xfer_cb = spi_master_trans_data_tx_rx;
	ctx->deinit_cb = spi_master_deinit;
}

/*
 * Reorders a BCD/ASCII time stamp "MMDDhhmm.." in place into "MM-DD hh:mm".
 * Called from recv_ble_data; it sits between spim.c and the attitude filter
 * in align-2 code and has no align-4 sibling, so its file is unknown.
 */
int FUN_0007fdfa(uint8_t *s)
{
	s[0] = s[4];
	s[1] = s[5];
	s[2] = '-';
	s[3] = s[6];
	s[4] = s[7];
	s[5] = ' ';
	s[6] = s[9];
	s[7] = s[10];
	s[8] = ':';
	s[9] = s[11];
	s[10] = s[12];
	s[11] = 0;

	return 12;
}
