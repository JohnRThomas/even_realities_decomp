/*
 * Function: FUN_0101a79c
 * Entry:    0101a79c
 * Prototype: undefined __stdcall FUN_0101a79c(byte * param_1, byte * param_2)
 */


void FUN_0101a79c(byte *param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  
  if ((param_1[3] & 0x3f) == 0) {
    FUN_01026284((undefined4 *)param_2,param_1[3] & 0x3f,0x28);
    return;
  }
  uVar3 = FUN_0100e84c(param_1);
  param_2[0x11] = (byte)uVar3;
  bVar2 = FUN_0100e864(param_1);
  param_2[0x12] = bVar2;
  param_2[1] = param_1[4];
  bVar2 = param_1[3];
  *param_2 = bVar2 >> 6;
  bVar1 = param_1[4];
  uVar3 = (uint)bVar1;
  pbVar6 = (byte *)(uVar3 & 1);
  if ((bVar1 & 1) == 0) {
    iVar7 = 5;
    uVar8 = 0xb;
    uVar5 = 5;
  }
  else {
    iVar7 = 0xb;
    uVar5 = 0xb;
    pbVar6 = param_1 + 5;
    uVar8 = 0x11;
  }
  pbVar4 = (byte *)(uVar3 & 2);
  *(byte **)(param_2 + 4) = pbVar6;
  if ((bVar1 & 2) != 0) {
    pbVar4 = param_1 + iVar7;
    uVar5 = uVar8;
  }
  *(byte **)(param_2 + 8) = pbVar4;
  if ((int)(uVar3 << 0x1d) < 0) {
    uVar5 = uVar5 + 1;
  }
  pbVar6 = (byte *)(uVar3 & 8);
  uVar8 = uVar5;
  if ((bVar1 & 8) != 0) {
    uVar8 = uVar5 + 2;
    pbVar6 = param_1 + uVar5;
  }
  *(byte **)(param_2 + 0x14) = pbVar6;
  pbVar6 = (byte *)(uVar3 & 0x10);
  uVar5 = uVar8;
  if ((bVar1 & 0x10) != 0) {
    uVar5 = uVar8 + 3;
    pbVar6 = param_1 + uVar8;
  }
  *(byte **)(param_2 + 0x18) = pbVar6;
  pbVar6 = (byte *)(uVar3 & 0x20);
  if ((bVar1 & 0x20) != 0) {
    pbVar6 = param_1 + uVar5;
    uVar5 = uVar5 + 0x12 & 0xff;
  }
  pbVar4 = (byte *)(uVar3 & 0x40);
  *(byte **)(param_2 + 0x1c) = pbVar6;
  if ((bVar1 & 0x40) != 0) {
    pbVar4 = param_1 + uVar5;
    uVar5 = uVar5 + 1 & 0xff;
  }
  uVar3 = bVar2 & 0x3f;
  *(byte **)(param_2 + 0x20) = pbVar4;
  uVar8 = (uVar3 + 4) - uVar5 & 0xff;
  if (uVar8 == 0) {
    pbVar6 = (byte *)0x0;
  }
  else {
    pbVar6 = param_1 + uVar5;
  }
  *(byte **)(param_2 + 0x24) = pbVar6;
  uVar3 = (param_1[1] - 1) - uVar3;
  param_2[0x10] = (byte)uVar3;
  if ((uVar3 & 0xff) == 0) {
    param_2[0xc] = 0;
    param_2[0xd] = 0;
    param_2[0xe] = 0;
    param_2[0xf] = 0;
    return;
  }
  *(byte **)(param_2 + 0xc) = param_1 + uVar5 + uVar8;
  return;
}


