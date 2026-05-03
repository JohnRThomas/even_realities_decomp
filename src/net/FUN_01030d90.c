/*
 * Function: FUN_01030d90
 * Entry:    01030d90
 * Prototype: uint __stdcall FUN_01030d90(int param_1, byte * param_2, uint param_3, uint param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_01030d90(int param_1,byte *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  uint uVar4;
  byte *extraout_r1;
  byte *pbVar5;
  uint extraout_r2;
  uint extraout_r3;
  uint uVar6;
  undefined4 uVar7;
  
  puVar2 = *(undefined **)(param_1 + 0x10);
  pbVar5 = param_2;
  uVar3 = param_3;
  if (puVar2 != &DAT_21004870) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/drivers/entropy/entropy_nrf5.c",0x102,param_4);
    puVar2 = (undefined *)FUN_0103a370();
    pbVar5 = extraout_r1;
    uVar3 = extraout_r2;
    param_4 = extraout_r3;
  }
  if ((~param_4 & 1) == 0) {
    if (uVar3 != 0) {
      uVar7 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar7 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      uVar3 = FUN_0102f330(9);
      FUN_0102f308('\t');
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar7);
      }
      InstructionSynchronizationBarrier(0xf);
      Peripherals::RNG_NS.EVENTS_VALRDY = 0;
      uVar6 = Peripherals::RNG_NS.EVENTS_VALRDY;
      Peripherals::RNG_NS.TASKS_START = 1;
      _DAT_e000e280 = 0x200;
      uVar6 = param_3;
      do {
        do {
          while (uVar4 = Peripherals::RNG_NS.EVENTS_VALRDY, uVar4 == 0) {
            uVar7 = 0;
            bVar1 = (bool)isCurrentModePrivileged();
            if (bVar1) {
              uVar7 = getBasePriority();
            }
            bVar1 = (bool)isCurrentModePrivileged();
            if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
              setBasePriority(0x40);
            }
            InstructionSynchronizationBarrier(0xf);
            FUN_0102f1c0(uVar7);
          }
          uVar4 = FUN_01030cc8();
          _DAT_e000e280 = 0x200;
        } while ((int)uVar4 < 0);
        uVar6 = uVar6 - 1 & 0xffff;
        param_2[uVar6] = (byte)uVar4;
      } while (uVar6 != 0);
      if (uVar3 != 0) {
        FUN_0102f2ec('\t');
      }
    }
  }
  else {
    param_3 = FUN_01030d04(puVar2 + 0x30,pbVar5,uVar3);
  }
  return param_3;
}


