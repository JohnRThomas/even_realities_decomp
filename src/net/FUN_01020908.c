/*
 * Function: FUN_01020908
 * Entry:    01020908
 * Prototype: undefined __stdcall FUN_01020908(undefined4 param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01020976) */
/* WARNING: Removing unreachable block (ram,0x01020b5a) */
/* WARNING: Removing unreachable block (ram,0x01020b78) */
/* WARNING: Removing unreachable block (ram,0x01020bb4) */
/* WARNING: Removing unreachable block (ram,0x01020bf8) */
/* WARNING: Removing unreachable block (ram,0x01020c08) */
/* WARNING: Removing unreachable block (ram,0x01020c12) */
/* WARNING: Removing unreachable block (ram,0x01020c16) */
/* WARNING: Removing unreachable block (ram,0x01020ca8) */
/* WARNING: Removing unreachable block (ram,0x01020cae) */
/* WARNING: Removing unreachable block (ram,0x01020b90) */
/* WARNING: Removing unreachable block (ram,0x01020b94) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01020908(undefined4 param_1)

{
  short sVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint uVar5;
  uint extraout_r3;
  undefined4 extraout_r3_00;
  int unaff_r6;
  int unaff_r7;
  undefined8 uVar6;
  
  uVar5 = (uint)DAT_21001625;
  iVar4 = uVar5 << 0x1f;
  if (iVar4 < 0) {
    if ((int)(uVar5 << 0x1e) < 0) {
      uVar5 = Peripherals::RADIO_NS.SHORTS;
      Peripherals::RADIO_NS.SHORTS = uVar5 | 1;
      uVar2 = Peripherals::RADIO_NS.STATE;
      if ((uVar2 & 0xf6) != 2) {
        _MasterStackPointer = 0xb83d;
        return;
      }
      uVar6 = FUN_01009500(0x3e,0x5a7,uVar5 | 1,2);
      iVar4 = (int)((ulonglong)uVar6 >> 0x20);
      param_1 = (undefined4)uVar6;
      uVar5 = extraout_r3;
    }
    if ((int)(uVar5 << 0x1d) < 0) {
      Peripherals::RADIO_NS.SUBSCRIBE_START = 0x80000008;
      bVar3 = FUN_010242c4(param_1,iVar4,&DAT_80000008,&Peripherals::RADIO_NS);
      if (bVar3) {
        FUN_01009500(0x3e,0x5af,extraout_r2,extraout_r3_00);
        sVar1 = (short)(unaff_r6 >> 0x17);
        *(short *)(unaff_r6 >> 0x17) = sVar1;
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
        _MasterStackPointer = 0;
        DAT_21001608 = 0;
        FUN_01009500(0x3e,0xd35,extraout_r2_00,0xffffffff);
        *(short *)(unaff_r6 >> 0x17) = sVar1;
        _DAT_210015f4 = unaff_r7 << 7;
        DAT_210015f0 = &DAT_210015f0;
        FUN_01026284(&DAT_210015f0,0,0x48);
        DAT_41000e00 = 0x1111;
        _DAT_41007e40 = 0;
        _DAT_41007e44 = 0;
        _DAT_41007e00 = 0xaa;
        return;
      }
    }
  }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  return;
}


