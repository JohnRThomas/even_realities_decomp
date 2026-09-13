/*
 * BLE connection handling and ANCS client.
 * Derived from nrf/samples/bluetooth/peripheral_ancs_client.
 */
#include <stdio.h>
#include <string.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>
#include <zephyr/sys/reboot.h>
#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/uuid.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/hci.h>
#include <bluetooth/gatt_dm.h>
#include <bluetooth/services/ancs_client.h>
#include <bluetooth/services/gattp.h>
#include <zephyr/settings/settings.h>
#include <../subsys/bluetooth/host/conn_internal.h>

#include "g1_log.h"
#include "ble_ancs.h"

#define DEVICE_NAME "Even G1"
#define DEVICE_NAME_LEN (sizeof(DEVICE_NAME) - 1)

#define ATTR_DATA_SIZE 32

#define ANCS_MSGQ_MAX 10
#define UID_MSGQ_MAX 10

#define ANCS_THREAD_STACK_SIZE 5120
#define ANCS_THREAD_PRIORITY (-11)

enum {
	DISCOVERY_ANCS_ONGOING,
	DISCOVERY_ANCS_SUCCEEDED,
	SERVICE_CHANGED_INDICATED
};

/* forward declarations (definition order follows GCC's emission order) */
static void discover_ancs(struct bt_conn *conn, bool retry);
static void discover_gattp(struct bt_conn *conn);
static void discover_ancs_first(struct bt_conn *conn);
static void discover_ancs_again(struct bt_conn *conn);
static void discover_ancs_error_found_cb(struct bt_conn *conn, int err, void *ctx);
static void discover_ancs_completed_cb(struct bt_gatt_dm *dm, void *ctx);
static void discover_ancs_not_found_cb(struct bt_conn *conn, void *ctx);
static void indicate_sc_cb(struct bt_gattp *gattp, const struct bt_gattp_handle_range *handle_range, int err);
void start_ancs_work_thread(struct ble_context *ctx);

/* current connection (.bss 0x20007ef4, highest 4-aligned variable of this file) */
struct bt_conn *DAT_20007ef4;
extern void change_work_mode(int mode);
/* declared int here (main.c defines uint8_t): the shipped bt_start compares the full register */
extern int is_master(void);
extern const char *get_serial_number(void);
extern uint8_t FUN_0008069e(void);
extern uint32_t FUN_00080732(void);
extern void FUN_0007fdfa(char *date);
extern void dump_ancs(const char *tag, struct ancs_notif_data *data);
extern int is_on_whitelist_by_identifier(const char *app_id);
extern void send_whilelist_app_info_wrapper(struct ancs_notif_data *data);
extern void ble_process_req_dispatch(struct ble_context *ctx, uint8_t *hdr, uint8_t *data);
/* Multi-packet reassembly buffer shared with ble_proto.c (defined here so that
 * the BLE protocol code only sees an incomplete array type). */
uint8_t DAT_20010995[MULTI_PACKET_BUF_SIZE];
static char device_name[32];
static uint8_t manuf_data[20];
static uint8_t bt_start_busy;
static uint8_t app_id_received;

static uint8_t indicate_sc_count;
static struct bt_ancs_client ancs_c;
static struct bt_gattp gattp;
static struct ble_context *ancs_ble_ctx;
static atomic_t ancs_discovery_flags;
static struct bt_ancs_evt_notif notification_latest;
static struct bt_ancs_attr notif_attr_app_id_latest;
static struct k_msgq ancs_msgq;
static struct k_msgq uid_msgq;

static int security_fail_count;

static struct bt_le_conn_param conn_param = BT_LE_CONN_PARAM_INIT(12, 12, 0, 800);

static struct bt_data ad[] = {
	BT_DATA_BYTES(BT_DATA_FLAGS, (BT_LE_AD_GENERAL | BT_LE_AD_NO_BREDR)),
	{0},
};

static struct bt_data sd[] = {
	BT_DATA(BT_DATA_NAME_COMPLETE, DEVICE_NAME, DEVICE_NAME_LEN),
};

static K_THREAD_STACK_DEFINE(ancs_work_thread_stack, ANCS_THREAD_STACK_SIZE);
static struct k_thread ancs_work_thread;

static const char *lit_eventid[BT_ANCS_EVT_ID_COUNT] = { "Added",
							 "Modified",
							 "Removed" };

static void bt_ancs_notification_source_handler(struct bt_ancs_client *ancs_c,
		int err, const struct bt_ancs_evt_notif *notif);
static void bt_ancs_data_source_handler(struct bt_ancs_client *ancs_c,
		const struct bt_ancs_attr_response *response);
void discover_ancs(struct bt_conn *conn, bool retry);

static const struct bt_gatt_dm_cb discover_ancs_cb = {
	.completed = discover_ancs_completed_cb,
	.service_not_found = discover_ancs_not_found_cb,
	.error_found = discover_ancs_error_found_cb,
};

/**@brief Function for printing out errors that originated from the Notification Provider (iOS).
 *
 * @param[in] err_code_np Error code received from NP.
 */
static void err_code_print(uint8_t err_code_np)
{
	switch (err_code_np) {
	case BT_ATT_ERR_ANCS_NP_UNKNOWN_COMMAND:
		BLE_PRINTK("Error: Command ID was not recognized by the Notification Provider.\n");
		break;
	case BT_ATT_ERR_ANCS_NP_INVALID_COMMAND:
		BLE_PRINTK("Error: Command failed to be parsed on the Notification Provider.\n");
		break;
	case BT_ATT_ERR_ANCS_NP_INVALID_PARAMETER:
		BLE_PRINTK("Error: Parameter does not refer to an existing object on the Notification Provider.\n");
		break;
	case BT_ATT_ERR_ANCS_NP_ACTION_FAILED:
		BLE_PRINTK("Error: Perform Notification Action Failed on the Notification Provider.\n");
		break;
	default:
		break;
	}
}

static void bt_ancs_write_response_handler(struct bt_ancs_client *ancs_c,
					   uint8_t err)
{
	err_code_print(err);
}

static void discover_gattp_completed_cb(struct bt_gatt_dm *dm, void *ctx);
static void discover_gattp_not_found_cb(struct bt_conn *conn, void *ctx);
static void discover_gattp_error_found_cb(struct bt_conn *conn, int err, void *ctx);

static const struct bt_gatt_dm_cb discover_gattp_cb = {
	.completed = discover_gattp_completed_cb,
	.service_not_found = discover_gattp_not_found_cb,
	.error_found = discover_gattp_error_found_cb,
};

static void discover_gattp(struct bt_conn *conn)
{
	int err;

	err = bt_gatt_dm_start(conn, BT_UUID_GATT, &discover_gattp_cb, &gattp);
	if (err) {
		printk("Failed to start discovery for GATT Service (err %d)\n", err);
	}
}

static void mtu_updated(struct bt_conn *conn, uint16_t tx, uint16_t rx)
{
	printk("Updated MTU: TX: %d RX: %d bytes\n", tx, rx);
	if (tx >= 100) {
		k_sem_give(&ancs_ble_ctx->tx_sem);
		if (tx == 498) {
			change_work_mode(1);
		}
	}
}

static void bond_deleted(uint8_t id, const bt_addr_le_t *peer)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(peer, addr, sizeof(addr));
	printk("bond_deleted conn: %s\n", addr);
	ancs_ble_ctx->f_367 = 0;
}

static void check_bonded_addr(const struct bt_bond_info *info, void *user_data)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(&info->addr, addr, sizeof(addr));
	ancs_ble_ctx->f_367 = 0;
	G1_LOG_ERR("Got %s bind addr\n\n", addr);
}

static void pairing_failed(struct bt_conn *conn, enum bt_security_err reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	printk("Pairing failed conn: %s, reason %d\n", addr, reason);
	G1_LOG_ERR("bt_conn_disconnect because Pairing failed\n");
	bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
}

static void auth_cancel(struct bt_conn *conn)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	printk("Pairing cancelled: %s\n", addr);
	G1_LOG_ERR("bt_conn_disconnect because Pairing cancelled\n");
	bt_conn_disconnect(conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
}

static void ancs_security_changed(struct bt_conn *conn, bt_security_t level,
				  enum bt_security_err err)
{
	char addr[BT_ADDR_LE_STR_LEN];

	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));

	if (!err) {
		G1_LOG_INF("%s level %u\n\n", addr, level);
		if (bt_conn_get_security(conn) >= BT_SECURITY_L2) {
			const bt_addr_le_t *dst;

			ancs_discovery_flags = ATOMIC_INIT(0);
			dst = bt_conn_get_dst(conn);
			if (!FUN_00033d5c() && get_dashboard_state()->bonded == 1 &&
			    !memcmp(&get_dashboard_state()->bonded_addr, dst, sizeof(bt_addr_le_t))) {
				discover_gattp(conn);
			}
		}
		ancs_ble_ctx->f_367 = 0;
		security_fail_count = 0;
	} else {
		G1_LOG_INF("Security failed: %s level %u err %d\n\n", addr, level, err);
		security_fail_count++;
		if (security_fail_count >= 10) {
			G1_LOG_ERR("reboot because Security failed exceed 10 times, so reboot\r\n\n");
			k_msleep(500);
			sys_reboot(SYS_REBOOT_COLD);
		}
		bt_conn_set_security(conn, BT_SECURITY_L2);
	}
}

static void ancs_connected(struct bt_conn *conn, uint8_t err)
{
	char addr[BT_ADDR_LE_STR_LEN];
	const bt_addr_le_t *dst = bt_conn_get_dst(conn);

	bt_addr_le_to_str(dst, addr, sizeof(addr));
	printk("%s -- type: 0x%x, role:0x%x force_bind %d", addr, conn->type, conn->role,
	       get_dashboard_state()->force_bind);
	if (err) {
		G1_LOG_ERR("failed (err 0x%02x)\n\n", err);
		return;
	}

	if (!FUN_00033d5c() && !get_dashboard_state()->force_bind &&
	    memcmp(&get_dashboard_state()->bonded_addr, dst, sizeof(bt_addr_le_t))) {
		G1_LOG_ERR("disconnect because invalid mac %s -- type: 0x%x, role:0x%x \n\n",
			   addr, conn->type, conn->role);
		bt_conn_disconnect(conn, BT_HCI_ERR_AUTH_FAIL);
		return;
	}

	bt_conn_le_param_update(conn, &conn_param);
	get_dashboard_state()->ble_context.last_rx_time = k_uptime_get_32();
	get_dashboard_state()->ble_context.connected_time = k_uptime_get_32();
	ancs_ble_ctx->f_365 = 1;
	ancs_ble_ctx->f_367 = 1;
	DAT_20007ef4 = conn;
}

static void on_pairing_complete(struct bt_conn *conn, bool bonded)
{
	char addr[BT_ADDR_LE_STR_LEN];
	const bt_addr_le_t *dst = bt_conn_get_dst(conn);

	bt_addr_le_to_str(dst, addr, sizeof(addr));
	if (get_dashboard_state()->force_bind) {
		get_dashboard_state()->force_bind = 0;
	}
	if (!FUN_00033d5c() &&
	    memcmp(&get_dashboard_state()->bonded_addr, dst, sizeof(bt_addr_le_t))) {
		bt_unpair(BT_ID_DEFAULT, &get_dashboard_state()->bonded_addr);
		get_dashboard_state()->bonded = 0;
		get_dashboard_state()->dashboard_cmd = 0;
		k_sem_give(&get_dashboard_state()->dashboard_position_sem);
	}
	bt_addr_le_copy(&get_dashboard_state()->bonded_addr, dst);
	printk("Pairing completed: %s, bonded: %d\n", addr, bonded);
	ancs_ble_ctx->f_367 = 0;
}

static struct bt_conn_auth_cb conn_auth_callbacks = {
	.cancel = auth_cancel,
};

static struct bt_conn_auth_info_cb conn_auth_info_callbacks = {
	.pairing_complete = on_pairing_complete,
	.pairing_failed = pairing_failed,
	.bond_deleted = bond_deleted,
};

static struct bt_gatt_cb gatt_callbacks = {
	.att_mtu_updated = mtu_updated
};

static uint32_t last_notif_uid = 0xffffffff;

static void discover_ancs_completed_cb(struct bt_gatt_dm *dm, void *ctx);
static void discover_ancs_not_found_cb(struct bt_conn *conn, void *ctx);
static void discover_ancs_error_found_cb(struct bt_conn *conn, int err, void *ctx);

static void discover_ancs(struct bt_conn *conn, bool retry)
{
	int err;

	if (get_dashboard_state()->is_master != 2 || FUN_00033d5c() == 1) {
		return;
	}

	/* 1 Service Discovery at a time */
	if (atomic_test_and_set_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING)) {
		return;
	}

	/* If ANCS is found, do not discover again. */
	if (atomic_test_bit(&ancs_discovery_flags, DISCOVERY_ANCS_SUCCEEDED)) {
		atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
		return;
	}

	/* Check that Service Changed indication is received before discovering ANCS again. */
	if (retry) {
		if (!atomic_test_and_clear_bit(&ancs_discovery_flags, SERVICE_CHANGED_INDICATED)) {
			atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
			return;
		}
	}

	err = bt_gatt_dm_start(conn, BT_UUID_ANCS, &discover_ancs_cb, &ancs_c);
	if (err) {
		printk("Failed to start discovery for ANCS (err %d)\n", err);
		atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
	}
}

static void discover_ancs_first(struct bt_conn *conn)
{
	discover_ancs(conn, false);
}

static void discover_ancs_again(struct bt_conn *conn)
{
	discover_ancs(conn, true);
}

static void discover_gattp_error_found_cb(struct bt_conn *conn, int err, void *ctx)
{
	printk("The discovery procedure for GATT Service failed, err %d\n", err);
	discover_ancs_first(conn);
}

static void discover_ancs_error_found_cb(struct bt_conn *conn, int err, void *ctx)
{
	printk("The discovery procedure for ANCS failed, err %d\n", err);
	atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
	discover_ancs_again(conn);
}

static void enable_ancs_notifications(struct bt_ancs_client *ancs_c)
{
	int err;

	err = bt_ancs_subscribe_notification_source(ancs_c,
			bt_ancs_notification_source_handler);
	if (err) {
		printk("Failed to enable Notification Source notification (err %d)\n",
		       err);
	}

	err = bt_ancs_subscribe_data_source(ancs_c,
			bt_ancs_data_source_handler);
	if (err) {
		printk("Failed to enable Data Source notification (err %d)\n",
		       err);
	}
}

static void discover_ancs_completed_cb(struct bt_gatt_dm *dm, void *ctx)
{
	int err;
	struct bt_ancs_client *ancs_c = (struct bt_ancs_client *)ctx;
	struct bt_conn *conn = bt_gatt_dm_conn_get(dm);

	printk("The discovery procedure for ANCS succeeded\n");

	err = bt_ancs_handles_assign(dm, ancs_c);
	if (err) {
		printk("Could not init ANCS client object, error: %d\n", err);
	} else {
		atomic_set_bit(&ancs_discovery_flags, DISCOVERY_ANCS_SUCCEEDED);
		enable_ancs_notifications(ancs_c);
	}

	err = bt_gatt_dm_data_release(dm);
	if (err) {
		printk("Could not release the discovery data, error "
		       "code: %d\n",
		       err);
	}

	atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
	discover_ancs_again(conn);
}

static void discover_ancs_not_found_cb(struct bt_conn *conn, void *ctx)
{
	printk("ANCS could not be found during the discovery\n");
	atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
	discover_ancs_again(conn);
}

static void enable_gattp_indications(struct bt_gattp *gattp)
{
	int err;

	err = bt_gattp_subscribe_service_changed(gattp, indicate_sc_cb);
	if (err) {
		printk("Cannot subscribe to Service Changed indication (err %d)\n",
		       err);
	}
}

static void discover_gattp_completed_cb(struct bt_gatt_dm *dm, void *ctx)
{
	int err;
	struct bt_gattp *gattp = (struct bt_gattp *)ctx;
	struct bt_conn *conn = bt_gatt_dm_conn_get(dm);

	/* Checks if the service is empty.
	 * Discovery Manager handles empty services.
	 */
	if (bt_gatt_dm_attr_cnt(dm) > 1) {
		printk("The discovery procedure for GATT Service succeeded\n");
		err = bt_gattp_handles_assign(dm, gattp);
		if (err) {
			printk("Could not init GATT Service client object, error: %d\n", err);
		} else {
			enable_gattp_indications(gattp);
		}
	} else {
		printk("GATT Service could not be found during the discovery\n");
	}

	err = bt_gatt_dm_data_release(dm);
	if (err) {
		printk("Could not release the discovery data, error "
		       "code: %d\n",
		       err);
	}

	discover_ancs_first(conn);
}

static void discover_gattp_not_found_cb(struct bt_conn *conn, void *ctx)
{
	printk("GATT Service could not be found during the discovery\n");
	discover_ancs_first(conn);
}

void FUN_00018ba8(void)
{
	atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_ONGOING);
	atomic_clear_bit(&ancs_discovery_flags, DISCOVERY_ANCS_SUCCEEDED);
	atomic_clear_bit(&ancs_discovery_flags, SERVICE_CHANGED_INDICATED);
}

static void ancs_disconnected(struct bt_conn *conn, uint8_t reason)
{
	char addr[BT_ADDR_LE_STR_LEN];

	ancs_ble_ctx->f_365 = 0;
	DAT_20007ef4 = NULL;
	bt_addr_le_to_str(bt_conn_get_dst(conn), addr, sizeof(addr));
	G1_LOG_ERR("from %s (reason 0x%02x)\n", addr, reason);
	ancs_ble_ctx->f_367 = 0;
	while (k_sem_count_get(&get_dashboard_state()->ble_context.tx_sem)) {
		k_sem_take(&get_dashboard_state()->ble_context.tx_sem, K_FOREVER);
	}
	FUN_00018ba8();
}

BT_CONN_CB_DEFINE(conn_callbacks) = {
	.connected = ancs_connected,
	.disconnected = ancs_disconnected,
	.security_changed = ancs_security_changed,
};

static void indicate_sc_cb(struct bt_gattp *gattp,
			   const struct bt_gattp_handle_range *handle_range,
			   int err)
{
	if (!err) {
		indicate_sc_count++;
		if (indicate_sc_count >= 5) {
			indicate_sc_count = 0;
			G1_LOG_ERR("disconnect because can not discover ancs.\n");
			bt_conn_disconnect(gattp->conn, BT_HCI_ERR_REMOTE_USER_TERM_CONN);
			return;
		}
		atomic_set_bit(&ancs_discovery_flags, SERVICE_CHANGED_INDICATED);
		discover_ancs_again(gattp->conn);
	}
}

int init_msgq_ancs(void)
{
	int err;

	err = k_msgq_alloc_init(&ancs_msgq, sizeof(struct ancs_notif_data), ANCS_MSGQ_MAX);
	if (err) {
		G1_LOG_ERR("k_msgq alloc failed\n");
	}
	return err;
}

int enqueue_ancs(struct ancs_notif_data *data)
{
	struct ancs_notif_data msg;
	int err;

	memset(&msg, 0, sizeof(msg));
	if (ancs_msgq.max_msgs == 0) {
		return 1;
	}
	if (k_msgq_num_used_get(&ancs_msgq) == ANCS_MSGQ_MAX) {
		k_msgq_get(&ancs_msgq, &msg, K_NO_WAIT);
		BLE_PRINTK("enqueue ancs drop package! \n");
	}
	memcpy(&msg, data, sizeof(msg));
	err = k_msgq_put(&ancs_msgq, &msg, K_NO_WAIT);
	if (err) {
		G1_LOG_ERR("en ancs F\n");
	}
	return err;
}

/* the dashboard is not in a mode that suppresses notifications */
#define ANCS_NOTIF_MODE_ALLOWED()                                                   \
	(get_dashboard_state()->f_d5 != 11 && get_dashboard_state()->f_d5 != 10 &&  \
	 get_dashboard_state()->f_d5 != 9 && get_dashboard_state()->f_d5 != 12 &&   \
	 get_dashboard_state()->f_d5 != 16 && get_dashboard_state()->f_d5 != 20 &&  \
	 get_dashboard_state()->f_d5 != 14 && get_dashboard_state()->f_d5 != 15 &&  \
	 get_dashboard_state()->f_d5 != 17 && get_dashboard_state()->f_d5 != 18 &&  \
	 get_dashboard_state()->f_d5 != 19)

/* wait while the ESB link is busy */
#define ANCS_WAIT_ESB_IDLE()                                                        \
	while (get_dashboard_state()->f_001 == 1 ||                           \
	       get_dashboard_state()->f_001 == 8) {                           \
		k_sleep(K_MSEC(5000));                                              \
	}

static void bt_ancs_data_source_handler(struct bt_ancs_client *ancs_c,
		const struct bt_ancs_attr_response *response)
{
	struct ble_context *ctx = get_ble_context();

	G1_LOG_ERR("bt_ancs_data_source_handler response->command_id %d\n", response->command_id);

	switch (response->command_id) {
	case BT_ANCS_COMMAND_ID_GET_NOTIF_ATTRIBUTES:
		if (response->attr.attr_id == BT_ANCS_NOTIF_ATTR_ID_APP_IDENTIFIER) {
			notif_attr_app_id_latest = response->attr;
			app_id_received = 1;
		}
		break;
	case BT_ANCS_COMMAND_ID_GET_APP_ATTRIBUTES:
		if (app_id_received && notification_latest.notif_uid != last_notif_uid) {
			if (k_uptime_get_32() - get_dashboard_state()->ble_context.connected_time < 10000) {
				break;
			}
			ANCS_WAIT_ESB_IDLE();
			if (ANCS_NOTIF_MODE_ALLOWED()) {
				last_notif_uid = notification_latest.notif_uid;
				ctx->notif.action = notification_latest.evt_id;
				enqueue_ancs(&ctx->notif);
				G1_LOG_ERR("=========================>bt_ancs_get_attr_data_sem %d evt_id %d action %d\n",
					   notification_latest.notif_uid, notification_latest.evt_id,
					   ctx->notif.action);
				memset(&ctx->notif, 0, sizeof(ctx->notif));
				k_sem_give(&ctx->ancs_get_attr_data_sem);
				app_id_received = 0;
			}
		}
		break;
	default:
		/* No implementation needed. */
		break;
	}
}

int dequeue_ancs(struct ancs_notif_data *data)
{
	struct ancs_notif_data msg;
	int err;

	memset(&msg, 0, sizeof(msg));
	if (ancs_msgq.max_msgs == 0) {
		return 1;
	}
	err = k_msgq_get(&ancs_msgq, &msg, K_NO_WAIT);
	if (err) {
		G1_LOG_ERR("D ancs F\n");
	} else {
		memcpy(data, &msg, sizeof(msg));
	}
	return err;
}

int init_msgq_uid(void)
{
	int err;

	err = k_msgq_alloc_init(&uid_msgq, sizeof(struct bt_ancs_evt_notif), UID_MSGQ_MAX);
	if (err) {
		G1_LOG_ERR("k_msgq alloc failed\n");
	}
	return err;
}

int enqueue_uid(const struct bt_ancs_evt_notif *notif)
{
	struct bt_ancs_evt_notif local_data;
	int err;

	memset(&local_data, 0, sizeof(local_data));
	if (uid_msgq.max_msgs == 0) {
		return 1;
	}
	if (k_msgq_num_used_get(&uid_msgq) == UID_MSGQ_MAX) {
		k_msgq_get(&uid_msgq, &local_data, K_NO_WAIT);
		BLE_PRINTK("enqueue uid drop package! \n");
	}
	memcpy(&local_data, notif, sizeof(local_data));
	G1_LOG_ERR("local_data uid %d\n", local_data.notif_uid);
	err = k_msgq_put(&uid_msgq, &local_data, K_NO_WAIT);
	if (err) {
		G1_LOG_ERR("en uid F\n");
	}
	return err;
}

static void bt_ancs_notification_source_handler(struct bt_ancs_client *ancs_c,
		int err, const struct bt_ancs_evt_notif *notif)
{
	struct ble_context *ctx = get_ble_context();

	if (err) {
		return;
	}
	printk("\nNotification UID:         %u\nEvent:       %s\n", notif->notif_uid,
	       lit_eventid[notif->evt_id]);
	if (k_uptime_get_32() - get_dashboard_state()->ble_context.connected_time < 10000) {
		return;
	}
	ANCS_WAIT_ESB_IDLE();
	if (!ANCS_NOTIF_MODE_ALLOWED() || notif->evt_id >= BT_ANCS_EVT_ID_COUNT) {
		return;
	}
	if (enqueue_uid(notif)) {
		return;
	}
	G1_LOG_ERR("============================>bt_ancs_get_attr_req_sem %d count %d notif->evt_id %d\n",
		   notif->notif_uid, k_sem_count_get(&ctx->ancs_get_attr_req_sem), notif->evt_id);
	memset(&ctx->notif, 0, sizeof(ctx->notif));
	if (notif->evt_id == BT_ANCS_EVENT_ID_NOTIFICATION_REMOVED) {
		ctx->notif.uid = notif->notif_uid;
	}
	k_sem_give(&ctx->ancs_get_attr_req_sem);
}

int dequeue_uid(struct bt_ancs_evt_notif *notif)
{
	struct bt_ancs_evt_notif local_data;
	int err;

	memset(&local_data, 0, sizeof(local_data));
	if (uid_msgq.max_msgs == 0) {
		return 1;
	}
	err = k_msgq_get(&uid_msgq, &local_data, K_NO_WAIT);
	if (err) {
		G1_LOG_ERR("D uid F\n");
	} else {
		memcpy(notif, &local_data, sizeof(local_data));
	}
	return err;
}

/*
 * The error logs below print __LINE__; the original file had ancs_c_init()
 * at line 948 (logs at 954..1002), so re-sync the line counter here.
 */
#line 948
int ancs_c_init(struct ancs_notif_data *data)
{
	int err;

	err = bt_ancs_client_init(&ancs_c);
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_attr(&ancs_c,
		BT_ANCS_NOTIF_ATTR_ID_APP_IDENTIFIER,
		data->app_identifier, ATTR_DATA_SIZE);
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_app_attr(&ancs_c,
		BT_ANCS_APP_ATTR_ID_DISPLAY_NAME,
		data->display_name, sizeof(data->display_name));
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_attr(&ancs_c,
		BT_ANCS_NOTIF_ATTR_ID_TITLE,
		data->title, ATTR_DATA_SIZE);
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_attr(&ancs_c,
		BT_ANCS_NOTIF_ATTR_ID_SUBTITLE,
		data->subtitle, ATTR_DATA_SIZE);
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_attr(&ancs_c,
		BT_ANCS_NOTIF_ATTR_ID_MESSAGE,
		data->message, sizeof(data->message));
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	err = bt_ancs_register_attr(&ancs_c,
		BT_ANCS_NOTIF_ATTR_ID_DATE,
		data->date, ATTR_DATA_SIZE);
	if (err) {
		G1_LOG_ERR("%d: err=%d\n", __LINE__, err);
		return err;
	}

	return 0;
}

int gattp_init(void)
{
	return bt_gattp_init(&gattp);
}

int request_ancs_attr_ext(void)
{
	struct ble_context *ctx = get_ble_context();
	uint16_t retry_time = 0;
	int err;

	err = bt_ancs_request_attrs(&ancs_c, &notification_latest,
				    bt_ancs_write_response_handler);

	do {
		if (notif_attr_app_id_latest.attr_id == BT_ANCS_NOTIF_ATTR_ID_APP_IDENTIFIER &&
		    notif_attr_app_id_latest.attr_len != 0 &&
		    notif_attr_app_id_latest.attr_data[0] != '\0' &&
		    ctx->notif.app_identifier[0] != '\0') {
			goto request;
		}
		k_sleep(K_MSEC(1));
		retry_time++;
	} while (retry_time != 1001);

	G1_LOG_ERR("notif_attr_app_id_latest.attr_id %d notif_attr_app_id_latest.attr_len %d "
		   "strlen(notif_attr_app_id_latest.attr_data) %d c->notifi_data.app_identifier %d\n",
		   notif_attr_app_id_latest.attr_id, notif_attr_app_id_latest.attr_len,
		   strlen(notif_attr_app_id_latest.attr_data), ctx->notif.app_identifier[0]);

	if (notif_attr_app_id_latest.attr_id == BT_ANCS_NOTIF_ATTR_ID_APP_IDENTIFIER) {
request:
		if (notif_attr_app_id_latest.attr_len != 0 &&
		    notif_attr_app_id_latest.attr_data[0] != '\0') {
			BLE_PRINTK("Request for %s: retry_time %d\n",
				   notif_attr_app_id_latest.attr_data, retry_time);
			while (retry_time < 200) {
				err = bt_ancs_request_app_attr(&ancs_c,
					notif_attr_app_id_latest.attr_data,
					notif_attr_app_id_latest.attr_len,
					bt_ancs_write_response_handler);
				if (!err) {
					goto out;
				}
				retry_time++;
				k_sleep(K_MSEC(5));
			}
			if (err) {
				printk("Failed requesting attributes for a given app (err: %d)\n", err);
			}
		}
	}
out:
	BLE_PRINTK("notif_attr_app_id_latest.attr_id (%d/%d) retry_time %d\n",
		   notif_attr_app_id_latest.attr_id, notif_attr_app_id_latest.attr_len, retry_time);
	return err;
}

int bt_start(void)
{
	int err;

	while (bt_start_busy) {
		k_msleep(1);
	}
	bt_start_busy = 1;

	if (get_dashboard_state()->bt_state == 2 || get_dashboard_state()->bt_state == 0) {
		bt_start_busy = 0;
		return 0;
	}

	ad[1].type = BT_DATA_MANUFACTURER_DATA;
	ad[1].data_len = sizeof(manuf_data);
	if (is_master() == 1) {
		manuf_data[0] = 1;
	} else {
		manuf_data[0] = 2;
	}
	ad[1].data = manuf_data;
	strcpy(&manuf_data[1], get_serial_number());

	printk("c->esb_channel %d\r\n", get_dashboard_state()->esb_channel);

	if (is_master() == 1) {
		if (FUN_00033d5c() == 1) {
			if (get_dashboard_state()->esb_channel != 0xff) {
				sprintf(device_name, "%sV%d%d%d_%d_R_%02X%02X%02X", DEVICE_NAME,
					FUN_0008069e(), 6, 3, get_dashboard_state()->esb_channel,
					get_dashboard_state()->ble_context.mac_r[2],
					get_dashboard_state()->ble_context.mac_r[1],
					get_dashboard_state()->ble_context.mac_r[0]);
			} else {
				sprintf(device_name, "%sV%d%d%d_R_%02X%02X%02X", DEVICE_NAME,
					FUN_0008069e(), 6, 3,
					get_dashboard_state()->ble_context.mac_r[2],
					get_dashboard_state()->ble_context.mac_r[1],
					get_dashboard_state()->ble_context.mac_r[0]);
			}
		} else {
			if (get_dashboard_state()->esb_channel != 0xff) {
				sprintf(device_name, "%s_%d_R_%02X%02X%02X", DEVICE_NAME,
					get_dashboard_state()->esb_channel,
					get_dashboard_state()->ble_context.mac_r[2],
					get_dashboard_state()->ble_context.mac_r[1],
					get_dashboard_state()->ble_context.mac_r[0]);
			} else {
				sprintf(device_name, "%s_R_%02X%02X%02X", DEVICE_NAME,
					get_dashboard_state()->ble_context.mac_r[2],
					get_dashboard_state()->ble_context.mac_r[1],
					get_dashboard_state()->ble_context.mac_r[0]);
			}
		}
	} else {
		if (FUN_00033d5c() == 1) {
			if (get_dashboard_state()->esb_channel != 0xff) {
				sprintf(device_name, "%sV%d%d%d_%d_L_%02X%02X%02X", DEVICE_NAME,
					FUN_0008069e(), 6, 3, get_dashboard_state()->esb_channel,
					get_dashboard_state()->ble_context.mac_l[2],
					get_dashboard_state()->ble_context.mac_l[1],
					get_dashboard_state()->ble_context.mac_l[0]);
			} else {
				sprintf(device_name, "%sV%d%d%d_L_%02X%02X%02X", DEVICE_NAME,
					FUN_0008069e(), 6, 3,
					get_dashboard_state()->ble_context.mac_l[2],
					get_dashboard_state()->ble_context.mac_l[1],
					get_dashboard_state()->ble_context.mac_l[0]);
			}
		} else {
			if (get_dashboard_state()->esb_channel != 0xff) {
				sprintf(device_name, "%s_%d_L_%02X%02X%02X", DEVICE_NAME,
					get_dashboard_state()->esb_channel,
					get_dashboard_state()->ble_context.mac_l[2],
					get_dashboard_state()->ble_context.mac_l[1],
					get_dashboard_state()->ble_context.mac_l[0]);
			} else {
				sprintf(device_name, "%s_L_%02X%02X%02X", DEVICE_NAME,
					get_dashboard_state()->ble_context.mac_l[2],
					get_dashboard_state()->ble_context.mac_l[1],
					get_dashboard_state()->ble_context.mac_l[0]);
			}
		}
	}

	sd[0].data = device_name;
	sd[0].data_len = strlen(device_name);

	err = bt_set_name(device_name);
	if (err) {
		G1_LOG_ERR("Failed to set device name (err %d)\n\n", err);
	} else {
		err = bt_le_adv_start(BT_LE_ADV_PARAM(BT_LE_ADV_OPT_CONNECTABLE, 0x160, 0x1e0, NULL),
				      ad, ARRAY_SIZE(ad), sd, ARRAY_SIZE(sd));
		if (!err) {
			get_dashboard_state()->bt_state = 2;
			printk("Advertising %s successfully started uptime %lld\n", device_name,
			       k_ticks_to_ms_ceil64(k_uptime_ticks()));
		}
	}
	bt_start_busy = 0;
	return err;
}

void recv_ble_data(struct ble_context *ctx)
{
	uint8_t hdr[4] = {0x4b, 0, 0, 0};
	struct ancs_notif_data data;
	int ret;

	memset(&data, 0, sizeof(data));
	if (dequeue_ancs(&data) == 0 && (data.action >= 2 || data.app_identifier[0] != '\0')) {
		data.msg_id = FUN_00080732();
		if (data.msg_id == 0) {
			data.msg_id = 1;
		}
		data.uid = notification_latest.notif_uid;
		dump_ancs("FROM:ancs", &data);
		if (data.action >= 2) {
			goto type2;
		}
		ret = is_on_whitelist_by_identifier(data.app_identifier);
		if (ret == 2) {
			goto type2;
		}
		if (ret == 3) {
			hdr[1] = 4;
			goto dispatch;
		}
		if (ret != 1) {
			return;
		}
		/* BLE_PRINTK() split in two: the plain printk arm sits after the type-2 path */
		if (BLE_DEBUG) {
			ble_printk("blocked! app(%s) not in whitelist \n", data.app_identifier);
			send_whilelist_app_info_wrapper(&data);
			return;
		}
		if (0) {
type2:
			hdr[1] = 2;
			goto dispatch;
		}
		printk("blocked! app(%s) not in whitelist \n", data.app_identifier);
		send_whilelist_app_info_wrapper(&data);
		return;
dispatch:
		if (notification_latest.category_id == BT_ANCS_CATEGORY_ID_MISSED_CALL) {
			strncpy(data.app_identifier, "com.apple.mobilephone_missed",
				sizeof(data.app_identifier));
		}
		FUN_0007fdfa(data.date);
		ble_process_req_dispatch(ctx, hdr, (uint8_t *)&data);
	}
}

static void ble_ancs_data_req_thread(void *p1, void *p2, void *p3)
{
	struct ble_context *ctx = p1;

	G1_LOG_INF("enter\n");
	k_sem_init(&ctx->ancs_get_attr_req_sem, 0, 10);
	k_sem_init(&ctx->ancs_get_attr_data_sem, 0, 10);
	init_msgq_ancs();
	init_msgq_uid();
	k_sleep(K_MSEC(5000));

	while (1) {
		while (get_dashboard_state()->f_001 == 1 ||
		       get_dashboard_state()->f_001 == 8) {
			k_sleep(K_MSEC(5000));
		}
		if (!(get_dashboard_state()->module_mask & BIT(7))) {
			k_msleep(1000);
			continue;
		}
		G1_LOG_ERR("!!!!!!!!!wait -> ancs_get_attr_req_sem\n");
		k_sem_take(&ctx->ancs_get_attr_req_sem, K_FOREVER);
		if (dequeue_uid(&notification_latest)) {
			continue;
		}
		G1_LOG_ERR("!!!!!!!!!!!!!!get -> ancs_get_attr_req_sem %d evt_id %d\n",
			   notification_latest.notif_uid, notification_latest.evt_id);
		if (notification_latest.evt_id < BT_ANCS_EVENT_ID_NOTIFICATION_REMOVED) {
			request_ancs_attr_ext();
			G1_LOG_ERR("!!!!!!!!!!!!wait -> ancs_get_attr_req_sem add done, and wait -> "
				   "ancs_get_attr_data_sem\n");
			k_sem_take(&ctx->ancs_get_attr_data_sem, K_MSEC(1000));
		} else {
			ctx->notif.action = BT_ANCS_EVENT_ID_NOTIFICATION_REMOVED;
			ctx->notif.uid = notification_latest.notif_uid;
			ctx->notif.f_00d = 0;
			/* vendor bug: a string literal is stored into a char (keeps the
			 * low byte of its address) */
			ctx->notif.app_identifier[0] = (char)(uintptr_t)"\r";
			ctx->notif.display_name[0] = (char)(uintptr_t)"\r";
			ctx->notif.f_00e = 0;
			enqueue_ancs(&ctx->notif);
			memset(&ctx->notif, 0, sizeof(ctx->notif));
			G1_LOG_ERR("!!!!!!!!!!!!wait -> ancs_get_attr_req_sem remove done, and wait -> "
				   "ancs_get_attr_data_sem\n");
		}
		recv_ble_data(ctx);
		G1_LOG_ERR("!!!!!!!!!!!!!!!!wait -> ancs_get_attr_data_sem done\n");
	}
}

int ancs_main(struct ble_context *ctx)
{
	int err;
	int bt_retry_count = 5;
	int wait = 50;

	ancs_ble_ctx = ctx;
	G1_LOG_ERR("Starting Apple Notification Center Service client\n\n");

	while (bt_retry_count) {
		for (;;) {
			if (get_dashboard_state()->bt_state != 0 || wait == 0) {
				break;
			}
			wait--;
			k_msleep(100);
		}
		err = bt_enable(NULL);
		if (!err) {
			break;
		}
		bt_disable();
		printk("BLE init failed (err %d) bt_retry_count %d\n", err, bt_retry_count);
		bt_retry_count--;
		k_msleep(1000);
	}

	bt_foreach_bond(BT_ID_DEFAULT, check_bonded_addr, NULL);
	settings_load();

	err = ancs_c_init(&ctx->notif);
	if (err) {
		printk("ANCS client init failed (err %d)\n", err);
		goto fail;
	}

	err = gattp_init();
	if (err) {
		printk("GATT Service client init failed (err %d)\n", err);
		goto fail;
	}

	err = bt_conn_auth_cb_register(&conn_auth_callbacks);
	if (err) {
		printk("Failed to register authorization callbacks\n");
		goto fail;
	}

	err = bt_conn_auth_info_cb_register(&conn_auth_info_callbacks);
	if (err) {
		printk("Failed to register authorization info callbacks.\n");
		goto fail;
	}

	bt_gatt_cb_register(&gatt_callbacks);

	err = init_nus();
	if (err) {
		printk("Failed to init nus.\n");
		goto fail;
	}

	err = bt_start();
	if (err) {
		printk("Advertising %s failed to start (err %d)\n", device_name, err);
		goto fail;
	}

	start_ancs_work_thread(ctx);
	return 0;

fail:
	printk("ancs or ncs init failure, reboot it\n");
	k_msleep(1000);
	G1_LOG_ERR("reboot because ancs start failed\r\n\n");
	k_msleep(500);
	sys_reboot(SYS_REBOOT_COLD);
}

void start_ancs_work_thread(struct ble_context *ctx)
{
	if (get_dashboard_state()->is_master != 2 || FUN_00033d5c() == 1) {
		return;
	}
	k_thread_create(&ancs_work_thread, ancs_work_thread_stack,
			K_THREAD_STACK_SIZEOF(ancs_work_thread_stack),
			ble_ancs_data_req_thread, ctx, NULL, NULL,
			ANCS_THREAD_PRIORITY, 0, K_NO_WAIT);
	G1_LOG_INF("exit\n\n");
}

void FUN_0007f38a(uint32_t uid)
{
	struct ble_context *ctx = get_ble_context();
	struct bt_ancs_evt_notif notif;

	notif.notif_uid = uid;
	notif.evt_id = BT_ANCS_EVENT_ID_NOTIFICATION_REMOVED;
	if (!enqueue_uid(&notif)) {
		k_sem_give(&ctx->ancs_get_attr_req_sem);
	}
}

int FUN_00019c80(int enable)
{
	FUN_00018ba8();
	if (enable) {
		if (DAT_20007ef4 == NULL) {
			return 0;
		}
		discover_gattp(DAT_20007ef4);
		if (get_dashboard_state()->bonded) {
			return 0;
		}
		get_dashboard_state()->bonded = 1;
	} else {
		if (get_dashboard_state()->bonded != 1) {
			return 0;
		}
		get_dashboard_state()->bonded = 0;
	}
	get_dashboard_state()->dashboard_cmd = 0;
	k_sem_give(&get_dashboard_state()->dashboard_position_sem);
	return 0;
}

struct bt_conn *FUN_00019cec(void)
{
	return DAT_20007ef4;
}

/* align-2 helpers (advertising / bond state), last in this file's align-2 range */
int stop_ble_advertising(void)
{
	int err = 0;

	if (get_dashboard_state()->bt_state == 2) {
		err = bt_le_adv_stop();
		if (err == 0) {
			get_dashboard_state()->bt_state = 3;
		}
	}
	return err;
}

bool FUN_0007f3da(void)
{
	bt_addr_le_t addr;

	memset(&addr, 0, sizeof(addr));
	if (bt_addr_le_cmp(&get_dashboard_state()->bonded_addr, &addr) == 0) {
		return false;
	}
	memset(&addr, 0xff, sizeof(addr));
	return bt_addr_le_cmp(&get_dashboard_state()->bonded_addr, &addr) != 0;
}
