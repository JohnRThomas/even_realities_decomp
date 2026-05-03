/*
 * Function: FUN_010131b8
 * Entry:    010131b8
 * Prototype: undefined __stdcall FUN_010131b8(undefined1 * param_1, int param_2, int param_3)
 */


void FUN_010131b8(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = (uint)(byte)param_1[2];
  *param_1 = (char)param_2;
  param_1[1] = (char)param_3;
  iVar2 = (-((int)(uVar3 << 0x1e) >> 0x1f) - ((int)(uVar3 << 0x1d) >> 0x1f)) + (uVar3 & 1);
  iVar1 = iVar2 * param_2 * param_3;
  if (iVar1 < 0xff) {
    return;
  }
  iVar1 = FUN_01009500(0x2e,0x5c,iVar1,iVar2);
  *(undefined1 *)(iVar1 + 5) = 0;
  *(undefined2 *)(iVar1 + 3) = 0;
  return;
}


