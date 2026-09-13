/*
 * Zephyr driver init functions the application calls directly.  Neither driver
 * declares them in a header.
 */
#ifndef G1_VENDOR_DRIVERS_H_
#define G1_VENDOR_DRIVERS_H_

#include <zephyr/device.h>

/* drivers/sensor/lsm6dso/lsm6dso.c: non-static in the vendor's zephyr tree, where
 * the device has no init function of its own.  On a stock tree
 * imu/lsm6dso_stock.c stands in. */
int lsm6dso_init(const struct device *dev);

/* drivers/sensor/npm1300_charger/npm1300_charger.c (non-static in stock Zephyr) */
int npm1300_charger_init(const struct device *dev);

/* subsys/bluetooth/host/hci_core.c, added in the vendor's zephyr tree:
 * bt_hci_cmd_send_sync() with a timeout in ms; without assert_on_timeout a timeout logs
 * an error and returns -ETIMEDOUT.  On a stock tree ble/bt_hci_stock.c stands in. */
struct net_buf;
int bt_hci_cmd_send_sync_timeout(uint16_t opcode, struct net_buf *buf, struct net_buf **rsp,
				 int32_t timeout_ms, bool assert_on_timeout);

#endif /* G1_VENDOR_DRIVERS_H_ */
