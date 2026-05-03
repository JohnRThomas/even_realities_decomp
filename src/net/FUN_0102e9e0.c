/*
 * Function: FUN_0102e9e0
 * Entry:    0102e9e0
 * Prototype: undefined4 __stdcall FUN_0102e9e0(undefined4 param_1, uint param_2)
 */


undefined4 FUN_0102e9e0(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x20) {
    uVar1 = *(undefined4 *)(&DAT_0103bfac + param_2 * 8);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


