/*
 * Function: FUN_0101877c
 * Entry:    0101877c
 * Prototype: undefined __stdcall FUN_0101877c(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0101877c(void)

{
  byte bVar1;
  ushort *puVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  uVar3 = FUN_01027648(puVar2,(ushort)bVar1);
  if (uVar3 == 0) {
    FUN_01009500(0x32,0x509,extraout_r2,extraout_r3);
    iVar5 = FUN_0100df60();
    DAT_2100001c = (undefined1)iVar5;
    FUN_01020d00();
    FUN_0101877c();
    return;
  }
  FUN_01019df8();
  bVar1 = (&DAT_2100104d)[DAT_21001028];
  DAT_21001049 = bVar1;
  puVar4 = FUN_0101b95c(0);
  if (puVar4 == (undefined *)0x0) {
    if (DAT_2100100c != '\0') {
      FUN_010210b0();
      FUN_010204a8();
      DAT_2100100c = '\0';
    }
    DAT_2100104a = 0;
    DAT_21001000 = 1;
    DAT_2100104c = 0;
    FUN_0101bcf4((undefined *)0x0);
    return;
  }
  if (DAT_21001000 == '\x02') {
    if (bVar1 == 1) goto LAB_010187c4;
LAB_01018806:
    DAT_2100100c = FUN_0100d34c(uVar3 + 5);
    if (DAT_2100100c == '\0') goto LAB_010187d2;
    if ((bVar1 & 0xc) == 0) {
      uVar3 = 0x50;
    }
    else {
      uVar3 = 0x55;
    }
  }
  else {
    FUN_01016c30(0,uVar3);
    if (bVar1 != 1) goto LAB_01018806;
LAB_010187c4:
    DAT_2100100c = FUN_0100d34c(uVar3 + 3);
    if (DAT_2100100c == '\0') goto LAB_010187d2;
    uVar3 = 0x40;
  }
  FUN_01020470();
  FUN_01021098(uVar3);
LAB_010187d2:
  if ((DAT_21000fe4 - 2 < 2) && ((&DAT_2100104d)[DAT_21001028] == '\x01')) {
    FUN_010210f0(0,0,1);
  }
  _DAT_21001008 = 0xffff;
  _DAT_21001010 = 0;
  DAT_21001038 = 0;
  DAT_21001000 = 5;
  return;
}


