/*
 * IPC service (icmsg, "ipc0") glue between the application core and the
 * network core: endpoint, receive dispatch table and send helper.
 *
 * Original file name unknown.  Link order: after eeprom_st25dv.c / st25dv.c
 * (align-4 0x27c54..0x27f37, no align-2 code).
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/ipc/ipc_service.h>
#include <zephyr/sys/reboot.h>

#include <g1_log.h>

#define IPC_RECEIVER_MAX	22

/* GlassesState offset of the context (receivers get the GlassesState) */
#define GS_IPC_CTX_OFFSET	0x714

struct GlassesState;
struct GlassesState *get_dashboard_state(void);

struct ipc_ep_cfg {
	uint8_t id;
	const char *name;
	int (*recv_cb)(struct GlassesState *gs, const uint8_t *data, size_t len);
};

struct ipc_service_context {
	uint32_t f_00;
	int count;
	struct ipc_ep_cfg *receivers[IPC_RECEIVER_MAX];
	int (*send)(const void *data, size_t len);		/* 0x60 */
	int (*register_recv_cb)(struct ipc_ep_cfg *ep);		/* 0x64 */
};

int global_ipc_service_send(const void *data, size_t len);
int register_ipc_service_recv_callback(struct ipc_ep_cfg *ep);

static struct ipc_service_context *GLOBAL_IPC_SERVICE_CONTEXT;
static int ipc_ready;
static struct ipc_ept ipc0_ept;
static int ipc_send_fail_cnt;

static K_SEM_DEFINE(ipc0_bound_sem, 0, 1);

/* definition order = the target's __func__ / string order (defperm) */
void ipc0_ept_recv(const void *data, size_t len, void *priv);

static void ipc0_ept_bound(void *priv)
{
	k_sem_give(&ipc0_bound_sem);
}

int global_ipc_service_send(const void *data, size_t len)
{
	int ret;

	if (ipc_ready == 1 && ((uint8_t *)get_dashboard_state())[1] != 8 &&
	    ((uint8_t *)get_dashboard_state())[1] != 9) {
		ret = ipc_service_send(&ipc0_ept, data, len);
		if (ret < 0) {
			G1_LOG_ERR("ipc_service_send data failed with ret %d %d\n", ret,
				   ipc_send_fail_cnt);
			if (++ipc_send_fail_cnt > 2) {
				G1_LOG_ERR("sys reboot because ipc failed\n");
				k_msleep(500);
				sys_reboot(SYS_REBOOT_COLD);
			}
		} else {
			ipc_send_fail_cnt = 0;
		}
	} else {
		ret = -1;
		G1_LOG_ERR("ipc_service not ready!\n");
	}

	return ret;
}

static struct ipc_ept_cfg ipc0_ept_cfg = {
	.name = "ipc0",
	.cb = {
		.bound = ipc0_ept_bound,
		.received = ipc0_ept_recv,
	},
};

int serialization_init(void)
{
	const struct device *ipc0_instance = DEVICE_DT_GET(DT_NODELABEL(ipc0));
	int ret;

	ret = ipc_service_open_instance(ipc0_instance);
	if ((ret < 0) && (ret != -EALREADY)) {
		G1_LOG_ERR("ipc_service_open_instance() failure\n");
		return -1;
	}

	ret = ipc_service_register_endpoint(ipc0_instance, &ipc0_ept, &ipc0_ept_cfg);
	if (ret < 0) {
		G1_LOG_ERR("ipc_service_register_endpoint() failure\n");
		return -1;
	}

	k_sem_take(&ipc0_bound_sem, K_FOREVER);
	ipc_ready = 1;
	G1_LOG_WRN("ipc_service[HOST] has ready!\n\n");

	return 0;
}

void ipc0_ept_recv(const void *data, size_t len, void *priv)
{
	struct ipc_service_context *ctx = GLOBAL_IPC_SERVICE_CONTEXT;
	const uint8_t *buf = data;
	uint8_t cmd = buf[0];
	struct ipc_ep_cfg *ep;
	int i;

	for (i = 0; i < ctx->count; i++) {
		ep = ctx->receivers[i];
		if (ep && ep->id == cmd) {
			ep->recv_cb((struct GlassesState *)((uint8_t *)ctx - GS_IPC_CTX_OFFSET),
				    buf + 1, len - 1);
			return;
		}
	}

	G1_LOG_WRN("NOT MATCH(cmd=%x)! ipc_receiver_index: %d, len:%d, received_data: "
		   "%02x,%02x,%02x,%02x,%02x,%02x,%02x,%02x\n",
		   cmd, ctx->count, len, cmd, buf[1], buf[2], buf[3], buf[4], buf[5], buf[6],
		   buf[7]);
}

int register_ipc_service_context(struct ipc_service_context *ctx)
{
	ctx->send = global_ipc_service_send;
	ctx->register_recv_cb = register_ipc_service_recv_callback;
	GLOBAL_IPC_SERVICE_CONTEXT = ctx;
	G1_LOG_WRN("exit\n\n");

	return 0;
}
int register_ipc_service_recv_callback(struct ipc_ep_cfg *ep)
{
	struct ipc_service_context *ctx = GLOBAL_IPC_SERVICE_CONTEXT;

	if (ctx->count < IPC_RECEIVER_MAX) {
		ctx->receivers[ctx->count] = ep;
		ctx->count++;
		return 0;
	}

	G1_LOG_ERR("ipc_service_register(%d,%s) %d,total must < %d\n", ep->id, ep->name,
		   ctx->count, IPC_RECEIVER_MAX);
	return -1;
}
