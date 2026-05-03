/*
 * Function: FUN_0101e50c
 * Entry:    0101e50c
 * Prototype: undefined __stdcall FUN_0101e50c(int param_1)
 */


void FUN_0101e50c(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 0x1c);
  if (iVar3 == 0) {
    iVar2 = *(int *)(param_1 + 0x18);
    DAT_2100113c = iVar2;
    if (iVar2 == 0) goto LAB_0101e528;
  }
  else {
    iVar1 = *(int *)(param_1 + 8);
    iVar4 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(param_1 + 0x18);
    iVar2 = *(int *)(param_1 + 0x18);
    *(int *)(iVar3 + 0xc) = iVar1 + iVar4 + *(int *)(iVar3 + 0xc);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar3 + 0xc) = 0;
      goto LAB_0101e528;
    }
  }
  *(int *)(iVar2 + 0x1c) = iVar3;
LAB_0101e528:
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


