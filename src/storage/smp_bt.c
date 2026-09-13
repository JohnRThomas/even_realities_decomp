/*
 * BT connection callbacks of the SMP (mcumgr over BLE) transport glue.
 * Original file name unknown.
 */
#include <zephyr/kernel.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include "g1_log.h"

int smp_busy;                        /* 0x20007f7c */
int smp_conn_ok;                     /* 0x20007f78 */
static struct k_work smp_adv_work;   /* 0x20007f68 (never initialised) */

static void smp_connected(struct bt_conn *conn, uint8_t err)
{
	if (err) {
		G1_LOG_ERR("failed (err 0x%02x)\n", err);
		return;
	}
	smp_conn_ok = 1;
	G1_LOG_INF("ok\n");
}

static void smp_disconnected(struct bt_conn *conn, uint8_t reason)
{
	G1_LOG_ERR("(reason 0x%02x)\n", reason);
	if (smp_adv_work.handler) {
		k_work_submit(&smp_adv_work);
	}
	smp_busy = 0;
	smp_conn_ok = 0;
}

BT_CONN_CB_DEFINE(smp_conn_callbacks) = {
	.connected = smp_connected,
	.disconnected = smp_disconnected,
};
