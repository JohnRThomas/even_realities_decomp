#ifndef _AW_CAP_CONFIG_H_
#define _AW_CAP_CONFIG_H_

#define AW_STM32H7_P				(0)
#define AW_BES2500_P				(1)
#define AW_DEBUG_PRINTF				(1)
#define AW_DEBUG_PRINTF_DATA 		(1)
//#define AW_PRINTF_FLASH_RAM_DATA 
//#define AW_UPGRADE_EXCEPTION_RECOVERY

#if (defined(AW_BES2500_P) && (AW_BES2500_P == 1))
#include <hal_trace.h>
#define AW_SPP_USED
#define AW_OS_USED
#if (defined(AW_DEBUG_PRINTF) && (AW_DEBUG_PRINTF == 1))
#define AWLOGD(fmt, ...)     TRACE(5, "[%s:%d] DBG: "fmt" \n", __func__, __LINE__, ##__VA_ARGS__)
#define AWLOGE(fmt, ...)     TRACE(5, "[%s:%d] ERR: "fmt" \n", __func__, __LINE__, ##__VA_ARGS__)
#endif
#endif



#if (defined(AW_STM32H7_P) && (AW_STM32H7_P == 1))
#if (defined(AW_DEBUG_PRINTF) && (AW_DEBUG_PRINTF == 1))
#define AWLOGD(fmt, ...)     printf("[%s:%d] DBG: "fmt" \r\n", __func__, __LINE__, ##__VA_ARGS__)
#define AWLOGE(fmt, ...)     printf("[%s:%d] ERR: "fmt" \r\n", __func__, __LINE__, ##__VA_ARGS__)
#endif
#endif

#endif
