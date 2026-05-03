/*
 * Function: FUN_010398f8
 * Entry:    010398f8
 * Prototype: undefined __stdcall FUN_010398f8(undefined1 * param_1, uint param_2, byte * param_3, uint param_4)
 */


void FUN_010398f8(undefined1 *param_1,uint param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_34 [2];
  undefined1 local_32;
  undefined1 *local_30;
  undefined1 *local_24;
  undefined1 *local_20;
  uint uStack_4;
  
  uStack_4 = param_4;
  FUN_0103bdee(auStack_34,0,0x1c);
  local_32 = 2;
  local_30 = &LAB_0103bdfe_1;
  iVar2 = 0;
  if (param_2 != 0) {
    uVar1 = param_2;
    if (0x7fffffff < param_2) {
      uVar1 = 0x80000000;
    }
    iVar2 = uVar1 - 1;
  }
  local_20 = param_1 + iVar2;
  local_24 = param_1;
  FUN_01039950((int)auStack_34,param_3,&uStack_4);
  if (param_2 != 0) {
    *local_24 = 0;
  }
  return;
}


