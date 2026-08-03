/*
 * Function: gpio_nrfx_port_set_masked_raw
 * Entry:    00087312
 * Prototype: int __stdcall gpio_nrfx_port_set_masked_raw(int param_1, uint param_2)
 */


/* exclude_from_export_ai */

int gpio_nrfx_port_set_masked_raw(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  iVar3 = *(int *)(param_1 + 4);
  while ((-1 < (int)((param_2 >> (uVar2 & 0xff)) << 0x1f) ||
         (iVar1 = i2c_write_dt(*(i2c_dt_spec **)(iVar3 + 4),&DAT_00000006,uVar2 & 0xff), iVar1 == 0)
         )) {
    uVar2 = uVar2 + 1;
    if (uVar2 == 5) {
      return 0;
    }
  }
  return iVar1;
}


