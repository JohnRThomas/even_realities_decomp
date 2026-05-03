/*
 * Function: FUN_01018400
 * Entry:    01018400
 * Prototype: undefined __stdcall FUN_01018400(void)
 */


/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x0101855a) */
/* WARNING: Removing unreachable block (ram,0x010185b6) */
/* WARNING: Removing unreachable block (ram,0x01018564) */
/* WARNING: Removing unreachable block (ram,0x0101856c) */
/* WARNING: Removing unreachable block (ram,0x010185c0) */

void FUN_01018400(void)

{
  byte bVar1;
  ushort *puVar2;
  byte *pbVar3;
  undefined *puVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  uint extraout_r2_03;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  pbVar3 = (byte *)FUN_01027648(puVar2,(ushort)bVar1);
  if (pbVar3 != (byte *)0x0) {
    puVar4 = FUN_0101b95c(6);
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
    DAT_21001000 = 0xe;
    FUN_0101bd4c(1,extraout_r1,extraout_r2_00);
    FUN_010210f0(0,1,(uint)DAT_21001049);
    DAT_21001021 = (byte)(((uint)*pbVar3 << 0x1a) >> 0x1f);
    FUN_01016ae0(5);
    pbVar3 = DAT_21001050;
    *(undefined1 *)(DAT_21000fe0 + 0xcd) = 1;
    *pbVar3 = *pbVar3 & 0xdf;
    return;
  }
  FUN_01009500(0x32,0x6b0,extraout_r2,extraout_r3);
  puVar2 = (ushort *)FUN_0100ada0();
  bVar1 = FUN_0100adb4();
  pbVar3 = (byte *)FUN_01027648(puVar2,(ushort)bVar1);
  if (pbVar3 == (byte *)0x0) {
    FUN_01009500(0x32,0x68a,extraout_r2_01,extraout_r3_00);
    puVar4 = (undefined *)(extraout_r2_03 >> 0x1e);
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
  FUN_0101bd4c(0,extraout_r1_00,extraout_r2_02);
  DAT_21001021 = (byte)(((uint)*pbVar3 << 0x1a) >> 0x1f);
  FUN_01016ae0(5);
  pbVar3 = DAT_21001050;
  bVar1 = *(byte *)(DAT_21000fe0 + 0xcd) & DAT_21001021;
  *(byte *)(DAT_21000fe0 + 0xcd) = bVar1;
  *pbVar3 = (bVar1 & 1) << 5 | *pbVar3 & 0xdf;
  return;
}


