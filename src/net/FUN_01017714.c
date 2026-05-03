/*
 * Function: FUN_01017714
 * Entry:    01017714
 * Prototype: uint __stdcall FUN_01017714(int param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01017850) */
/* WARNING: Removing unreachable block (ram,0x01017864) */
/* WARNING: Removing unreachable block (ram,0x01017868) */
/* WARNING: Removing unreachable block (ram,0x0101786c) */
/* WARNING: Removing unreachable block (ram,0x0101787c) */
/* WARNING: Removing unreachable block (ram,0x01017880) */

uint FUN_01017714(int param_1)

{
  undefined1 uVar1;
  byte bVar2;
  bool bVar3;
  ushort *puVar4;
  uint uVar5;
  undefined4 extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar6;
  
  if (DAT_2100104c < 0x60) {
    uVar6 = (uint)*(byte *)((int)&DAT_0103c210 + (uint)(DAT_2100104c >> 5));
  }
  else {
    uVar6 = 0;
  }
  if (DAT_21001004 != 0) {
    puVar4 = (ushort *)FUN_0100ada0();
    bVar2 = FUN_0100adb4();
    uVar5 = FUN_01027648(puVar4,(ushort)bVar2);
    if (uVar5 == 0) {
      FUN_01009500(0x32,0x5db,extraout_r2,extraout_r3);
      *(int *)extraout_r2_00 = extraout_r2_00;
      *(undefined4 *)(extraout_r2_00 + 4) = extraout_r3_00;
      uVar6 = FUN_010200d8();
      if (((int)(uVar6 << 0x1d) < 0) || ((LAB_00000002 & 0xe0) != 0x40)) {
        FUN_010200d8();
      }
      return 0;
    }
    FUN_0101766c(0,uVar5);
  }
  uVar5 = FUN_01020fcc(DAT_21001024);
  uVar1 = (undefined1)uVar6;
  if (DAT_21000fe4 == '\x02') {
    if (DAT_21001018 != '\x02') {
      if (param_1 != 0) {
        DAT_21001010 = 0;
        DAT_21001039 = 0x101;
        DAT_21001049 = uVar1;
        return uVar5;
      }
      goto LAB_010177aa;
    }
LAB_01017784:
    if (((uVar6 & 0xc) != 0) && (DAT_21000fea == '\x01')) {
      uVar6 = 4;
    }
    uVar5 = FUN_010210f0(0,0,uVar6);
  }
  else if ((DAT_21000fe4 == '\x03') && (DAT_21001018 == '\x01')) goto LAB_01017784;
  if (param_1 != 0) {
    DAT_21001039 = 0x101;
    DAT_21001049 = uVar1;
    DAT_21001010 = 0;
    return uVar5;
  }
  if (DAT_21001018 == '\x02') {
    DAT_21001039 = 0;
    DAT_21001049 = uVar1;
    DAT_21001010 = 0;
    return uVar5;
  }
LAB_010177aa:
  if (DAT_21001018 == '\x01') {
    DAT_21001010 = 0;
    DAT_21001039 = CONCAT11(DAT_21001049 == '\x02',DAT_21001049 == '\x02');
    DAT_21001049 = uVar1;
    return uVar5;
  }
  if (DAT_21001018 == '\0') {
    bVar3 = FUN_0101a1cc();
    DAT_21001039 = CONCAT11(DAT_21001039._1_1_,bVar3);
    bVar3 = FUN_01019d60();
    DAT_21001039 = CONCAT11(bVar3,(undefined1)DAT_21001039);
    DAT_21001010 = 0;
    DAT_21001049 = uVar1;
    return (uint)bVar3;
  }
  DAT_21001010 = 0;
  DAT_21001049 = uVar1;
  return uVar5;
}


