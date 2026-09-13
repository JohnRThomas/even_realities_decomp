/*
 * bt_hci_cmd_send_sync_timeout() for a stock zephyr tree.
 *
 * The vendor's zephyr tree adds this variant of
 * bt_hci_cmd_send_sync() to subsys/bluetooth/host/hci_core.c: a caller-chosen
 * timeout and, without assert_on_timeout, an error return instead of the
 * BT_ASSERT.  Stock zephyr has only bt_hci_cmd_send_sync(), whose HCI_CMD_TIMEOUT
 * asserts.  This weak stand-in, which the vendor tree's definition replaces, keeps
 * the plain build linking.
 */
#include <zephyr/bluetooth/hci.h>
#include <zephyr/toolchain.h>

#include <vendor_drivers.h>

__weak int bt_hci_cmd_send_sync_timeout(uint16_t opcode, struct net_buf *buf,
					 struct net_buf **rsp, int32_t timeout_ms,
					 bool assert_on_timeout)
{
	ARG_UNUSED(timeout_ms);
	ARG_UNUSED(assert_on_timeout);
	return bt_hci_cmd_send_sync(opcode, buf, rsp);
}
