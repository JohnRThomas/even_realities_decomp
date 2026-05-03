/*
 * Function: FUN_010356e4
 * Entry:    010356e4
 * Prototype: undefined1 * __stdcall FUN_010356e4(int * param_1, uint * param_2)
 */


undefined1 * FUN_010356e4(int *param_1,uint *param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined1 *puVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  
  uVar9 = *param_2;
  uVar7 = 16000000 / uVar9;
  if ((((uVar9 * uVar7 == 16000000) && (uVar9 < 0xf42401)) && ((uVar7 - 1 & uVar7) == 0)) &&
     (uVar7 < 0x201)) {
    bVar3 = (byte)uVar7;
    bVar4 = (byte)(uVar7 >> 8);
    bVar2 = (byte)(uVar7 >> 0x10);
    iVar6 = *param_1;
    bVar1 = *(byte *)((int)param_2 + 5);
    *(uint *)(iVar6 + 0x504) = (byte)param_2[1] & 3 | *(uint *)(iVar6 + 0x504) & 0xfffffffc;
    *(uint *)(iVar6 + 0x508) = *(uint *)(iVar6 + 0x508) & 0xfffffffc | bVar1 & 3;
    *(int *)(iVar6 + 0x510) =
         LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) << 1 |
                                 bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1
                              | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18 |
                 (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1) << 1 |
                                 bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1
                              | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                 (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) << 1 |
                                 bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1
                              | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 8);
    iVar8 = 0x40;
    iVar6 = *param_1;
    do {
      *(undefined4 *)(iVar6 + 0x100 + iVar8) = 0;
      iVar8 = iVar8 + 4;
    } while (iVar8 != 0x60);
    FUN_0102f2ec((char)((uint)(iVar6 << 0xc) >> 0x18));
    puVar5 = &DAT_0bad0000;
  }
  else {
    puVar5 = &DAT_0bad0004;
  }
  return puVar5;
}


