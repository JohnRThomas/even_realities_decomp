/*
 * Function: FUN_0100ffb0
 * Entry:    0100ffb0
 * Prototype: undefined __stdcall FUN_0100ffb0(int param_1)
 */


void FUN_0100ffb0(int param_1)

{
  char cVar1;
  undefined1 extraout_r1;
  undefined1 extraout_r2;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  cVar1 = *(char *)(iVar2 + 0x104) + -1;
  *(char *)(iVar2 + 0x104) = cVar1;
  if (-1 < cVar1) {
    return;
  }
  iVar2 = FUN_01009500(0x4a,0x35,iVar2 + 0xa8,(int)cVar1);
  iVar2 = *(int *)(iVar2 + 4);
  *(undefined1 *)(iVar2 + 0x14b) = extraout_r1;
  *(undefined1 *)(iVar2 + 0x14a) = extraout_r2;
  return;
}


