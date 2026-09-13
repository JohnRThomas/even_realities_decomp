/*
 * Production-test lpuart transport (UART async API), derived from the NCS
 * lpuart sample (nrf/samples/peripheral/lpuart).
 *
 * Original path: src/production_test/serial_port.c (from the __ASSERT
 * __FILE__ string; the asserts in uart_callback() sit at lines 81 and 84).
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/uart.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "production_test.h"

#define BUF_SIZE 256
static K_MEM_SLAB_DEFINE(uart_slab, BUF_SIZE, 3, 4);

/* last complete frame received on the lpuart */
static uint8_t serial_rx_buf[BUF_SIZE];
static uint8_t serial_rx_len;

/* hex dump of the rx buffer when it holds no complete frame */
static void serial_rx_dump(struct uart_event *evt, size_t offset)
{
	uint32_t k;

	printk("recv data %d bytes:", evt->data.rx.len);
	for (k = 0; k < evt->data.rx.len; k++) {
		printk("%02x ", evt->data.rx.buf[offset + k]);
	}
	printk("\n");
}

static void uart_callback(const struct device *dev, struct uart_event *evt, void *user_data)
{
	struct device *uart = user_data;
	uint8_t *p;
	uint8_t *buf;
	uint8_t len;
	uint8_t sum;
	uint16_t i;
	uint32_t j;
	size_t tx_len;
	size_t offset;
	int k;
	int err;

	switch (evt->type) {
	case UART_TX_DONE:
		tx_len = evt->data.tx.len;
		G1_LOG_INF("Tx sent %d bytes\n", tx_len);
		for (j = 0; j < evt->data.tx.len; j++) {
			printk("%02x ", evt->data.tx.buf[j]);
		}
		printk("\n");
		break;

	case UART_TX_ABORTED:
		G1_LOG_ERR("Tx aborted\n");
		break;

	case UART_RX_RDY:
		offset = evt->data.rx.offset;
		for (i = offset; i < 248; i++) {
			p = &evt->data.rx.buf[i];
			if (p[0] == 0x5a && p[1] == 0xa5 && p[2] == 0x7f) {
				len = p[3] + 5;
				if (len > BUF_SIZE - i) {
					continue;
				}
				sum = 0;
				for (k = 0; k < len - 1; k++) {
					sum += evt->data.rx.buf[i + k];
				}
				if (sum == evt->data.rx.buf[i + len - 1]) {
					serial_rx_len = len;
					memcpy(serial_rx_buf, p, len);
					memset(evt->data.rx.buf, 0, BUF_SIZE);
					return;
				}
			}
		}
		serial_rx_dump(evt, offset);
		break;

	case UART_RX_BUF_REQUEST:
	{
		printk("*************alloc new rx buf*************\n");
		err = k_mem_slab_alloc(&uart_slab, (void **)&buf, K_NO_WAIT);
#line 81 "../src/production_test/serial_port.c"
		__ASSERT(err == 0, "Failed to allocate slab");

		err = uart_rx_buf_rsp(uart, buf, BUF_SIZE);
		__ASSERT(err == 0, "Failed to provide new buffer");
		break;
	}

	case UART_RX_BUF_RELEASED:
		printk("****************************UART_RX_BUF_RELEASED"
		       "***************************************\n");
		k_mem_slab_free(&uart_slab, (void *)evt->data.rx_buf.buf);
		break;

	default:
		break;
	}
}

static inline int serial_args_invalid(const struct device *dev, uint8_t **data)
{
	return dev == NULL || data == NULL;
}

int read_serial_data(const struct device *dev, uint8_t **data, uint32_t *len)
{
	uint8_t *p;
	uint8_t *d;
	uint8_t n;
	int j;
	uint16_t i;
	int idx;
	uint8_t sum;

	if (serial_args_invalid(dev, data) || len == NULL) {
		return -1;
	}
	if (serial_rx_len == 0) {
		return -2;
	}

	for (i = 0; i <= BUF_SIZE - serial_rx_len; i++) {
		idx = i;
		if (serial_rx_buf[idx] == 0x5a && serial_rx_buf[idx + 1] == 0xa5 && serial_rx_buf[idx + 2] == 0x7f &&
		    serial_rx_buf[idx + 3] + 4 < BUF_SIZE - i) {
			n = serial_rx_buf[idx + 3];
			sum = 0;
			for (j = 0; j <= n + 3; j++) {
				sum += serial_rx_buf[i + j];
			}
			if (serial_rx_buf[i + n + 4] == sum) {
				d = *data;
				p = &serial_rx_buf[i + 4];
				memcpy(d, p, n);
				*len = n;
				printk("use read_serial_data:");
				for (j = 0; j < n; j++) {
					printk("%02x ", d[j]);
				}
				printk("\n");
				break;
			}
		}
	}

	if (i > BUF_SIZE - serial_rx_len) {
		serial_rx_len = 0;
		printk("Err:serial recv data does not meet the protocol\n");
		return -3;
	}
	serial_rx_len = 0;

	return 0;
}

int lpuart_async_b(const struct device *dev, uint8_t *data, size_t len)
{
	int err;

	if (dev == NULL || data == NULL || len == 0) {
		return -1;
	}

	err = uart_tx(dev, data, len, 10000);
	if (err) {
		printk("Failed to initiate transmission\n");
		return -2;
	}

	k_sleep(K_MSEC(500));
	uart_poll_out(dev, data[0]);
	k_sleep(K_MSEC(100));

	return err;
}

int lpuart_async_a(const struct device *dev)
{
	uint8_t *buf;
	int err;

	if (dev == NULL) {
		return -1;
	}

	err = k_mem_slab_alloc(&uart_slab, (void **)&buf, K_NO_WAIT);
	if (err) {
		printk("Failed to alloc slab\n");
		return -1;
	}

	err = uart_callback_set(dev, uart_callback, (void *)dev);
	if (err) {
		printk("Failed to set callback\n");
		return -2;
	}

	err = uart_rx_enable(dev, buf, BUF_SIZE, 10000);
	if (err) {
		printk("Failed to enable RX\n");
		return -3;
	}

	return 0;
}

void serial_rx_clear(void)
{
	serial_rx_len = 0;
	memset(serial_rx_buf, 0, sizeof(serial_rx_buf));
}
