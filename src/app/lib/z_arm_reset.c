/*
 * Function: z_arm_reset
 * Entry:    0004f76c
 * Prototype: void __stdcall z_arm_reset(void)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* exclude_from_export_ai */

void z_arm_reset(void)

{
  undefined4 uVar1;
  uint uVar2;
  int extraout_r0;
  int extraout_r0_00;
  int extraout_r0_01;
  int extraout_r0_02;
  int extraout_r0_03;
  int iVar3;
  int iVar4;
  
  z_arm_platform_init();
  if ((extraout_r0 != 0) && (iVar3 = DAT_50004a20, iVar3 == 0)) {
    DAT_50004a20 = 0xd;
    DAT_5000491c = 1;
    DAT_5000491c = 0;
  }
  iVar3 = 0;
  do {
    if ((&Peripherals::FICR_S.TRIMCNF_0__ADDR)[iVar3 * 2] == 0xffffffff) break;
    iVar4 = iVar3 + 1;
    *(uint *)(&Peripherals::FICR_S.TRIMCNF_0__ADDR)[iVar3 * 2] =
         (&Peripherals::FICR_S.TRIMCNF_0__DATA)[iVar3 * 2];
    iVar3 = iVar4;
  } while (iVar4 != 0x20);
  z_arm_platform_init();
  if (extraout_r0_00 != 0) {
    DAT_5000470c = 0x29;
    DAT_5000473c = 3;
  }
  z_arm_platform_init();
  if (extraout_r0_01 != 0) {
    DAT_50039530 = 0xbeef0044;
    Peripherals::CLOCK_S.HFCLKCTRL = 1;
  }
  iVar3 = Peripherals::FICR_S._304_4_;
  iVar4 = Peripherals::FICR_S._308_4_;
  if (((iVar3 == 7) && (iVar4 - 2U < 4)) && ((&DAT_000f49d9)[iVar4] != '\0')) {
    _DAT_5003254c = 0;
  }
  z_arm_platform_init();
  if ((extraout_r0_02 != 0) && (iVar3 = Peripherals::CLOCK_S._1024_4_, iVar3 << 0x1f < 0)) {
    Peripherals::CLOCK_S._276_4_ = 0;
    Peripherals::CLOCK_S._280_4_ = 0;
  }
  iVar3 = Peripherals::FICR_S._304_4_;
  uVar1 = Peripherals::FICR_S._308_4_;
  if ((iVar3 == 7) && (iVar3 = Peripherals::CLOCK_S._1024_4_, iVar3 << 0x1f < 0)) {
    Peripherals::CLOCK_S._1024_4_ = 0xfffffffe;
  }
  z_arm_platform_init();
  if (extraout_r0_03 != 0) {
    DAT_5000470c = 0x65;
  }
  iVar3 = Peripherals::FICR_S._304_4_;
  uVar1 = Peripherals::FICR_S._308_4_;
  if ((iVar3 == 7) && (_DAT_50032420 < 0)) {
    Peripherals::CLOCK_S.LFCLKSRC = 3;
    Peripherals::CLOCK_S.TASKS_LFCLKSTART = 1;
    do {
      uVar2 = Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED;
    } while (uVar2 == 0);
    Peripherals::CLOCK_S.EVENTS_LFCLKSTARTED = 0;
    Peripherals::CLOCK_S.TASKS_LFCLKSTOP = 1;
    Peripherals::CLOCK_S.LFCLKSRC = 1;
  }
  iVar3 = Peripherals::FICR_S._304_4_;
  iVar4 = Peripherals::FICR_S._308_4_;
  if ((iVar3 == 7) && ((3 < iVar4 - 2U || ((&DAT_000f49d5)[iVar4] != '\0')))) {
    DAT_5000470c = 0x7e;
    DAT_5000493c = 0x7e;
    _DAT_50002118 = 0x7f;
    DAT_50039e04 = 0;
    DAT_50039e08 = 0;
    _DAT_50101110 = 0;
    _DAT_50002124 = 0;
    _DAT_5000212c = 0;
    _DAT_502012a0 = 0;
  }
  _DAT_e000ed8c = _DAT_e000ed8c | 0xc00;
  uVar2 = Peripherals::UICR_S.APPROTECT;
  Peripherals::CTRLAP_S._1348_4_ = uVar2;
  uVar2 = Peripherals::UICR_S.SECUREAPPROTECT;
  Peripherals::CTRLAP_S._1356_4_ = uVar2;
  _DAT_e000ed88 = _DAT_e000ed88 | 0xf00000;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


