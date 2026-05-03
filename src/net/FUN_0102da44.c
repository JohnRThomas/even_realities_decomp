/*
 * Function: FUN_0102da44
 * Entry:    0102da44
 * Prototype: uint __stdcall FUN_0102da44(void)
 */


/* WARNING: Removing unreachable block (ram,0x0102da98) */

uint FUN_0102da44(void)

{
  bool bVar1;
  uint uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_r1;
  int extraout_r1_00;
  undefined4 extraout_r2;
  uint uVar6;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar7;
  uint uVar8;
  undefined8 uVar9;
  byte local_30 [4];
  char *local_2c;
  undefined4 local_1c;
  
  puVar3 = (undefined1 *)FUN_01034c18((undefined1 *)&local_1c);
  if (puVar3 == &DAT_0bad0000) {
    uVar4 = FUN_01031ea4();
    if ((int)uVar4 < 0) {
      FUN_01034c24(local_1c & 0xff);
    }
    else {
      local_1c = CONCAT22(0x708,CONCAT11((char)uVar4,(sbyte)local_1c));
      uVar4 = FUN_0103ad4c(0x103bf58,7,0x102dbf5,local_1c);
      if ((-1 < (int)uVar4) && (uVar4 = FUN_01031420(0x103bf58,7,1), -1 < (int)uVar4)) {
        FUN_01034b60(1 << (sbyte)local_1c);
        uVar2 = local_1c >> 0x10;
        uVar8 = local_1c & 0xff;
        iVar5 = FUN_01031adc(local_1c >> 8 & 0xff,extraout_r1,extraout_r2,extraout_r3);
        if (0xf < (uVar2 & 0xff)) {
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                       "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",0x1e1,extraout_r3_00);
          FUN_0103a370();
          iVar5 = extraout_r1_00;
        }
        uVar6 = uVar8 | 0x80000000;
        (&Peripherals::IPC_NS.SUBSCRIBE_SEND_0_)[uVar2 & 0x3f] = uVar6;
        FUN_01034b78(uVar8,iVar5,uVar6,0x41012080);
        uVar7 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar7 = getBasePriority();
        }
        bVar1 = (bool)isCurrentModePrivileged();
        if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        uVar9 = FUN_01031b68();
        DAT_21004654 = (int)uVar9 + 100;
        FUN_01031cd0(local_1c >> 8 & 0xff,(int)((ulonglong)uVar9 >> 0x20),DAT_21004654,0,
                     &LAB_0102db6c_1,local_1c);
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(uVar7);
        }
        InstructionSynchronizationBarrier(0xf);
        if (uVar4 == 0) {
          return 0;
        }
      }
    }
  }
  else {
    uVar4 = 0xffffffed;
  }
  local_2c = "Failed synchronized RTC setup (err: %d)";
  local_30[0] = 3;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  FUN_0102ea44(0x103c094,0x1840,local_30,(undefined1 *)0x0);
  return uVar4;
}


