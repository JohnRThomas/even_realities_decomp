/*
 * Function: FUN_0008ac9c
 * Entry:    0008ac9c
 * Prototype: undefined4 __stdcall FUN_0008ac9c(undefined4 param_1, uint * param_2, byte * param_3, int param_4)
 */


undefined4 FUN_0008ac9c(undefined4 param_1,uint *param_2,byte *param_3,int param_4)

{
  undefined4 uVar1;
  uint local_4;
  
  if (param_2 == (uint *)0x0) {
    param_2 = &local_4;
  }
  if (param_3 == (byte *)0x0) {
    uVar1 = 0;
  }
  else if (param_4 == 0) {
    uVar1 = 0xfffffffe;
  }
  else {
    *param_2 = (uint)*param_3;
    uVar1 = 0;
    if (*param_3 != 0) {
      uVar1 = 1;
    }
  }
  return uVar1;
}


