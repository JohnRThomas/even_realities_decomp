/*
 * Function: FUN_0102dbf4
 * Entry:    0102dbf4
 * Prototype: undefined __stdcall FUN_0102dbf4(int param_1, undefined4 param_2, uint param_3)
 */


void FUN_0102dbf4(int param_1,undefined4 param_2,uint param_3)

{
  longlong lVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar4;
  undefined4 extraout_r1_01;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar5;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  code *pcVar6;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar7;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined1 *unaff_r5;
  uint unaff_r6;
  uint unaff_r8;
  uint unaff_r9;
  uint unaff_r10;
  undefined8 uVar8;
  byte local_30 [4];
  char *local_2c;
  int iStack_28;
  uint local_24;
  
  pcVar6 = *(code **)(*(int *)(param_1 + 8) + 0x10);
  uVar4 = 0;
  if (pcVar6 != (code *)0x0) {
    uVar8 = (*pcVar6)(param_1,param_2,0);
    unaff_r5 = (undefined1 *)uVar8;
    uVar4 = extraout_r3;
    if (unaff_r5 == (undefined1 *)0x0) {
      unaff_r9 = (param_3 << 0x10) >> 0x18;
      unaff_r6 = FUN_01031b38(unaff_r9,(int)((ulonglong)uVar8 >> 0x20),extraout_r2,extraout_r3);
      unaff_r8 = param_3 & 0xff;
      unaff_r10 = param_3 >> 0x18;
      uVar4 = extraout_r1;
      uVar5 = extraout_r2_00;
      uVar7 = extraout_r3_00;
      if (param_3 < 0x10000000) goto LAB_0102dc4c;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/modules/hal/nordic/nrfx/hal/nrf_ipc.h",0x1e7,extraout_r3_00);
      goto LAB_0102dc48;
    }
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
               "WEST_TOPDIR/zephyr/soc/arm/nordic_nrf/nrf53/sync_rtc.c",0xcb,uVar4);
LAB_0102dc48:
  while( true ) {
    FUN_0103a370();
    uVar4 = extraout_r1_00;
    uVar5 = extraout_r2_01;
    uVar7 = extraout_r3_01;
LAB_0102dc4c:
    iVar2 = FUN_01031b08(unaff_r9,uVar4,uVar5,uVar7);
    FUN_01034bf0(unaff_r8,iVar2,extraout_r2_02,extraout_r3_02);
    (&Peripherals::IPC_NS.PUBLISH_RECEIVE_0_)[unaff_r10] = (uint)unaff_r5;
    FUN_01034b6c(1 << (unaff_r8 & 0xff));
    FUN_01031ee0(unaff_r9,extraout_r1_01,extraout_r2_03,extraout_r3_03);
    puVar3 = (undefined1 *)FUN_01034c24(unaff_r8);
    if (puVar3 == &DAT_0bad0000) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/soc/arm/nordic_nrf/nrf53/sync_rtc.c",0x75,&DAT_0bad0000);
    unaff_r10 = unaff_r10 * 4;
  }
  iVar2 = DAT_21004654 * -2 + -100 + unaff_r6;
  DAT_210005ec = iVar2;
  FUN_0102e594(0x102da31,&DAT_00008000);
  local_2c = "Updated timestamp to synchronized RTC by %d ticks (%dus)";
  iStack_28 = DAT_210005ec;
  lVar1 = (longlong)iVar2 * 1000000;
  local_24 = (uint)lVar1 >> 0xf | (int)((ulonglong)lVar1 >> 0x20) << 0x11;
  local_30[0] = 4;
  local_30[1] = 0;
  local_30[2] = 0;
  local_30[3] = 0;
  FUN_0102ea44(0x103c094,0x20c0,local_30,unaff_r5);
  return;
}


