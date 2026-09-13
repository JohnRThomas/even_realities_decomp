/*
 * ST25DV dynamic NFC tag (I2C EEPROM + mailbox) on the G1.
 *
 * The vendor wrapped the tag in a hand-built Zephyr "eeprom" device
 * (struct device in RAM, eeprom_driver_api {read, write, size}); the
 * register helpers below follow ST's st25dv.c, rewritten on that device.
 */
#ifndef G1_ST25DV_H_
#define G1_ST25DV_H_

#include <stdint.h>
#include <stddef.h>
#include <sys/types.h>
#include <zephyr/device.h>

/* I2C addresses: user memory / dynamic registers at 0x53, system area at 0x57 */
#define ST25DV_ADDR_DATA_I2C	0x53
#define ST25DV_ADDR_SYST_I2C_BIT 0x04

/* system configuration area (E2 = 1) */
#define ST25DV_GPO_REG		0x0000
#define ST25DV_ITTIME_REG	0x0001
#define ST25DV_RFA1SS_REG	0x0004
#define ST25DV_RFA3SS_REG	0x0008
#define ST25DV_MEM_SIZE_REG	0x0014
#define ST25DV_BLK_SIZE_REG	0x0016
#define ST25DV_ICREF_REG	0x0017
#define ST25DV_UID_REG		0x0018
#define ST25DV_ICREV_REG	0x0020
#define ST25DV_I2CPASSWD_REG	0x0900

/* dynamic registers (E2 = 0) */
#define ST25DV_EH_CTRL_DYN_REG	0x2002
#define ST25DV_I2C_SSO_DYN_REG	0x2004
#define ST25DV_ITSTS_DYN_REG	0x2005
#define ST25DV_MB_CTRL_DYN_REG	0x2006
#define ST25DV_MB_LEN_DYN_REG	0x2007
#define ST25DV_MAILBOX_RAM_REG	0x2008

struct eeprom_st25dv_config {
	const struct device *bus;	/* i2c@9000 */
	uint16_t bus_addr;		/* 0x53 */
	uint16_t pad_06;
	uint16_t addr;			/* 0x53 */
	uint16_t pad_0a;
	size_t size;			/* 0x1000 */
};

struct st25dv_passwd {
	uint32_t msb;
	uint32_t lsb;
};

struct st25dv_mem_size {
	uint8_t blk_size;
	uint8_t pad_01;
	uint16_t mem_size;
};

/* the eeprom device and a pointer to it (set by nfc_init()) */
extern struct device global_st25dv_context;
extern const struct device *global_st25dv_context_ptr;

int init_nfc_comm(void);
int FUN_00027848(uint8_t *it_status);
int eeprom_st25dv_read(const struct device *dev, off_t offset, void *buf, size_t len);
int eeprom_st25dv_write(const struct device *dev, off_t offset, const void *buf, size_t len);
int eeprom_st25dv_read_sys(const struct device *dev, off_t offset, void *buf, size_t len);
int eeprom_st25dv_write_sys(const struct device *dev, off_t offset, const void *buf, size_t len);
int FUN_00027ac0(const struct device *dev, uint8_t **buf, uint32_t *len);
int eeprom_st25dv_write_i2c_mb_mailbox_ram(const struct device *dev, const void *buf, size_t len);
const struct device *eeprom_st25dv_init(void);
uint8_t FUN_0007fc18(const struct device *dev);	/* no return value (vendor) */
uint8_t FUN_0007fc2c(const struct device *dev);	/* no return value (vendor) */

/* st25dv.c */
int st25dv_configure_gpo(const struct device *dev, uint8_t it_conf);
int st25dv_read_it_pulse(const struct device *dev, uint8_t *it_time);
int st25dv_write_it_pulse(const struct device *dev, uint8_t it_time);
int ST25DV_GetUID(const struct device *dev, uint8_t *uid);
int st25dv_read_ic_rev(const struct device *dev, uint8_t *ic_rev);
int st25dv_read_id(const struct device *dev, uint8_t *ic_ref);
int st25dv_read_mem_size(const struct device *dev, struct st25dv_mem_size *size);
int st25dv_present_i2c_password(const struct device *dev, const struct st25dv_passwd *pwd);
int st25dv_read_eh_ctrl_dyn(const struct device *dev, uint8_t *eh_ctrl);
int st25dv_write_eh_ctrl_dyn(const struct device *dev, uint8_t eh_ctrl);
int st25dv_read_itsts_dyn(const struct device *dev, uint8_t *it_status);
int st25dv_read_i2c_security_session_dyn(const struct device *dev, uint8_t *session);

#endif /* G1_ST25DV_H_ */
