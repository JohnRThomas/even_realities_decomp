/*
 * Production-test lpuart bring-up (init_serial_port / init_serial_comm) and the
 * PT command table.
 *
 * Original path: src/production_test/serial_thread.c (from the __ASSERT
 * __FILE__ string; the assert in init_serial_port() sits at line 46).
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/sys/printk.h>

#include "g1_log.h"
#include "production_test.h"

static uint8_t lpuart_ready;             /* lpuart initialised */

int init_serial_port(void)
{
	const struct device *lpuart = DEVICE_DT_GET(DT_NODELABEL(uart0));

	if (lpuart_ready) {
		return 0;
	}

#line 46 "../src/production_test/serial_thread.c"
	__ASSERT(device_is_ready(lpuart), "LPUART device not ready");

	if (lpuart_async_a(lpuart)) {
		lpuart_ready = 0;
		printk("init_serial_port is failed\n");
		return -1;
	}
	lpuart_ready = 1;

	return 0;
}

/*
 * Serial test thread entry: not referenced, so --gc-sections drops its code, but
 * it is compiled before init_serial_comm and therefore owns the .str1.1 section
 * holding "init_serial_comm is failed\n"; that string is still used, so the
 * section and the banner after it stay in the image (as in the target).
 */
void serial_thread(void)
{
	if (init_serial_port()) {
		return;
	}
	if (setUARTDevice(DEVICE_DT_GET(DT_NODELABEL(uart0)))) {
		printk("init_serial_comm is failed\n");
		return;
	}
	printk("**********************************join in serial thread"
	       "*******************************\n");
	process_pt_data(NULL);
}

int init_serial_comm(void)
{
	if (init_serial_port()) {
		return -1;
	}

	if (setUARTDevice(DEVICE_DT_GET(DT_NODELABEL(uart0)))) {
		printk("init_serial_comm is failed\n");
		k_sleep(K_MSEC(500));
		return -2;
	}

	return process_pt_data(NULL) ? -3 : 0;
}

