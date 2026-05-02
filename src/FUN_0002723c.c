/*
 * Function: FUN_0002723c
 * Entry:    0002723c
 * Prototype: undefined4 __stdcall FUN_0002723c(byte * param_1, byte * param_2)
 */


undefined4 FUN_0002723c(byte *param_1,byte *param_2)

{
  int iVar1;
  
  if (((param_1 != (byte *)0x0) && (*param_1 == 7)) && (param_2 != (byte *)0x0)) {
    FUN_0007f81e(param_2);
    FUN_0007f798(param_2,1,(int *)&DAT_200023c4);
    iVar1 = FUN_0007f986(param_2,param_1);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return 7;
}


