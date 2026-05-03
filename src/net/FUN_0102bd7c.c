/*
 * Function: FUN_0102bd7c
 * Entry:    0102bd7c
 * Prototype: uint __stdcall FUN_0102bd7c(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_0102bd7c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int *piVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uStack_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  
  DAT_21004fa2 = (undefined1)param_1;
  Peripherals::P0_NS.DIRSET = 0xf0000010;
  Peripherals::P0_NS.OUTCLR = 0xf0000000;
  DAT_21004628 = param_2;
  uStack_18 = param_1;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  piVar2 = (int *)FUN_01030b3c(0);
  if (piVar2 == (int *)0x0) {
    if (0 < DAT_21000580) {
      FUN_01039ee2((byte *)"Unable get Clock\n",extraout_r1,extraout_r2,DAT_21000580);
    }
    uVar5 = 0xfffffffa;
  }
  else {
    local_14 = 0;
    local_c = 0;
    local_10 = 1;
    uVar5 = FUN_0102d240(piVar2,&uStack_18);
    uVar1 = local_c;
    if ((int)uVar5 < 0) {
      if (0 < DAT_21000580) {
        FUN_01039ee2((byte *)"Clock request failed: %d\n",uVar5,extraout_r2_00,DAT_21000580);
      }
    }
    else {
      do {
      } while ((local_10 & 3) != 0);
      uVar3 = extraout_r1_00;
      uVar4 = extraout_r2_00;
      if (local_c != 0) {
        if (0 < DAT_21000580) {
          FUN_01039ee2((byte *)"Clock can not starte %d\n",local_c,extraout_r2_00,DAT_21000580);
          uVar3 = extraout_r1_01;
          uVar4 = extraout_r2_01;
        }
        if ((int)uVar1 < 0) {
          return uVar1;
        }
      }
      FUN_0102c368(0x102bf19,uVar3,uVar4);
      uVar5 = 0;
    }
  }
  return uVar5;
}


