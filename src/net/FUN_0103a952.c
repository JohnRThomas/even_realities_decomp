/*
 * Function: FUN_0103a952
 * Entry:    0103a952
 * Prototype: undefined4 __stdcall FUN_0103a952(int param_1, int param_2)
 */


undefined4 FUN_0103a952(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    FUN_0103b88c((int *)(param_1 + 0xe0),param_2);
    if (param_2 == 0) {
      *(undefined4 *)(param_1 + 0x19c) = 0;
      *(undefined4 *)(param_1 + 0x1a0) = 0;
      *(undefined4 *)(param_1 + 0x1a4) = 0;
    }
    uVar1 = 0;
  }
  return uVar1;
}


