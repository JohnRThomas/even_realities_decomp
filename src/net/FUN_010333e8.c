/*
 * Function: FUN_010333e8
 * Entry:    010333e8
 * Prototype: undefined __stdcall FUN_010333e8(undefined1 * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010333e8(undefined1 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  byte *extraout_r1;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  RADIO_NS *pRVar7;
  int *piVar8;
  undefined8 uVar9;
  
  pRVar7 = (RADIO_NS *)&DAT_21004a94;
  DAT_210049a8 = 1;
  piVar8 = (int *)&DAT_21004a8c;
  pbVar2 = *(byte **)(&DAT_21004a60 + DAT_21004a84 * 4);
  iVar6 = 0;
  DAT_21004a8c = pbVar2;
  if (DAT_21004a94 == '\0') goto LAB_01033448;
  if (DAT_21004a94 == '\x01') {
    bVar1 = 1;
    if (pbVar2[3] != 0) {
      bVar1 = DAT_21004aa6 ^ 1;
    }
    bVar3 = (pbVar2[4] & 3) << 1;
    if (pbVar2[3] == 0) {
      bVar3 = bVar3 | 1;
    }
    _DAT_2100635b = CONCAT11(bVar3,*pbVar2);
    FUN_0103bcfa(&DAT_2100635d,pbVar2 + 5,(undefined1 *)(uint)*pbVar2,&UNK_000000fb);
    if (bVar1 == 0) {
      Peripherals::RADIO_NS.SHORTS = 0x113;
      param_1 = &LAB_010335a4_1;
      DAT_210049a0 = &LAB_010335a4_1;
      bVar1 = 1;
      DAT_21006458 = 1;
      Peripherals::RADIO_NS.INTENSET = 0x10;
      iVar6 = 0;
      goto LAB_0103340a;
    }
    Peripherals::RADIO_NS.SHORTS = 0x11b;
    DAT_210049ac = (uint)DAT_21004aa0._2_2_;
    param_1 = &LAB_01033870_1;
    DAT_210049a0 = &LAB_01033870_1;
    pbVar2 = &LAB_00000002;
    DAT_21006458 = 2;
    Peripherals::RADIO_NS.INTENSET = 0x10;
  }
  while( true ) {
    bVar1 = (byte)pbVar2;
    iVar6 = 1;
LAB_0103340a:
    iVar4 = *piVar8;
    piVar8 = (int *)&DAT_00000001;
    pRVar7 = &Peripherals::RADIO_NS;
    Peripherals::RADIO_NS.TXADDRESS = (uint)*(byte *)(iVar4 + 1);
    Peripherals::RADIO_NS.RXADDRESSES = 1 << *(sbyte *)(iVar4 + 1) & 0xff;
    uVar5 = DAT_21000697 + 0x960;
    if (uVar5 < 0x9c5) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_radio.h",0x6b7,uVar5);
    FUN_0103a370();
    pbVar2 = extraout_r1;
LAB_01033448:
    _DAT_2100635b = (undefined2)iVar6;
    (*DAT_2100499c)(*pbVar2);
    pbVar2 = (byte *)*piVar8;
    _DAT_2100635b = CONCAT11(DAT_2100635c,DAT_2100635b & 0xfc | pbVar2[4] & 3);
    uVar9 = FUN_0103bcfa(&DAT_2100635d,pbVar2 + 5,(undefined1 *)(uint)*pbVar2,&UNK_000000fb);
    pbVar2 = (byte *)((ulonglong)uVar9 >> 0x20);
    param_1 = (undefined1 *)uVar9;
    Peripherals::RADIO_NS.SHORTS = 0x11b;
    Peripherals::RADIO_NS.INTENSET = 0x10;
    DAT_210049ac = (uint)*(ushort *)((int)&pRVar7->TASKS_STOP + 2);
    DAT_210049a0 = &LAB_01033870_1;
    DAT_21006458 = 2;
  }
  Peripherals::RADIO_NS.FREQUENCY = (uint)DAT_21000697;
  FUN_01033298(param_1,bVar1);
  Peripherals::RADIO_NS.PACKETPTR = 0x2100635b;
  _DAT_e000e280 = 0x100;
  FUN_0102f2ec('\b');
  Peripherals::RADIO_NS.EVENTS_ADDRESS = 0;
  uVar5 = Peripherals::RADIO_NS.EVENTS_ADDRESS;
  Peripherals::RADIO_NS.EVENTS_PAYLOAD = 0;
  uVar5 = Peripherals::RADIO_NS.EVENTS_PAYLOAD;
  Peripherals::RADIO_NS.EVENTS_DISABLED = 0;
  uVar5 = Peripherals::RADIO_NS.EVENTS_DISABLED;
  Peripherals::RADIO_NS.EVENTS_END = 0;
  uVar5 = Peripherals::RADIO_NS.EVENTS_END;
  FUN_010342d8('\0',iVar6);
  FUN_01033020(iVar6);
  Peripherals::EGU0_NS.TASKS_TRIGGER_6_ = 1;
  return;
}


