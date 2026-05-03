/*
 * Function: FUN_0100f900
 * Entry:    0100f900
 * Prototype: undefined2 __stdcall FUN_0100f900(int param_1, uint param_2)
 */


undefined2 FUN_0100f900(int param_1,uint param_2)

{
  undefined2 uVar1;
  
  if ((param_2 & 0xc) == 0) {
    uVar1 = *(undefined2 *)(param_1 + 0x12);
  }
  else {
    uVar1 = 0xa90;
  }
  return uVar1;
}


