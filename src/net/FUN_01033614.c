/*
 * Function: FUN_01033614
 * Entry:    01033614
 * Prototype: undefined __stdcall FUN_01033614(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01033614(void)

{
  code *pcVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte extraout_r1;
  byte extraout_r1_00;
  byte bVar4;
  byte extraout_r1_01;
  byte extraout_r1_02;
  byte extraout_r1_03;
  undefined4 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  uVar9 = Peripherals::RADIO_NS.CRCSTATUS;
  uVar9 = uVar9 & 1;
  if ((uVar9 == 0) || (7 < DAT_21004a5c)) {
    FUN_01033174();
    return;
  }
  uVar6 = Peripherals::RADIO_NS.RXMATCH;
  uVar6 = uVar6 & 0xff;
  uVar10 = Peripherals::RADIO_NS.RXCRC;
  iVar8 = uVar6 * 4;
  if ((uVar10 == *(ushort *)(&DAT_21004b7c + uVar6 * 4)) &&
     (((uint)DAT_2100625f << 0x1d) >> 0x1e == (uint)(byte)(&DAT_21004b7e)[iVar8])) {
    uVar10 = 0;
    uVar11 = uVar9;
  }
  else {
    uVar11 = 0;
    uVar10 = uVar9;
  }
  (&DAT_21004b7e)[iVar8] = (byte)(((uint)DAT_2100625f << 0x1d) >> 0x1e);
  uVar9 = Peripherals::RADIO_NS.RXCRC;
  *(short *)(&DAT_21004b7c + uVar6 * 4) = (short)uVar9;
  if ((DAT_21004aa6 != '\0') && (-1 < (int)((uint)DAT_2100625f << 0x1f))) {
    FUN_01033174();
    goto LAB_01033778;
  }
  FUN_010220e4();
  uVar3 = FUN_010220c0();
  bVar4 = DAT_21004a94;
  Peripherals::RADIO_NS.SHORTS = 0x11b;
  if (DAT_21004a94 == 0) {
    uVar3 = (*DAT_2100499c)(0);
    DAT_2100635b = DAT_2100635b & 0xfc | (byte)(((uint)DAT_2100625e << 0x1e) >> 0x1e);
    DAT_2100635c = bVar4;
    bVar4 = extraout_r1_03;
  }
  else {
    bVar4 = extraout_r1;
    if (DAT_21004a94 == 1) {
      uVar9 = Peripherals::RADIO_NS.RXMATCH;
      if (DAT_21004a88 == 0) {
LAB_010337c4:
        (&DAT_21004b7f)[iVar8] = 0;
        uVar3 = (*DAT_2100499c)(0);
        bVar4 = extraout_r1_02;
LAB_010337be:
        DAT_2100635b = 0;
      }
      else {
        uVar9 = uVar9 & 0xff;
        puVar5 = *(undefined4 **)(&DAT_210049b4 + uVar9 * 4);
        if (puVar5 == (undefined4 *)0x0) goto LAB_010337c4;
        DAT_21004a8c = (byte *)*puVar5;
        if (((&DAT_21004b7f)[iVar8] != '\0') && (uVar11 == 0)) {
          *(undefined1 *)(puVar5 + 1) = 0;
          iVar7 = DAT_21004a88 + -1;
          puVar5 = *(undefined4 **)(*(int *)(&DAT_210049b4 + uVar9 * 4) + 8);
          DAT_21004a88 = iVar7;
          *(undefined4 **)(&DAT_210049b4 + uVar9 * 4) = puVar5;
          if (iVar7 == 0) {
            DAT_21004a8c = (byte *)0x0;
          }
          else {
            DAT_21004a8c = (byte *)0x0;
            if (puVar5 != (undefined4 *)0x0) {
              DAT_21004a8c = (byte *)*puVar5;
            }
          }
          DAT_210049b0 = DAT_210049b0 | 1;
        }
        pbVar2 = DAT_21004a8c;
        pcVar1 = DAT_2100499c;
        if (DAT_21004a8c == (byte *)0x0) {
          (&DAT_21004b7f)[iVar8] = 0;
          uVar3 = (*pcVar1)(0);
          bVar4 = extraout_r1_01;
          goto LAB_010337be;
        }
        (&DAT_21004b7f)[iVar8] = 1;
        (*pcVar1)(*pbVar2);
        DAT_2100635b = *DAT_21004a8c;
        uVar3 = FUN_0103bcfa(&DAT_2100635d,DAT_21004a8c + 5,(undefined1 *)(uint)DAT_2100635b,
                             &UNK_000000fb);
        bVar4 = extraout_r1_00;
      }
      DAT_2100635c = DAT_2100635c & 0xf8 | DAT_2100625f & 7;
    }
  }
  DAT_21006458 = 5;
  FUN_01033298(uVar3,bVar4);
  uVar9 = Peripherals::RADIO_NS.RXMATCH;
  Peripherals::RADIO_NS.TXADDRESS = uVar9 & 0xff;
  Peripherals::RADIO_NS.PACKETPTR = 0x2100635b;
  DAT_210049a0 = &LAB_01032fc4_1;
LAB_01033778:
  if (uVar10 != 0) {
    uVar9 = Peripherals::RADIO_NS.RXMATCH;
    if ((DAT_21004a5c < 8) && (iVar8 = FUN_010331fc((byte)uVar9,(&DAT_21004b7e)[iVar8]), iVar8 != 0)
       ) {
      DAT_210049b0 = DAT_210049b0 | 4;
      _DAT_e000e200 = 0x20000000;
    }
  }
  return;
}


