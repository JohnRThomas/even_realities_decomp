/*
 * Function: FUN_0103515c
 * Entry:    0103515c
 * Prototype: undefined1 * __stdcall FUN_0103515c(void)
 */


undefined1 * FUN_0103515c(void)

{
  int iVar1;
  uint *puVar2;
  undefined1 *puVar3;
  undefined4 extraout_r1;
  undefined4 uVar4;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 uVar5;
  undefined4 extraout_r2_00;
  uint extraout_r3;
  uint uVar6;
  uint uVar7;
  
  if (DAT_21000720 == '\0') {
    FUN_0103bdee((undefined1 *)&DAT_210006b8,0,0x60);
    uVar7 = 0;
    uVar4 = extraout_r1;
    uVar5 = extraout_r2;
    uVar6 = extraout_r3;
    do {
      iVar1 = FUN_01034e10(uVar7 & 0xff,uVar4,uVar5,uVar6);
      uVar6 = iVar1 - 0x100U >> 2;
      if (uVar6 == 0x1f) {
        puVar2 = (uint *)((int)&Peripherals::GPIOTE_NS.TASKS_OUT_0_ + iVar1);
        *puVar2 = 0;
        uVar6 = *puVar2;
      }
      uVar7 = uVar7 + 1;
      uVar4 = extraout_r1_00;
      uVar5 = extraout_r2_00;
    } while (uVar7 != 8);
    Peripherals::GPIOTE_NS.EVENTS_PORT = 0;
    uVar7 = Peripherals::GPIOTE_NS.EVENTS_PORT;
    FUN_0102f2ec('\n');
    Peripherals::GPIOTE_NS.INTENSET = 0x80000000;
    puVar3 = &DAT_0bad0000;
    DAT_21000720 = '\x01';
    DAT_2100071c = 1;
  }
  else {
    puVar3 = &DAT_0bad0005;
  }
  return puVar3;
}


