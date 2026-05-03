/*
 * Function: FUN_0007fcd0
 * Entry:    0007fcd0
 * Prototype: int __stdcall FUN_0007fcd0(st25dv_context * param_1, uint param_2, undefined4 param_3)
 */


int FUN_0007fcd0(st25dv_context *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_14;
  undefined4 uStack_10;
  
  local_14 = param_2 & 0xffff0000;
  if (param_2 == 0) {
    iVar1 = -0x16;
  }
  else {
    uStack_10 = param_3;
    iVar1 = __eeprom_st25dv_read_sys(param_1,0x14,&local_14,2);
    if (iVar1 == 0) {
      *(undefined2 *)(param_2 + 2) = (undefined2)local_14;
      iVar1 = __eeprom_st25dv_read_sys(param_1,0x16,param_2,1);
    }
  }
  return iVar1;
}


