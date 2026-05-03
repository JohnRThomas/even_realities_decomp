/*
 * Function: FUN_010357e8
 * Entry:    010357e8
 * Prototype: undefined __stdcall FUN_010357e8(int * param_1)
 */


void FUN_010357e8(int *param_1)

{
  int iVar1;
  int extraout_r1;
  undefined4 *puVar2;
  undefined4 *extraout_r3;
  
  iVar1 = 0xc;
  puVar2 = &DAT_21004af8;
  if ((&DAT_21004b00)[(uint)*(byte *)(param_1 + 1) * 0xc] == '\0') {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_timer.c",0xca,&DAT_21004af8);
    param_1 = (int *)FUN_0103a370();
    iVar1 = extraout_r1;
    puVar2 = extraout_r3;
  }
  *(undefined4 *)(*param_1 + 0x10) = 1;
  *(undefined1 *)((int)puVar2 + iVar1 * (uint)*(byte *)(param_1 + 1) + 8) = 1;
  return;
}


