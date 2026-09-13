/*
 * lsm6dso_init() for a stock zephyr tree.
 *
 * The vendor's zephyr tree exports the driver's lsm6dso_init() and gives the device
 * no init function of its own: main.c calls it once the sensor is powered
 * (power_for_imu_and_mic()).  Stock zephyr keeps the function static and runs it at
 * boot, before the sensor has power.  This weak stand-in, which the vendor tree's
 * definition replaces, runs the device's init function again.
 */
#include <errno.h>
#include <zephyr/init.h>
#include <zephyr/toolchain.h>

#include <vendor_drivers.h>

extern const struct init_entry __init_start[];
extern const struct init_entry __init_end[];

__weak int lsm6dso_init(const struct device *dev)
{
	for (const struct init_entry *entry = __init_start; entry < __init_end; entry++) {
		if (entry->dev == dev) {
			return entry->init_fn.dev(dev);
		}
	}
	return -ENODEV;
}
