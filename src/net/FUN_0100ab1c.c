/*
 * Function: FUN_0100ab1c
 * Entry:    0100ab1c
 * Prototype: undefined __stdcall FUN_0100ab1c(int param_1, char param_2)
 */


void FUN_0100ab1c(int param_1,char param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  undefined4 local_10;
  undefined4 local_c;
  
  iVar3 = *(int *)(param_1 + 4);
  if (param_2 == '\0') {
    *(undefined1 *)(param_1 + 1) = 0;
    for (local_10 = 0; local_10 < 4; local_10 = local_10 + 1) {
      *(undefined2 *)(param_1 + (local_10 + 0xc) * 2) = 0;
      *(undefined2 *)(param_1 + (local_10 + 0x10) * 2) = 0;
      *(undefined4 *)(local_10 * 4 + param_1 + 4) = 0;
      *(undefined1 *)(local_10 + param_1 + 0x14) = 0;
    }
    uVar1 = FUN_0102830c(DAT_21000bc0);
    uVar2 = FUN_01028332(DAT_21000bc0);
    *(int *)(param_1 + 4) = iVar3;
    *(ushort *)(param_1 + 0x20) = uVar2;
    *(uint *)(param_1 + 8) = iVar3 + (uint)uVar2;
    *(ushort *)(param_1 + 0x22) = uVar1;
    *(int *)(param_1 + 0xc) = iVar3;
    *(ushort *)(param_1 + 0x24) = uVar2;
    *(uint *)(param_1 + 0x10) = iVar3 + (uint)uVar2;
    *(ushort *)(param_1 + 0x26) = uVar1;
  }
  else {
    *(undefined1 *)(param_1 + 1) = 1;
    uVar1 = FUN_010282f2(DAT_21000bc0);
    for (local_c = 0; local_c < 4; local_c = local_c + 1) {
      *(undefined2 *)(param_1 + (local_c + 0xc) * 2) = 0;
      *(ushort *)(param_1 + (local_c + 0x10) * 2) = uVar1;
      *(uint *)(local_c * 4 + param_1 + 4) = iVar3 + local_c * uVar1;
      *(undefined1 *)(local_c + param_1 + 0x14) = 0;
    }
  }
  return;
}


