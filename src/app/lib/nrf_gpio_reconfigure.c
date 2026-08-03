/*
 * Function: nrf_gpio_reconfigure
 * Entry:    000888e0
 * Prototype: void __stdcall nrf_gpio_reconfigure(uint32_t pin_number, nrf_gpio_pin_dir_t * p_dir, nrf_gpio_pin_input_t * p_input, nrf_gpio_pin_pull_t * p_pull, nrf_gpio_pin_drive_t * p_drive, nrf_gpio_pin_sense_t * p_sense)
 */


/* exclude_from_export */

void nrf_gpio_reconfigure
               (uint32_t pin_number,nrf_gpio_pin_dir_t *p_dir,nrf_gpio_pin_input_t *p_input,
               nrf_gpio_pin_pull_t *p_pull,nrf_gpio_pin_drive_t *p_drive,
               nrf_gpio_pin_sense_t *p_sense)

{
  NRF_GPIO_Type *pNVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint32_t local_1c;
  
  local_1c = pin_number;
  pNVar1 = nrf_gpio_pin_port_decode(&local_1c);
  if (p_pull == (nrf_gpio_pin_pull_t *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc;
  }
  if (p_drive == (nrf_gpio_pin_drive_t *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xf00;
  }
  if (p_sense == (nrf_gpio_pin_sense_t *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x30000;
  }
  uVar6 = 0;
  if (p_dir != (nrf_gpio_pin_dir_t *)0x0) {
    uVar6 = (uint)(byte)*p_dir;
  }
  uVar8 = 0;
  if (p_input != (nrf_gpio_pin_input_t *)0x0) {
    uVar8 = (uint)(byte)*p_input << 1;
  }
  uVar7 = 0;
  if (p_pull != (nrf_gpio_pin_pull_t *)0x0) {
    uVar7 = (uint)(byte)*p_pull << 2;
  }
  if (p_drive == (nrf_gpio_pin_drive_t *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)(byte)*p_drive << 8;
  }
  uVar9 = 0;
  if (p_sense != (nrf_gpio_pin_sense_t *)0x0) {
    uVar9 = (uint)(byte)*p_sense << 0x10;
  }
  pNVar1[local_1c + 0x80] =
       uVar5 | uVar6 | pNVar1[local_1c + 0x80] &
                       ~((uint)(p_dir != (nrf_gpio_pin_dir_t *)0x0) |
                         (uint)(p_input != (nrf_gpio_pin_input_t *)0x0) << 1 | uVar2 | uVar3 | uVar4
                        ) | uVar8 | uVar7 | uVar9;
  return;
}


