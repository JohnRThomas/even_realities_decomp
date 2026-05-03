/*
 * Function: FUN_01015250
 * Entry:    01015250
 * Prototype: undefined4 __stdcall FUN_01015250(int param_1, int param_2)
 */


undefined4 FUN_01015250(int param_1,int param_2)

{
  undefined2 *puVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  
  bVar2 = FUN_0100efe0(param_2);
  if (!bVar2) {
    uVar7 = FUN_01010034(param_1,param_2);
    return uVar7;
  }
  iVar9 = *(int *)(param_1 + 4);
  uVar3 = FUN_0100efd8(param_2);
  uVar4 = FUN_0100efd0(param_2);
  uVar5 = FUN_0100efdc(param_2);
  uVar6 = FUN_0100efd4(param_2);
  FUN_0100f998(iVar9 + 0x30,uVar3,uVar4,uVar5,uVar6);
  puVar1 = DAT_21000f6c;
  if (((int)((uint)DAT_21000f74 << 0x1e) < 0) && (*(char *)(DAT_21000f78 + 3) == '\x14')) {
    iVar9 = *(int *)(param_1 + 4);
LAB_010152a8:
    *(undefined1 *)(iVar9 + 100) = 1;
  }
  else {
    iVar9 = *(int *)(param_1 + 4);
    if (*(char *)(iVar9 + 0xc5) == '\x1e') goto LAB_010152a8;
    if (((*(char *)(iVar9 + 100) != '\x01') && (*(char *)(iVar9 + 0x163) == '\0')) &&
       (*(char *)(iVar9 + 0x162) == '\0')) {
      puVar8 = (undefined4 *)(DAT_21000f6c + 0xf1);
      *(uint *)(iVar9 + 0xb4) = *(uint *)(iVar9 + 0xb4) | 0x20;
      FUN_0100fad0(*puVar1,(int)(puVar1 + 0x18),puVar8);
      goto LAB_010152ba;
    }
  }
  *(uint *)(iVar9 + 0xb4) = *(uint *)(iVar9 + 0xb4) | 0x10;
LAB_010152ba:
  FUN_0100ff98(param_1);
  return 0;
}


