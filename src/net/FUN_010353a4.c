/*
 * Function: FUN_010353a4
 * Entry:    010353a4
 * Prototype: undefined __stdcall FUN_010353a4(undefined4 param_1, int param_2, uint param_3)
 */


void FUN_010353a4(undefined4 param_1,int param_2,uint param_3)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  P1_NS *pPVar8;
  uint extraout_r1;
  uint uVar9;
  uint extraout_r2;
  byte *pbVar10;
  uint uVar11;
  uint *puVar12;
  int iVar13;
  bool bVar14;
  uint local_34;
  uint local_30 [3];
  
  uVar6 = Peripherals::GPIOTE_NS.INTENSET;
  uVar6 = FUN_01034e3c(uVar6 & 0xff | 0x80000000,param_2,param_3,(int *)&Peripherals::GPIOTE_NS);
  if ((int)uVar6 < 0) {
    local_30[0] = Peripherals::P0_NS.LATCH;
    Peripherals::P0_NS.LATCH = local_30[0];
    local_30[1] = Peripherals::P1_NS.LATCH;
    Peripherals::P1_NS.LATCH = local_30[1];
    uVar7 = extraout_r2;
LAB_010353dc:
    iVar13 = 0;
    puVar12 = local_30;
    do {
      pbVar10 = (byte *)(" 00000000000000" + iVar13 + 0xf);
      while (uVar9 = *puVar12, uVar9 != 0) {
        bVar3 = (byte)uVar9;
        bVar4 = (byte)(uVar9 >> 8);
        bVar5 = (byte)(uVar9 >> 0x10);
        bVar2 = (byte)(uVar9 >> 0x18);
        uVar9 = LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                         << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                      bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                        0x18 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                                bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                              bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                            bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 0x10 |
                        (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1)
                                         << 1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                      bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8
                        | (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 |
                                           bVar2 >> 2 & 1) << 1 | bVar2 >> 3 & 1) << 1 |
                                         bVar2 >> 4 & 1) << 1 | bVar2 >> 5 & 1) << 1 |
                                       bVar2 >> 6 & 1) << 1 | bVar2 >> 7)) |
                (uint)(byte)" 00000000000000"[iVar13 + 0xf] << 5;
        uVar7 = FUN_01034c68(uVar9);
        uVar1 = *(ushort *)((int)&DAT_210006a8 + (uVar7 + 8) * 2);
        *(byte *)((int)puVar12 + (extraout_r1 >> 3)) =
             *(byte *)((int)puVar12 + (extraout_r1 >> 3)) & ~(byte)(1 << (extraout_r1 & 7));
        local_34 = uVar9;
        pPVar8 = FUN_01034db4(&local_34);
        uVar11 = ((uint)uVar1 << 0x1b) >> 0x1d;
        uVar7 = ((&pPVar8->PIN_CNF_0_)[local_34] << 0xe) >> 0x1e;
        if ((int)((uint)(uVar1 >> 2) << 0x1d) < 0) {
          FUN_01034cf8(uVar9);
          local_34 = uVar9;
          pPVar8 = FUN_01034db4(&local_34);
          if (uVar7 == ((&pPVar8->PIN_CNF_0_)[local_34] << 0xe) >> 0x1e) {
            FUN_0103b17e(uVar9);
            FUN_0103b17e(uVar9);
          }
        }
        else {
          if (uVar7 == 2) {
            FUN_0103b17e(uVar9);
            bVar14 = (uVar11 & 5) == 1;
LAB_010354b2:
            if (!bVar14) goto LAB_01035478;
          }
          else {
            FUN_0103b17e(uVar9);
            if (uVar11 != 3) {
              if (uVar7 != 3) goto LAB_01035478;
              bVar14 = uVar11 == 2;
              goto LAB_010354b2;
            }
          }
          FUN_01034cf8(uVar9);
        }
LAB_01035478:
        local_34 = uVar9;
        pPVar8 = FUN_01034db4(&local_34);
        pbVar10 = (byte *)(1 << (local_34 & 0xff));
        pPVar8->LATCH = (uint)pbVar10;
        uVar7 = local_34;
      }
      puVar12 = puVar12 + 1;
      if (iVar13 != 0) goto LAB_010354d6;
      iVar13 = 1;
    } while( true );
  }
LAB_010354fe:
  for (; uVar6 != 0; uVar6 = uVar6 & ~(1 << iVar13)) {
    bVar3 = (byte)uVar6;
    bVar4 = (byte)(uVar6 >> 8);
    bVar5 = (byte)(uVar6 >> 0x10);
    bVar2 = (byte)(uVar6 >> 0x18);
    iVar13 = LZCOUNT((uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1) <<
                                      1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                   bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x18
                     | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1)
                                        << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                     bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) <<
                       0x10 | (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 |
                                               bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) << 1 |
                                             bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 |
                                           bVar5 >> 6 & 1) << 1 | bVar5 >> 7) << 8 |
                     (uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                      1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                   bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7));
    FUN_01034cf8(((&Peripherals::GPIOTE_NS.CONFIG_0_)[iVar13] << 0x12) >> 0x1a);
  }
  return;
LAB_010354d6:
  FUN_01034e3c(0x80000000,0,uVar7,(int *)pbVar10);
  local_30[0] = Peripherals::P0_NS.LATCH;
  Peripherals::P0_NS.LATCH = local_30[0];
  uVar7 = Peripherals::P1_NS.LATCH;
  local_30[1] = uVar7;
  Peripherals::P1_NS.LATCH = uVar7;
  if (local_30[0] == 0 && uVar7 == 0) goto code_r0x010354f8;
  goto LAB_010353dc;
code_r0x010354f8:
  uVar6 = uVar6 & 0x7fffffff;
  goto LAB_010354fe;
}


