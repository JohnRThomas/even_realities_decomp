/*
 * Function: FUN_00041ef4
 * Entry:    00041ef4
 * Prototype: undefined __stdcall FUN_00041ef4(int param_1)
 */


void FUN_00041ef4(int param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  uint uVar7;
  
  bVar1 = get_current_language();
  uVar7 = (uint)bVar1;
  gui_screen_clear(uVar7,extraout_r1,extraout_r2);
  if (param_1 == 0) {
    uVar7 = uVar7 - 5 & 0xff;
    if (uVar7 < 10) {
      uVar7 = (uint)(byte)(&DAT_000ac3c8)[uVar7];
    }
    else {
      uVar7 = 0x70;
    }
    iVar4 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x40,iVar4 + uVar7,uVar2 + 0x3a,0,0,0);
    pcVar5 = get_string(0x54);
    iVar4 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar4 = uVar7 + iVar4;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    uVar7 = uVar7 - 5 & 0xff;
    if (uVar7 < 10) {
      uVar7 = (uint)(byte)(&DAT_000ac3be)[uVar7];
    }
    else {
      uVar7 = 0x5c;
    }
    iVar4 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    gui_bmp_bitmap_draw(0x40,iVar4 + uVar7,uVar2 + 0x3a,0,0,0);
    pcVar5 = get_string(0x55);
    iVar4 = FUN_000809e2();
    uVar2 = FUN_00080a3a();
    iVar6 = FUN_000809e2();
    uVar3 = FUN_00080a3a();
    iVar4 = uVar7 + iVar4;
  }
  gui_utf_draw(0,pcVar5,0,iVar4 + 0x2c,uVar2 + 0x36,iVar6 + 0x240,uVar3 + 0x88,3,0,0,
               (undefined *)0x0,0);
  return;
}


