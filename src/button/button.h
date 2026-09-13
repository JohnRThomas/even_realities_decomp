/* GPIO lines, touch/NFC interrupt buttons and the hardware-id straps (button.c) */
#ifndef G1_BUTTON_H_
#define G1_BUTTON_H_

#include <stdint.h>
#include <zephyr/kernel.h>
#include <glasses_state.h>

/* button.c */
extern int touch_irq_pending; /* AW9320x irq pending */
int panel_gpio_disable(void);
int panel_gpio_enable(void);
int nfc_lpd_on(void);
int nfc_lpd_off(void);
int touch_power_on(void);
int touch_power_off(void);
int reset_pmic_on(void);
int reset_pmic_off(void);
uint8_t button_init(void);
int get_sw0_irq_level(void);

#endif /* G1_BUTTON_H_ */
