/*
 * Function: FUN_000827b8
 * Entry:    000827b8
 * Prototype: undefined4 __stdcall FUN_000827b8(uint * param_1, int param_2)
 */


undefined4 FUN_000827b8(uint *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 4);
  uVar3 = *param_1;
  if (uVar3 < uVar4) {
LAB_000827c2:
    uVar1 = 1;
  }
  else {
    if (uVar3 < *(int *)(param_2 + 8) + uVar4) {
      iVar2 = *(int *)(param_2 + 0xc);
      if (*(uint *)(param_2 + 0x10) < *(uint *)(param_2 + 0x14)) {
        *(uint *)(iVar2 + *(uint *)(param_2 + 0x10) * 8) = uVar3 - uVar4;
        *(uint *)(iVar2 + *(int *)(param_2 + 0x10) * 8 + 4) = param_1[1];
        *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + 1;
        goto LAB_000827c2;
      }
      *(undefined4 *)(param_2 + 0x18) = 0xfffffff4;
    }
    uVar1 = 0;
  }
  return uVar1;
}


