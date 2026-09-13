/*
 * ipc.c - "ipc0" IPC service endpoint shared by several logical endpoints.
 * The first byte of every message selects the logical endpoint (struct ipc_ep).
 */
#include <errno.h>
#include <zephyr/device.h>
#include <zephyr/ipc/ipc_service.h>

#include "net_common.h"

static struct ipc_ops *g_ops;
static int ipc_ready;
static struct ipc_ept ipc_ept;

static K_SEM_DEFINE(ept_bound_sem, 0, 1);

static void ipc_ept_recv(const void *data, size_t len, void *priv)
{
	const uint8_t *p = data;
	uint8_t id = p[0];
	struct ipc_ops *ops = g_ops;

	for (int i = 0; i < ops->count; i++) {
		struct ipc_ep *ep = ops->eps[i];

		if (ep != NULL && ep->id == id) {
			ep->cb(CONTAINER_OF(ops, struct net_ctx, ipc), p + 1, len - 1);
			return;
		}
	}
}

static int ipc_register(struct ipc_ep *ep)
{
	struct ipc_ops *ops = g_ops;

	if (ops->count < IPC_EP_MAX) {
		ops->eps[ops->count] = ep;
		ops->count++;
		NET_INF("ipc service register(%d,%s) %d,SUCCESS\n", ep->id, ep->name, ops->count);
		return 0;
	}
	NET_ERR("ipc service register(%d,%s) %d,total must < %d\n", ep->id, ep->name,
		ops->count, IPC_EP_MAX);
	return -1;
}

static int ipc_send(const void *data, size_t len)
{
	int ret;

	if (ipc_ready == 1) {
		ret = ipc_service_send(&ipc_ept, data, len);
		if (ret < 0) {
			NET_ERR("send data failed %d\n", ret);
		}
		return ret;
	}
	NET_ERR("ipc service not ready!\n");
	return -1;
}

static void ipc_ept_bound(void *priv)
{
	k_sem_give(&ept_bound_sem);
}

static struct ipc_ept_cfg ipc_ept_cfg = {
	.name = "ipc0",
	.cb = {
		.bound    = ipc_ept_bound,
		.received = ipc_ept_recv,
	},
};

int ipc_init(void)
{
	const struct device *ipc_instance = DEVICE_DT_GET(DT_NODELABEL(ipc0));
	int err;

	err = ipc_service_open_instance(ipc_instance);
	if (err < 0 && err != -EALREADY) {
		NET_ERR("ipc service open fail\n");
		return -1;
	}

	err = ipc_service_register_endpoint(ipc_instance, &ipc_ept, &ipc_ept_cfg);
	if (err < 0) {
		NET_ERR("ipc service register endpoint failed\n");
		return -1;
	}

	k_sem_take(&ept_bound_sem, K_FOREVER);
	ipc_ready = 1;
	NET_INF("ipc service ready!\n\n");
	return 0;
}

int ipc_ops_init(struct ipc_ops *ops)
{
	ops->send = ipc_send;
	ops->reg = ipc_register;
	g_ops = ops;
	NET_INF("exit\n\n");
	return 0;
}
