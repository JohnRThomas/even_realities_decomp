/*
 * Function: wdt_npm1300_disable
 * Entry:    00088444
 * Prototype: int __stdcall wdt_npm1300_disable(device * param_1)
 */


/* exclude_from_export */

int wdt_npm1300_disable(device *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = param_1->data;
  iVar1 = i2c_write_dt(*(i2c_dt_spec **)param_1->config,&DAT_00000007,1);
  if (-1 < iVar1) {
    iVar1 = 0;
    *puVar2 = 0;
  }
  return iVar1;
}


