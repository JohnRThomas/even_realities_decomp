/*
 * Function: FUN_010101fc
 * Entry:    010101fc
 * Prototype: undefined4 __stdcall FUN_010101fc(int param_1, int param_2)
 */


undefined4 FUN_010101fc(int param_1,int param_2)

{
  short sVar1;
  bool bVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  undefined *puVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  
  uVar5 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc6),
                       1);
  if (uVar5 == 0) {
    return 1;
  }
  bVar2 = FUN_0100ee9c(param_2,(uint)*(byte *)(*(int *)(param_1 + 4) + 0x73));
  if (bVar2) {
    iVar8 = *(int *)(param_1 + 4);
    sVar1 = *(short *)(param_2 + 0xd);
    *(short *)(iVar8 + 0x3bc) = sVar1;
    if (0x7ffd < (ushort)(sVar1 + ~*(ushort *)(iVar8 + 0xbc))) {
      *(undefined1 *)(iVar8 + 0xe5) = 0x28;
      FUN_0100f788((undefined4 *)(iVar8 + 0xdc),&BYTE_010100a1,2);
      return 0;
    }
    uVar3 = FUN_0100ee7c(param_2);
    puVar6 = (undefined *)FUN_0100de00((uint)uVar3);
    iVar8 = *(int *)(param_1 + 4);
    *(undefined **)(iVar8 + 0x3c4) = puVar6;
    uVar5 = FUN_0100de24((uint)*(byte *)(param_2 + 4),puVar6);
    *(short *)(iVar8 + 0x3be) = (short)uVar5;
    iVar10 = *(int *)(param_1 + 4);
    iVar8 = FUN_0100de74((uint)*(ushort *)(param_2 + 5),puVar6);
    iVar9 = *(int *)(param_1 + 4);
    *(int *)(iVar10 + 0x3c0) = iVar8;
    uVar4 = FUN_0100ee84(param_2);
    *(undefined2 *)(iVar9 + 0x3c8) = uVar4;
    iVar9 = *(int *)(param_1 + 4);
    uVar4 = FUN_0100ee94(param_2);
    iVar8 = *(int *)(param_1 + 4);
    *(undefined2 *)(iVar9 + 0x3ca) = uVar4;
    *(undefined1 *)(iVar8 + 0xc6) = 0xe;
    return 0;
  }
  uVar7 = FUN_01010034(param_1,param_2);
  return uVar7;
}


