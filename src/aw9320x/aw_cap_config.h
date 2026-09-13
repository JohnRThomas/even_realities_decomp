#ifndef _AW_CAP_CONFIG_H_
#define _AW_CAP_CONFIG_H_

/* G1 port (Zephyr): no SPP / OS hooks, debug printing compiled out */
#define AW_DEBUG_PRINTF				(0)
#define AW_DEBUG_PRINTF_DATA			(0)
//#define AW_PRINTF_FLASH_RAM_DATA
//#define AW_UPGRADE_EXCEPTION_RECOVERY

#define AWLOGD(fmt, ...)
#define AWLOGE(fmt, ...)

#endif
