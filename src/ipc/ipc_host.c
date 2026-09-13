/*
 * IPC service (icmsg, "ipc0") glue between the application core and the
 * network core: endpoint, receive dispatch table and send helper.
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/ipc/ipc_service.h>
#include <zephyr/sys/reboot.h>

#include "../threads/threads.h"

#include <g1_log.h>
#include <glasses_state.h>
#include "ipc_host.h"




int global_ipc_service_send(const void *data, size_t len);
int register_ipc_service_recv_callback(struct ipc_ep_cfg *ep);

static struct ipc_service_context *GLOBAL_IPC_SERVICE_CONTEXT;
static int ipc_ready;
static struct ipc_ept ipc0_ept;
static int ipc_send_fail_cnt;

static K_SEM_DEFINE(ipc0_bound_sem, 0, 1);

/* definition order = the target's __func__ / string order (defperm) */
void ipc0_ept_recv(const void *data, size_t len, void *priv);
static void ipc0_ept_bound(void *priv);

int global_ipc_service_send(const void *data, size_t len)
{
	int ret;

	if (ipc_ready == 1 && get_dashboard_state()->work_mode != 8 &&
	    get_dashboard_state()->work_mode != 9) {
		ret = ipc_service_send(&ipc0_ept, data, len);
		if (ret < 0) {
			G1_LOG_ERR("ipc_service_send data failed with ret %d %d\n", ret,
				   ipc_send_fail_cnt);
			if (++ipc_send_fail_cnt > 2) {
				G1_LOG_ERR("sys reboot because ipc failed\n");
				system_reboot_delayed();
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

/* 1.66: defined after global_ipc_service_send (emission order) */
static void ipc0_ept_bound(void *priv)
{
	k_sem_give(&ipc0_bound_sem);
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

	ret = k_sem_take(&ipc0_bound_sem, K_SECONDS(10));
	if (ret != 0) {
		system_reboot_delayed();
		while (1) {
		}
	}
	ipc_ready = 1;
	G1_LOG_WRN("ipc_service[HOST] has ready!\n\n");

	return ret;
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
			ep->recv_cb(CONTAINER_OF(ctx, struct GlassesState, ipc_ctx),
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
