/*
 * Function: FUN_01033b74
 * Entry:    01033b74
 * Prototype: int __stdcall FUN_01033b74(undefined4 * param_1)
 */


int FUN_01033b74(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *extraout_r1;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  byte local_40 [4];
  char *local_3c;
  undefined1 *local_30;
  undefined4 local_2c;
  undefined4 uStack_28;
  byte local_20 [4];
  char *local_1c;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0x16;
  }
  if (DAT_21006459 != '\0') {
    FUN_01033b14();
  }
  DAT_21004a90 = param_1[1];
  puVar9 = param_1 + 4;
  puVar5 = (undefined4 *)&DAT_21004a94;
  do {
    uVar2 = *param_1;
    uVar3 = param_1[1];
    param_1 = param_1 + 2;
    *puVar5 = uVar2;
    puVar5[1] = uVar3;
    puVar5 = puVar5 + 2;
  } while (param_1 != puVar9);
  *puVar5 = *param_1;
  DAT_210049b0 = 0;
  FUN_0103bdee(&DAT_21004b7c,0,0x20);
  DAT_21006256 = 0;
  DAT_2100625a = 0;
  FUN_01032f24();
  if (DAT_21004a94 == '\0') {
    puVar7 = &LAB_01033364_1;
LAB_01033bda:
    *extraout_r1 = puVar7;
  }
  else if (DAT_21004a94 == '\x01') {
    puVar7 = (undefined1 *)0x10333a5;
    goto LAB_01033bda;
  }
  if (DAT_21004a9d == '\x01') {
    Peripherals::RADIO_NS.CRCINIT = 0xff;
    Peripherals::RADIO_NS.CRCCNF = 1;
    puVar4 = (undefined *)0x107;
  }
  else if (DAT_21004a9d == '\x02') {
    Peripherals::RADIO_NS.CRCINIT = 0xffff;
    Peripherals::RADIO_NS.CRCCNF = 2;
    puVar4 = &DAT_00011021;
  }
  else {
    if (DAT_21004a9d != '\0') goto LAB_01033c0c;
    Peripherals::RADIO_NS.CRCINIT = 0;
    Peripherals::RADIO_NS.CRCCNF = 0;
    puVar4 = (undefined *)0x0;
  }
  Peripherals::RADIO_NS.CRCPOLY = (uint)puVar4;
LAB_01033c0c:
  (*(code *)*extraout_r1)(DAT_21004aa5);
  Peripherals::RADIO_NS.BASE0 = 0xe7e7e7e7;
  Peripherals::RADIO_NS.BASE1 = 0x43434343;
  Peripherals::RADIO_NS.PREFIX0 = 0x23c343e7;
  Peripherals::RADIO_NS.PREFIX1 = 0x13e363a3;
  puVar5 = (undefined4 *)FUN_01032f60();
  puVar6 = &DAT_21005a56;
  iVar8 = 0;
  puVar4 = &DAT_21005a56;
  do {
    iVar8 = iVar8 + 1;
    *puVar5 = puVar4;
    puVar4 = puVar4 + 0x100;
    puVar5 = puVar5 + 1;
  } while (iVar8 != 8);
  iVar8 = 0;
  puVar4 = &DAT_21005256;
  puVar5 = &DAT_21004a34;
  do {
    iVar8 = iVar8 + 1;
    *puVar5 = puVar4;
    puVar4 = puVar4 + 0x100;
    puVar5 = puVar5 + 1;
  } while (iVar8 != 8);
  iVar8 = 0;
  puVar5 = &DAT_210049d4;
  do {
    iVar8 = iVar8 + 1;
    *puVar5 = puVar6;
    *(undefined1 *)(puVar5 + 1) = 0;
    puVar5[2] = 0;
    puVar6 = puVar6 + 0x100;
    puVar5 = puVar5 + 3;
  } while (iVar8 != 8);
  FUN_0103bdee(&DAT_210049b4,0,0x20);
  local_30 = &DAT_000f4240;
  local_2c = 0;
  uStack_28 = 0;
  puVar7 = FUN_01035768(&DAT_21000698,(uint *)&local_30,&LAB_01032f7c_1);
  if (puVar7 == &DAT_0bad0000) {
    iVar8 = FUN_010345b0();
    if (iVar8 == 0) {
      DAT_21000660 = FUN_010345a4();
      uVar1 = Peripherals::RADIO_NS.MODECNF0;
      Peripherals::RADIO_NS.MODECNF0 = uVar1 & 0x300 | (uint)DAT_21004aa7;
      FUN_0103affe();
      FUN_0102f34c('\b',1,0);
      FUN_0102f34c('\x1d',2,0);
      FUN_0102f34c('\x19',2,0);
      FUN_0103ab4a(8,1,0x1032f99,0,0);
      FUN_0103ab4a(0x1d,2,&LAB_0103305c_1,0,0);
      FUN_0103ab4a(0x19,2,&LAB_0103affa_1,0,0);
      FUN_0102f2ec('\b');
      FUN_0102f2ec('\x1d');
      FUN_0102f2ec('\x19');
      DAT_21006458 = 0;
      DAT_21006459 = '\x01';
    }
    else {
      local_1c = "Failed to initialize PPI";
      local_20[0] = 2;
      local_20[1] = 0;
      local_20[2] = 0;
      local_20[3] = 0;
      FUN_0102ea44(0x103c01c,0x1040,local_20,(undefined1 *)0x0);
    }
  }
  else {
    local_3c = "Failed to initialize nrfx timer (err %d)";
    local_40[0] = 3;
    local_40[1] = 0;
    local_40[2] = 0;
    local_40[3] = 0;
    FUN_0102ea44(0x103c01c,0x1840,local_40,(undefined1 *)0x0);
    local_1c = "Failed to initialize ESB system timer";
    local_20[0] = 2;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[3] = 0;
    iVar8 = -0xe;
    FUN_0102ea44(0x103c01c,0x1040,local_20,(undefined1 *)0x0);
  }
  return iVar8;
}


