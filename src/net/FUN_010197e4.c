/*
 * Function: FUN_010197e4
 * Entry:    010197e4
 * Prototype: undefined4 __stdcall FUN_010197e4(undefined1 param_1, uint param_2, byte * param_3, undefined1 param_4)
 */


undefined4 FUN_010197e4(undefined1 param_1,uint param_2,byte *param_3,undefined1 param_4)

{
  undefined4 uVar1;
  undefined1 in_r12;
  char in_ZR;
  
  DAT_21000fdd = in_r12;
  DAT_21000fe6 = param_1;
  DAT_2100100b = param_4;
  if (in_ZR != '\0') {
    uVar1 = FUN_0100cf44((uint)((param_2 & 0xfd) != 0),param_3);
    DAT_2100100b = (undefined1)uVar1;
  }
  return 0;
}


