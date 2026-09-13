/*
 * PDM microphone capture (derived from the Zephyr dmic sample), LC3 encoding
 * of the captured blocks and the DMIC message queue.
 * Reconstructed from the v1.63 firmware image.
 */
#include <stdlib.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/flash.h>
#include <zephyr/audio/dmic.h>
#include <zephyr/sys/atomic.h>

#include "lc3.h"

#include "g1_log.h"
#include "sensors_audio.h"

/* other modules */
struct ble_context {
	uint8_t pad_000[0x218];
	struct k_sem rx_sem;                     /* 0x218 */
	uint8_t pad_230[0x248 - 0x230];
	uint8_t receiver_thd_is_running;         /* 0x248 */
};
extern struct ble_context *FUN_00018320(void);
extern int enqueue_bt_data(void *data, uint8_t len);
extern uint8_t FUN_00033d5c(void);           /* test (production) mode */
extern void FUN_0004d4f8(int64_t *ts);

#define DMIC_DEV  DEVICE_DT_GET(DT_NODELABEL(pdm0))
#define FLASH_DEV DEVICE_DT_GET(DT_NODELABEL(mx25r64))

#define DMIC_MODULE_ON BIT(1)

#define AUDIO_FLASH_START 0x400000
#define AUDIO_FLASH_END   0x410000

#define MAX_SAMPLE_RATE  16000
#define SAMPLE_BIT_WIDTH 16
#define BYTES_PER_SAMPLE sizeof(int16_t)
#define READ_TIMEOUT     1000
#define BLOCK_SIZE(_sample_rate, _number_of_channels) \
	(BYTES_PER_SAMPLE * (_sample_rate / 10) * _number_of_channels)
#define MAX_BLOCK_SIZE BLOCK_SIZE(MAX_SAMPLE_RATE, 1)
#define BLOCK_COUNT    10

#define LC3_FRAME_US    10000
#define LC3_SAMPLE_RATE 16000
#define LC3_FRAME_BYTES 20

#define DMIC_MSGQ_LEN 10

K_MEM_SLAB_DEFINE_STATIC(dmic_mem_slab, MAX_BLOCK_SIZE, BLOCK_COUNT, 4);

struct k_msgq dmic_msgq;                     /* 0x2000855c */
atomic_t DAT_20008558;                       /* audio stream record running */
static uint32_t audio_flash_offset = AUDIO_FLASH_START; /* 0x20002404 */
uint8_t DAT_20019a77;                        /* set when the BLE rx thread was kicked */
static uint8_t dmic_stop_state = 1;          /* 0x20003052 (.data): 1 = stop, 2 = paused */

struct dmic_msg {
	uint8_t data[DMIC_MSG_SIZE];
};

/* 4-aligned in the target (0x8bd7c, aligned .rodata area, not among the strings) */
static const struct dmic_msg dmic_msg_empty __aligned(4);

int init_dmic_msgq(void)
{
	int ret = k_msgq_alloc_init(&dmic_msgq, DMIC_MSG_SIZE, DMIC_MSGQ_LEN);

	if (ret) {
		G1_LOG_ERR("dmic init failed\n");
	}
	return ret;
}

int clean_dmic_msgq(void)
{
	int ret = k_msgq_cleanup(&dmic_msgq);

	if (ret) {
		G1_LOG_ERR("dmic cleanup failed\n");
	}
	return ret;
}

int enqueue_dmic(void *msg)
{
	struct dmic_msg data = dmic_msg_empty;
	uint32_t used = dmic_msgq.used_msgs;
	int ret;

	if (used == DMIC_MSGQ_LEN) {
		k_msgq_get(&dmic_msgq, &data, K_NO_WAIT);
		G1_LOG_ERR("enqueue_dmic num is full, drop it %d\r\n\n", used);
	}
	memcpy(&data, msg, DMIC_MSG_SIZE);
	ret = k_msgq_put(&dmic_msgq, &data, K_NO_WAIT);
	if (ret) {
		G1_LOG_ERR("enqueue_dmic failed\r\n\n");
	}
	return ret;
}

uint32_t get_dmic_num_messages(void)
{
	return dmic_msgq.used_msgs;
}

int dequeue_dmic(void *msg)
{
	struct dmic_msg data = dmic_msg_empty;
	int ret;

	ret = k_msgq_get(&dmic_msgq, &data, K_NO_WAIT);
	if (ret) {
		G1_LOG_ERR("dequeue_dmic failed\r\n\n");
	} else {
		memcpy(msg, &data, DMIC_MSG_SIZE);
	}
	return ret;
}
void app_codec_lc3_test(void *pcm, int len)
{
	const struct device *flash_dev = FLASH_DEV;
	unsigned int enc_size = lc3_encoder_size(LC3_FRAME_US, LC3_SAMPLE_RATE);
	uint16_t frame_size = lc3_frame_samples(LC3_FRAME_US, LC3_SAMPLE_RATE) * 2;
	void *enc_mem = malloc(enc_size);
	void *pcm_buf = malloc(frame_size);
	uint16_t frames = len / frame_size;
	uint8_t *out = malloc(frames * LC3_FRAME_BYTES);
	lc3_encoder_t encoder;
	int ret;

	if (enc_mem == NULL || pcm_buf == NULL || out == NULL) {
		G1_LOG_ERR("malloc error\r\n\n");
		goto out;
	}
	if (FUN_00033d5c() == 1 && !device_is_ready(flash_dev)) {
		G1_LOG_ERR(" [%s] device not ready.\n\n", flash_dev->name);
		goto out;
	}

	encoder = lc3_setup_encoder(LC3_FRAME_US, LC3_SAMPLE_RATE, 0, enc_mem);
	for (int i = 0; i < frames; i++) {
		ret = lc3_encode(encoder, LC3_PCM_FORMAT_S16, (uint8_t *)pcm + i * frame_size, 1, LC3_FRAME_BYTES, out + i * LC3_FRAME_BYTES);
		if (ret) {
			G1_LOG_ERR("lc3_encode did not return zero %d\n", ret);
			goto out;
		}
	}

	if (FUN_00033d5c() == 1) {
		if (audio_flash_offset < AUDIO_FLASH_END) {
			ret = flash_write(flash_dev, audio_flash_offset, out, frames * LC3_FRAME_BYTES);
			if (ret) {
				G1_LOG_ERR("Flash write failed! %d\n\n", ret);
				goto out;
			}
			G1_LOG_ERR("Flash write to addr 0x%x\n\n", audio_flash_offset);
			audio_flash_offset += frames * LC3_FRAME_BYTES;
		}
	} else if (atomic_get(&DAT_20008558)) {
		int64_t ts = 0;

		FUN_0004d4f8(&ts);
		G1_LOG_INF("send audio stream data to storage thread,timestemp = %lld\n", ts);
		sendAudioStram2Cache(out);
	} else {
		enqueue_dmic(out);
	}
out:
	if (enc_mem) {
		free(enc_mem);
	}
	if (pcm_buf) {
		free(pcm_buf);
	}
	if (out) {
		free(out);
	}
}

uint8_t dmic_get_stop_state(void)
{
	if (get_dashboard_state()->is_master == 1) {
		return dmic_stop_state;
	}
	return 0;
}

int dmic_stream_stop(void)
{
	if (dmic_stop_state != 1) {
		if (FUN_00033d5c() == 1 || get_dashboard_state()->is_master == 1) {
			dmic_stop_state = 1;
		}
	}
	return 0;
}

int dmic_stream_pause(int pause)
{
	if (get_dashboard_state()->is_master == 1) {
		if (pause) {
			dmic_stop_state = 2;
		} else {
			dmic_stop_state = 0;
		}
	}
	return 0;
}

/*
 * G1_LOG_ERR with the printk arm written first (`if (!BLE_DEBUG)`): same behaviour, but the
 * shipped code's block placement of the shared log tails (RTL crossjump/bb-reorder) needs this
 * arm order at the device-not-ready and flash-write-failed sites of do_pdm_transfer.
 */
#define G1_LOG_ERR_PRINTK_FIRST(fmt, ...)                                           \
	do {                                                                        \
		if (LOG_LEVEL > 0) {                                                \
			if (!BLE_DEBUG) {                                           \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);      \
			} else {                                                    \
				ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);  \
			}                                                           \
		}                                                                   \
	} while (0)

/*
 * One capture block: read, store to flash or feed the LC3 test, free.  buffer/size live in an
 * inner block that closes before the return (its end-of-scope clobbers then sit before the
 * caller's exec-failed check, which keeps DOM's LOG_LEVEL jump threading of the error paths)
 * and lets size share its stack slot with the caller's cmd[].
 */
static int do_pdm_transfer(const struct device *dmic_dev)
{
	int ret;

	{
		void *buffer = NULL;
		uint32_t size;

		if (FUN_00033d5c() == 1 && get_dashboard_state()->f_10a4 == 1 &&
		    !device_is_ready(FLASH_DEV)) {
			G1_LOG_ERR_PRINTK_FIRST(" [%s] device not ready.\n", FLASH_DEV->name);
			ret = -1;
			goto out;
		}
		ret = dmic_read(dmic_dev, 0, &buffer, &size, READ_TIMEOUT);
		if (ret) {
			G1_LOG_ERR("dmic_read failed %d\n", ret);
			goto out;
		}
		if (FUN_00033d5c() == 1 && get_dashboard_state()->f_10a4 == 1) {
			if (audio_flash_offset < AUDIO_FLASH_END - size) {
				ret = flash_write(FLASH_DEV, audio_flash_offset, buffer, size);
				if (ret) {
					G1_LOG_ERR_PRINTK_FIRST("Flash write failed! %d\n\n", ret);
					goto out;
				}
				G1_LOG_ERR("Flash write to addr 0x%x\n\n", audio_flash_offset);
				audio_flash_offset += size;
			}
		} else if (buffer) {
			app_codec_lc3_test(buffer, size);
		}
out:
		if (buffer) {
			k_mem_slab_free(&dmic_mem_slab, buffer);
		}
	}
	if (ret) {
		return -1;
	}
	return ret;
}

int dmic_stream_start(void)
{
	struct ble_context *ble = FUN_00018320();
	const struct device *const dmic_dev = DMIC_DEV;
	int ret = 0;
	struct pcm_stream_cfg stream;
	struct dmic_cfg cfg;

	if (get_dashboard_state()->module_mask & DMIC_MODULE_ON) {
		G1_LOG_INF("DMIC sample\n");
		if (!device_is_ready(dmic_dev)) {
			G1_LOG_ERR("%s is not ready\n", dmic_dev->name);
			ret = 1;
		} else {
			G1_LOG_INF("%s is ready\n", dmic_dev->name);
			if (init_dmic_msgq()) {
				ret = 1;
				goto stop;
			}
			stream = (struct pcm_stream_cfg){
				.pcm_width = SAMPLE_BIT_WIDTH,
				.mem_slab = &dmic_mem_slab,
			};
			cfg = (struct dmic_cfg){
				.io = {
					.min_pdm_clk_freq = 1000000,
					.max_pdm_clk_freq = 3500000,
					.min_pdm_clk_dc = 40,
					.max_pdm_clk_dc = 60,
				},
				.streams = &stream,
				.channel = {
					.req_num_streams = 1,
				},
			};

			cfg.channel.req_num_chan = 1;
			cfg.channel.req_chan_map_lo = dmic_build_channel_map(0, 0, PDM_CHAN_LEFT);
			cfg.streams[0].pcm_rate = MAX_SAMPLE_RATE;
			cfg.streams[0].block_size =
				BLOCK_SIZE(cfg.streams[0].pcm_rate, cfg.channel.req_num_chan);

			if (FUN_00033d5c() == 1) {
				ret = erase_audio_buffer();
				if (ret < 0) {
					G1_LOG_ERR("Failed to erase_audio_buffer %d\n", ret);
					goto err;
				}
			}
			ret = dmic_configure(dmic_dev, &cfg);
			if (ret < 0) {
				G1_LOG_ERR("Failed to configure the driver: %d\n", ret);
				goto err;
			}
			ret = dmic_trigger(dmic_dev, DMIC_TRIGGER_START);
			if (ret < 0) {
				G1_LOG_ERR("START trigger failed: %d\n", ret);
				goto err;
			}
			DAT_20019a77 = 0;
			dmic_stop_state = 0;
			while (dmic_stop_state != 1) {
				ret = do_pdm_transfer(dmic_dev);
				if (ret < 0) {
					G1_LOG_ERR("!!!do_pdm_transfer exec failed.\n");
					goto err;
				}
				if (dmic_stop_state == 0 && FUN_00033d5c() == 0 &&
				    k_msgq_num_used_get(&dmic_msgq) != 0) {
					if (ble->receiver_thd_is_running != 0 ||
					    k_sem_count_get(&ble->rx_sem) != 0) {
						uint8_t cmd[3] = { 0 };

						cmd[0] = 0xf1;
						cmd[2] = 0xcc;
						enqueue_bt_data(cmd, sizeof(cmd));
					} else {
						DAT_20019a77 = 1;
						k_sem_give(&ble->rx_sem);
					}
				}
			}
		}
	}

stop:
	if (dmic_trigger(dmic_dev, DMIC_TRIGGER_STOP) < 0) {
		G1_LOG_ERR("STOP trigger failed\n");
	} else {
		G1_LOG_ERR("STOP trigger Success\n");
	}
	clean_dmic_msgq();
	audio_flash_offset = AUDIO_FLASH_START;
	G1_LOG_INF("Exiting\n");
	return ret;

err:
	ret = -1;
	goto stop;
}

int erase_audio_buffer(void)
{
	int ret = flash_erase(FLASH_DEV, AUDIO_FLASH_START, AUDIO_FLASH_END - AUDIO_FLASH_START);

	if (ret) {
		G1_LOG_ERR("Flash erase failed! %d\n\n", ret);
	} else {
		audio_flash_offset = AUDIO_FLASH_START;
		G1_LOG_INF("Flash erase ok \n\n");
	}
	return ret;
}

/* old Ghidra names, kept as aliases until the callers in other modules are renamed */
extern __typeof__(dmic_get_stop_state) FUN_00030440 __attribute__((alias("dmic_get_stop_state")));
extern __typeof__(dmic_stream_stop) FUN_00030458 __attribute__((alias("dmic_stream_stop")));
extern __typeof__(dmic_stream_pause) FUN_00030484 __attribute__((alias("dmic_stream_pause")));
