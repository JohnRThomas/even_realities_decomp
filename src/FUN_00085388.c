/*
 * Function: FUN_00085388
 * Entry:    00085388
 * Prototype: undefined4 __stdcall FUN_00085388(int param_1, int param_2, int param_3)
 */


undefined4 FUN_00085388(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = (uint)**(byte **)(param_3 + 0xc);
  if (uVar1 == 0) {
    **(byte **)(param_3 + 0xc) = (byte)(param_2 + 2U);
  }
  else if (uVar1 != param_2 + 2U) {
    *(short *)(param_1 + 0x10) = *(short *)(param_1 + 0x10) + -2;
    *(undefined4 *)(param_3 + 0x10) = 0;
    return 0;
  }
  return 1;
}


