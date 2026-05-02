/*
 * Function: FUN_0007fb98
 * Entry:    0007fb98
 * Prototype: undefined4 __stdcall FUN_0007fb98(int * param_1)
 */


undefined4 FUN_0007fb98(int *param_1)

{
  uint uVar1;
  
  uVar1 = adc_nfc_run();
  *param_1 = uVar1 * 10;
  return 1;
}


