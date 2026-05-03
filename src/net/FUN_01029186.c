/*
 * Function: FUN_01029186
 * Entry:    01029186
 * Prototype: undefined4 __stdcall FUN_01029186(short * param_1)
 */


undefined4 FUN_01029186(short *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0100cf18(*param_1);
  if (iVar1 == 0) {
    uVar2 = 0x30;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


