/*
 * External QSPI NOR flash (mx25r6435f) access wrappers.
 * Reconstructed from the v1.63 firmware image.
 */
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/flash.h>

#include "g1_log.h"
#include "sensors_audio.h"

#define EXT_FLASH_MODULE_ON BIT(4)

/* power hooks of the flash module (empty in this build) */
extern void FUN_0007f328(void);
extern void FUN_0007f32a(void);

#define EXT_FLASH_POWER_ON(gs)                                 \
	do {                                                   \
		if (!((gs)->module_mask & EXT_FLASH_MODULE_ON)) { \
			FUN_0007f328();                        \
		}                                              \
	} while (0)
#define EXT_FLASH_POWER_OFF(gs)                                \
	do {                                                   \
		if (!((gs)->module_mask & EXT_FLASH_MODULE_ON)) { \
			FUN_0007f32a();                        \
		}                                              \
	} while (0)

static const struct device *ext_flash_dev;   /* 0x20008548 */
static struct k_mutex ext_flash_mutex;       /* 0x20008534 */

/* ext_flash_api_init is defined first: target __func__ order */
int ext_flash_erase(struct GlassesState *gs, off_t offset, size_t size);
int ext_flash_write(struct GlassesState *gs, off_t offset, const void *data, size_t len);
int ext_flash_read(struct GlassesState *gs, off_t offset, void *data, size_t len);

int ext_flash_api_init(ext_flash_read_t *read, ext_flash_write_t *write, ext_flash_erase_t *erase)
{
	const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(mx25r64));

	k_mutex_init(&ext_flash_mutex);
	if (device_is_ready(dev)) {
		*read = ext_flash_read;
		*write = ext_flash_write;
		*erase = ext_flash_erase;
		ext_flash_dev = dev;
		G1_LOG_INF("flash init success!\n");
		get_dashboard_state()->flash_page_count = flash_get_page_count(dev);
		return 0;
	}
	G1_LOG_ERR("FAILURE!\n");
	return -1;
}
int ext_flash_erase(struct GlassesState *gs, off_t offset, size_t size)
{
	int ret = 0;

	EXT_FLASH_POWER_ON(gs);
	if (ext_flash_dev != NULL) {
		k_mutex_lock(&ext_flash_mutex, K_FOREVER);
		ret = flash_erase(ext_flash_dev, offset, size);
		k_mutex_unlock(&ext_flash_mutex);
	}
	EXT_FLASH_POWER_OFF(gs);
	if (ret != 0) {
		G1_LOG_ERR("flash erase fail!\n");
	}
	return ret;
}

int ext_flash_write(struct GlassesState *gs, off_t offset, const void *data, size_t len)
{
	int ret = 0;

	EXT_FLASH_POWER_ON(gs);
	if (ext_flash_dev != NULL) {
		k_mutex_lock(&ext_flash_mutex, K_FOREVER);
		ret = flash_write(ext_flash_dev, offset, data, len);
		k_mutex_unlock(&ext_flash_mutex);
	}
	EXT_FLASH_POWER_OFF(gs);
	if (ret != 0) {
		G1_LOG_ERR("flash write fail!\n");
	}
	return ret;
}

int ext_flash_read(struct GlassesState *gs, off_t offset, void *data, size_t len)
{
	int ret = 0;

	EXT_FLASH_POWER_ON(gs);
	if (ext_flash_dev != NULL) {
		k_mutex_lock(&ext_flash_mutex, K_FOREVER);
		ret = flash_read(ext_flash_dev, offset, data, len);
		k_mutex_unlock(&ext_flash_mutex);
	}
	EXT_FLASH_POWER_OFF(gs);
	if (ret != 0) {
		G1_LOG_ERR("flash read fail!\n");
	}
	return ret;
}
