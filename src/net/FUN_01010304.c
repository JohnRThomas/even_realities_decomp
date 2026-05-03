/*
 * Function: FUN_01010304
 * Entry:    01010304
 * Prototype: undefined4 __stdcall FUN_01010304(byte * param_1, int param_2)
 */


undefined4 FUN_01010304(byte *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  int iVar9;
  
  iVar9 = *(int *)(param_1 + 4);
  bVar1 = *param_1;
  uVar7 = FUN_0100dbc0(iVar9 + 0xa8,10,(uint)*(byte *)(iVar9 + 0xc5),(uint)bVar1);
  if (uVar7 == 0) {
    return 1;
  }
  bVar2 = FUN_0100efe0(param_2);
  if (bVar2) {
    uVar3 = FUN_0100efd8(param_2);
    uVar4 = FUN_0100efd0(param_2);
    uVar5 = FUN_0100efdc(param_2);
    uVar6 = FUN_0100efd4(param_2);
    FUN_0100f998(iVar9 + 0x30,uVar3,uVar4,uVar5,uVar6);
    FUN_0100f9f8(iVar9);
    if (bVar1 == 0) {
      FUN_0101c5d4(*(undefined4 **)(param_1 + 4),4,extraout_r2,extraout_r3);
    }
    else {
      FUN_01014698(*(undefined4 **)(param_1 + 4),5,extraout_r2,extraout_r3);
    }
  }
  *(undefined1 *)(iVar9 + 0xc5) = 0;
  puVar8 = *(undefined2 **)(param_1 + 4);
  *(undefined1 *)(iVar9 + 0x100) = 0;
  if (*(char *)(puVar8 + 0x32) == '\x01') {
    *(undefined1 *)(puVar8 + 0x32) = 2;
    return 0;
  }
  FUN_0100fb00(*puVar8,(int)(puVar8 + 0x18),(undefined4 *)(puVar8 + 0xe7));
  return 0;
}


