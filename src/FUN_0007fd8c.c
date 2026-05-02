/*
 * Function: FUN_0007fd8c
 * Entry:    0007fd8c
 * Prototype: undefined __stdcall FUN_0007fd8c(st25dv_context * param_1, undefined1 * param_2)
 */


void FUN_0007fd8c(st25dv_context *param_1,undefined1 *param_2)

{
  uint uVar1;
  undefined4 uStack_c;
  
  *param_2 = 0;
  uStack_c = param_2;
  uVar1 = __eeprom_st25dv_read(param_1,0x2004,(int)&uStack_c + 3,1);
  if (uVar1 == 0) {
    if (uStack_c._3_1_ == '\0') {
      *param_2 = 0;
    }
    else {
      *param_2 = 1;
    }
  }
  return;
}


