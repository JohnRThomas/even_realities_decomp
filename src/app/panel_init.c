/*
 * Function: panel_init
 * Entry:    00080e3a
 * Prototype: undefined __stdcall panel_init(void)
 */


void panel_init(void)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 extraout_r2_06;
  
  FUN_00080e16();
  FUN_00080ece(6);
  FUN_00080d0a(1,0x10,extraout_r2);
  FUN_00080d76(0);
  FUN_00080d20(0,0,extraout_r2_00);
  FUN_00080d20(0,0x14,extraout_r2_01);
  FUN_00080d20(0x18,0,extraout_r2_02);
  FUN_00080d20(0x18,0x14,extraout_r2_03);
  FUN_00080d20(0xc,10,extraout_r2_04);
  FUN_00080ece(0x71);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  FUN_00080ece(0x73);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  FUN_00080d46(0xf,extraout_r1,extraout_r2_05);
  FUN_00080d0a(0x31,4,extraout_r2_06);
  FUN_00080ece(0xa3);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  return;
}


