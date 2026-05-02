/*
 * Function: FUN_0008a2f0
 * Entry:    0008a2f0
 * Prototype: uint __stdcall FUN_0008a2f0(int param_1, undefined * param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_0008a2f0(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  piVar2 = (int *)(param_1 + 0x48);
  uVar4 = 0;
  do {
    iVar5 = piVar2[1];
    iVar3 = piVar2[2];
    while (iVar5 = iVar5 + -1, -1 < iVar5) {
      if ((1 < *(ushort *)(iVar3 + 0xc)) && (*(short *)(iVar3 + 0xe) != -1)) {
        uVar1 = (*(code *)param_2)(param_1,iVar3);
        uVar4 = uVar4 | uVar1;
      }
      iVar3 = iVar3 + 0x68;
    }
    piVar2 = (int *)*piVar2;
  } while (piVar2 != (int *)0x0);
  return uVar4;
}


