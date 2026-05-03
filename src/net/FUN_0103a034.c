/*
 * Function: FUN_0103a034
 * Entry:    0103a034
 * Prototype: uint __stdcall FUN_0103a034(int param_1, uint param_2)
 */


uint FUN_0103a034(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  uVar5 = FUN_01039f92(*(uint *)(param_1 + 8));
  iVar10 = param_1 + uVar5 * 4;
  uVar9 = *(uint *)(iVar10 + 0x10);
  if (uVar9 != 0) {
    iVar8 = 3;
    do {
      uVar7 = *(uint *)(iVar10 + 0x10);
      uVar6 = FUN_01039f28(param_1,uVar7);
      if (param_2 <= uVar6) goto LAB_0103a066;
      uVar7 = FUN_01039efc(param_1,uVar7,3);
      iVar8 = iVar8 + -1;
      *(uint *)(iVar10 + 0x10) = uVar7;
    } while ((iVar8 != 0) && (uVar9 != uVar7));
  }
  uVar5 = -1 << (uVar5 + 1 & 0xff) & *(uint *)(param_1 + 0xc);
  uVar7 = 0;
  if (uVar5 != 0) {
    bVar2 = (byte)uVar5;
    bVar3 = (byte)(uVar5 >> 8);
    bVar4 = (byte)(uVar5 >> 0x10);
    bVar1 = (byte)(uVar5 >> 0x18);
    uVar5 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                     1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                  bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                    | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                       << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                    bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                      0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                              bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                            bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                          bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                    (uint)(byte)((((((((bVar1 & 1) << 1 | bVar1 >> 1 & 1) << 1 | bVar1 >> 2 & 1) <<
                                     1 | bVar1 >> 3 & 1) << 1 | bVar1 >> 4 & 1) << 1 |
                                  bVar1 >> 5 & 1) << 1 | bVar1 >> 6 & 1) << 1 | bVar1 >> 7));
    uVar7 = *(uint *)(param_1 + (uVar5 + 4) * 4);
LAB_0103a066:
    FUN_01039faa(param_1,uVar7,uVar5);
  }
  return uVar7;
}


