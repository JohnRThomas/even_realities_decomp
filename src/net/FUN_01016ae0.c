/*
 * Function: FUN_01016ae0
 * Entry:    01016ae0
 * Prototype: undefined __stdcall FUN_01016ae0(int param_1)
 */


void FUN_01016ae0(int param_1)

{
  undefined2 uVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  
  pbVar6 = DAT_21001050;
  pbVar6[0] = 0;
  pbVar6[1] = 0;
  if (param_1 == 3) {
    FUN_0100e7bc(pbVar6,3);
    pbVar6 = DAT_21001050;
  }
  else if (param_1 == 5) {
    FUN_0100e7bc(pbVar6,5);
    pbVar6 = DAT_21001050;
    *(undefined4 *)(DAT_21001050 + 0xf) = *(undefined4 *)(DAT_21000fe0 + 0x18);
    iVar3 = DAT_21000fe0;
    uVar9 = *(undefined4 *)(DAT_21000fe0 + 0x20);
    pbVar6[0x13] = (byte)uVar9;
    pbVar6[0x14] = (byte)((uint)uVar9 >> 8);
    pbVar6[0x15] = (byte)((uint)uVar9 >> 0x10);
    uVar8 = FUN_0100de4c((uint)*(ushort *)(iVar3 + 0x28),*(undefined **)(iVar3 + 0x14));
    pbVar6[0x16] = (byte)uVar8;
    pbVar6 = DAT_21001050;
    uVar8 = FUN_0100de88(*(uint *)(DAT_21000fe0 + 0x24),*(undefined **)(DAT_21000fe0 + 0x14));
    pbVar6[0x17] = (byte)uVar8;
    pbVar4 = DAT_21001050;
    pbVar6[0x18] = (byte)(uVar8 >> 8);
    uVar8 = FUN_0100ddd0(*(uint *)(DAT_21000fe0 + 0x14));
    pbVar4[0x19] = (byte)uVar8;
    pbVar4[0x1a] = (byte)(uVar8 >> 8);
    pbVar4 = DAT_21001050;
    iVar3 = DAT_21000fe0;
    uVar1 = *(undefined2 *)(DAT_21000fe0 + 0x1c);
    DAT_21001050[0x1b] = (byte)uVar1;
    pbVar4[0x1c] = (byte)((ushort)uVar1 >> 8);
    uVar1 = *(undefined2 *)(iVar3 + 0x1e);
    pbVar4[0x1d] = (byte)uVar1;
    pbVar4[0x1e] = (byte)((ushort)uVar1 >> 8);
    *(undefined4 *)(pbVar4 + 0x1f) = *(undefined4 *)(iVar3 + 0xce);
    pbVar4[0x23] = *(byte *)(iVar3 + 0xd2);
    pbVar4[0x24] = *(byte *)(DAT_21000fe0 + 0xd9) & 0x1f | pbVar4[0x24] & 0xe0;
    bVar5 = FUN_01020124();
    pbVar6 = DAT_21001050;
    pbVar4[0x24] = pbVar4[0x24] & 0x1f | bVar5 << 5;
  }
  FUN_0100e828((int)pbVar6,&DAT_21001019);
  FUN_0100e854(DAT_21001050,DAT_21001020);
  bVar5 = DAT_21000fd5;
  if (DAT_2100100d != '\0') {
    if ((DAT_21000fe4 != '\x03') || (bVar2 = DAT_2100100b, DAT_21000fdd == '\0')) {
      bVar2 = DAT_21001008;
    }
    puVar7 = (undefined4 *)FUN_0100d3bc((uint)bVar2);
    if (puVar7 != (undefined4 *)0x0) {
      bVar5 = 1;
      goto LAB_01016b2c;
    }
  }
  puVar7 = &DAT_21000fd6;
LAB_01016b2c:
  FUN_0100e808((int)DAT_21001050,puVar7);
  FUN_0100e838(DAT_21001050,bVar5);
  FUN_01020f64((uint)DAT_21001050);
  iVar3 = DAT_21000fe0;
  if (param_1 == 5) {
    *(undefined4 *)(DAT_21000fe0 + 10) = *puVar7;
    *(undefined2 *)(iVar3 + 0xe) = *(undefined2 *)(puVar7 + 1);
    *(byte *)(DAT_21000fe0 + 9) = bVar5;
    return;
  }
  return;
}


