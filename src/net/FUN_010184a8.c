/*
 * Function: FUN_010184a8
 * Entry:    010184a8
 * Prototype: undefined __stdcall FUN_010184a8(void)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0101855a) */
/* WARNING: Removing unreachable block (ram,0x010185b6) */
/* WARNING: Removing unreachable block (ram,0x01018564) */
/* WARNING: Removing unreachable block (ram,0x0101856c) */
/* WARNING: Removing unreachable block (ram,0x010185c0) */

void FUN_010184a8(void)

{
  byte bVar1;
  ushort *puVar2;
  byte *pbVar3;
  undefined *puVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint extraout_r2_01;
  undefined4 extraout_r3;
  
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  pbVar3 = (byte *)FUN_01027648(puVar2,(ushort)bVar1);
  if (pbVar3 != (byte *)0x0) {
    puVar4 = FUN_0101b95c(4);
    if (puVar4 == (undefined *)0x0) {
      puVar4 = (undefined *)0x0;
      if (DAT_2100100c != '\0') {
        FUN_010210b0();
        puVar4 = (undefined *)FUN_010204a8();
        DAT_2100100c = '\0';
      }
      DAT_2100104a = 0;
      DAT_21001000 = 1;
      DAT_2100104c = 0;
      FUN_0101bcf4(puVar4);
      return;
    }
    DAT_21001000 = 0xc;
    FUN_0101bd4c(0,extraout_r1,extraout_r2_00);
    DAT_21001021 = (byte)(((uint)*pbVar3 << 0x1a) >> 0x1f);
    FUN_01016ae0(5);
    pbVar3 = DAT_21001050;
    bVar1 = *(byte *)(DAT_21000fe0 + 0xcd) & DAT_21001021;
    *(byte *)(DAT_21000fe0 + 0xcd) = bVar1;
    *pbVar3 = (bVar1 & 1) << 5 | *pbVar3 & 0xdf;
    return;
  }
  FUN_01009500(0x32,0x68a,extraout_r2,extraout_r3);
  puVar4 = (undefined *)(extraout_r2_01 >> 0x1e);
  if (puVar4 == (undefined *)0x0) {
    return;
  }
  if (DAT_2100100c != '\0') {
    FUN_010210b0();
    puVar4 = (undefined *)FUN_010204a8();
    DAT_2100100c = '\0';
  }
  DAT_2100104a = 0;
  DAT_21001000 = 1;
  DAT_2100104c = 0;
  FUN_0101bcf4(puVar4);
  return;
}


