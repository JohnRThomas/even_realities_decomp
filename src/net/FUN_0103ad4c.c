/*
 * Function: FUN_0103ad4c
 * Entry:    0103ad4c
 * Prototype: undefined4 __stdcall FUN_0103ad4c(int param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0103ad4c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int unaff_r4;
  
  if (param_2 < 0x10) {
    unaff_r4 = *(int *)(param_1 + 0x10) + param_2 * 4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + param_2 * 4) = param_3;
  }
  if (param_2 < 0x10) {
    *(undefined4 *)(unaff_r4 + 0x40) = param_4;
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffea;
  }
  return uVar1;
}


