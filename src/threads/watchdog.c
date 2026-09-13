/*
 * Hardware watchdog helpers (derived from samples/drivers/watchdog).
 * Reconstructed from the G1 v1.63 app core.
 */
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/watchdog.h>
#include "g1_log.h"
#include "threads.h"

#define WDT_RETRY_COUNT 5

static const struct device *const wdt = DEVICE_DT_GET(DT_NODELABEL(pmic_wdt)); /* nPM1300 watchdog */
int wdt_0_channel_id;

int init_watchdog(void)
{
	int err;
	int i;

	if (!device_is_ready(wdt)) {
		G1_LOG_ERR("%s: device not ready.\n", wdt->name);
		return 0;
	}

	struct wdt_timeout_cfg wdt_config;

	memset(&wdt_config, 0, sizeof(wdt_config));
	wdt_config.window.max = 30000U;
	wdt_config.flags = WDT_FLAG_RESET_SOC;

	wdt_0_channel_id = wdt_install_timeout(wdt, &wdt_config);
	if (wdt_0_channel_id == -ENOTSUP) {
		G1_LOG_ERR("Callback support rejected, continuing anyway\n");
		wdt_config.callback = NULL;
		wdt_0_channel_id = wdt_install_timeout(wdt, &wdt_config);
	}
	if (wdt_0_channel_id < 0) {
		G1_LOG_ERR("Watchdog install error\n");
		return 0;
	}

	err = wdt_setup(wdt, WDT_OPT_PAUSE_HALTED_BY_DBG);
	if (err < 0) {
		G1_LOG_ERR("Watchdog setup error\n");
		return 0;
	}

	for (i = WDT_RETRY_COUNT; i > 0; i--) {
		if (wdt_feed(wdt, wdt_0_channel_id) == 0) {
			break;
		}
		k_sleep(K_MSEC(50));
	}
	return 0;
}

int watchdog_feed(void)
{
	int err;
	int i;

	for (i = WDT_RETRY_COUNT; i > 0; i--) {
		err = wdt_feed(wdt, wdt_0_channel_id);
		if (err == 0) {
			break;
		}
		k_sleep(K_MSEC(50));
	}
	return err;
}

int watchdog_disable(void)
{
	int err;
	int i;

	if (wdt_0_channel_id < 0) {
		return 0;
	}
	for (i = WDT_RETRY_COUNT; i > 0; i--) {
		err = wdt_disable(wdt);
		if (err == 0) {
			break;
		}
		k_sleep(K_MSEC(50));
	}
	if (err == 0) {
		wdt_0_channel_id = -EBUSY;
		return 0;
	}
	return err;
}
