/*
 * Production-test transport selection: forwards reads/writes to the NFC
 * mailbox (ST25DV) or the lpuart.
 */
#include <zephyr/kernel.h>

#include "production_test.h"
#include "../nfc/st25dv.h"

int comm_write(int type, void *ctx, uint8_t *data, size_t len)
{
	if (ctx == NULL || data == NULL || len == 0 || type == PT_COMM_NONE) {
		printk("comm_write para is error\n");
		return -1;
	}

	switch (type) {
	case PT_COMM_NFC:
		return eeprom_st25dv_write_i2c_mb_mailbox_ram(ctx, data, len);
	case PT_COMM_UART:
		return lpuart_async_b(ctx, data, len);
	default:
		break;
	}

	return 0;
}

int comm_read(int type, void *ctx, uint8_t **data, uint32_t *len)
{
	if (ctx == NULL || data == NULL || len == NULL || type == PT_COMM_NONE) {
		return -1;
	}

	switch (type) {
	case PT_COMM_NFC:
		return eeprom_st25dv_read_i2c_mb_mailbox_ram(ctx, data, len);
	case PT_COMM_UART:
		return read_serial_data(ctx, data, len);
	default:
		break;
	}

	return 0;
}
