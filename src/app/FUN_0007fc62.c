/*
 * Function: FUN_0007fc62
 * Entry:    0007fc62
 * Prototype: undefined __stdcall FUN_0007fc62(st25dv_context * param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0007fc62(st25dv_context *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  iVar1 = __eeprom_st25dv_read_sys(param_1,1,(int)&uStack_14 + 3,1);
  if (iVar1 == 0) {
    uStack_14 = CONCAT13(uStack_14._3_1_ & 0xe0 | (byte)param_2 & 0x1f,(undefined3)uStack_14);
    __eeprom_st25dv_write_sys((int)param_1,1,(void *)((int)&uStack_14 + 3),1);
  }
  return;
}


