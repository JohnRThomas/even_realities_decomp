/*
 * Function: FUN_01032b8c
 * Entry:    01032b8c
 * Prototype: undefined4 __stdcall FUN_01032b8c(byte * param_1, undefined1 * param_2, int * param_3)
 */


undefined4 FUN_01032b8c(byte *param_1,undefined1 *param_2,int *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (DAT_210051ae == '\0') {
    if ((param_1 == (byte *)0x0) || (param_2 == (undefined1 *)0x0)) {
      uVar2 = 0xffffffea;
    }
    else {
      uVar1 = FUN_01009a24(param_1,param_2,param_3);
      if (uVar1 == 0) {
        uVar2 = 0xffffffdd;
      }
      else {
        *param_2 = (char)uVar1;
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  FUN_0103bdd4((int)param_1,&DAT_210051af,DAT_210051b0 + 2);
  DAT_210051ae = 0;
  *param_2 = 4;
  return 0;
}


