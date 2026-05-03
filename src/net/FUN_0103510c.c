/*
 * Function: FUN_0103510c
 * Entry:    0103510c
 * Prototype: undefined1 * __stdcall FUN_0103510c(uint param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


undefined1 * FUN_0103510c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 *puVar2;
  byte *extraout_r1;
  
  uVar1 = param_1;
  if (param_2 == 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_gpiote.c",0x265,param_4);
    uVar1 = FUN_0103a370();
  }
  uVar1 = FUN_01034c94(uVar1);
  if (uVar1 == 0) {
    puVar2 = &DAT_0bad0004;
  }
  else {
    uVar1 = FUN_01034c68(param_1);
    puVar2 = &DAT_0bad0000;
    *extraout_r1 = (byte)((ushort)*(undefined2 *)((int)&DAT_210006a8 + (uVar1 + 8) * 2) >> 0xd);
  }
  return puVar2;
}


