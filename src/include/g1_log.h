/*
 * Vendor logging helpers.
 *
 * Every vendor log line is "%s(): <msg>" with __func__, gated on the runtime
 * LOG_LEVEL and routed to ble_printk() when BLE_DEBUG is set, otherwise to
 * printk().  The arguments are evaluated separately in each branch, which is
 * what the shipped code does (e.g. k_uptime_get() is called in both arms).
 */
#ifndef G1_LOG_H_
#define G1_LOG_H_

#include <zephyr/sys/printk.h>

extern int LOG_LEVEL;
extern int BLE_DEBUG;

void ble_printk(const char *fmt, ...);

#define G1_LOG(lvl, fmt, ...)                                                       \
	do {                                                                        \
		if (LOG_LEVEL > (lvl)) {                                            \
			if (BLE_DEBUG) {                                            \
				ble_printk("%s(): " fmt, __func__, ##__VA_ARGS__);  \
			} else {                                                    \
				printk("%s(): " fmt, __func__, ##__VA_ARGS__);      \
			}                                                           \
		}                                                                   \
	} while (0)

#define G1_LOG_ERR(fmt, ...) G1_LOG(0, fmt, ##__VA_ARGS__)
#define G1_LOG_WRN(fmt, ...) G1_LOG(1, fmt, ##__VA_ARGS__)
#define G1_LOG_INF(fmt, ...) G1_LOG(2, fmt, ##__VA_ARGS__)
#define G1_LOG_DBG(fmt, ...) G1_LOG(3, fmt, ##__VA_ARGS__)

#endif /* G1_LOG_H_ */
