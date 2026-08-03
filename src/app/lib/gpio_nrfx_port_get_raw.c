/*
 * Function: gpio_nrfx_port_get_raw
 * Entry:    00087356
 * Prototype: int __stdcall gpio_nrfx_port_get_raw(size_t param_1, uint * param_2)
 */


/* exclude_from_export_ai */

int gpio_nrfx_port_get_raw(size_t param_1,uint *param_2)

{
  int iVar1;
  undefined4 uStack_c;
  
  uStack_c = param_2;
  iVar1 = i2c_write_read_dt(*(i2c_dt_spec **)(*(int *)(param_1 + 4) + 4),&DAT_00000006,0x1e,
                            (void *)((int)&uStack_c + 3),param_1);
  if (-1 < iVar1) {
    iVar1 = 0;
    *param_2 = (uint)uStack_c >> 0x18;
  }
  return iVar1;
}


