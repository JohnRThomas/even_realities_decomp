/*
 * Function: FUN_0102d398
 * Entry:    0102d398
 * Prototype: undefined __stdcall FUN_0102d398(undefined1 * param_1, undefined4 * param_2)
 */


void FUN_0102d398(undefined1 *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 extraout_r3;
  
  FUN_0103bdee(param_1,0,0x20);
  *(undefined4 *)(param_1 + 0x1c) = param_2[3];
  *(undefined4 *)(param_1 + 0x18) = param_2[2];
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  uVar3 = param_2[1];
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(uint *)(param_1 + 0x24) = uVar3;
  uVar2 = param_2[4];
  if ((uVar3 != 0) && ((uVar3 - 1 & uVar3) == 0)) {
    uVar2 = uVar2 | 1;
  }
  *(uint *)(param_1 + 0x10) = uVar2;
  iVar1 = FUN_0103b9e4((int)(param_1 + 0x2c),0,1);
  if (iVar1 != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/mpsc_pbuf.c",0x2e,
                 extraout_r3);
    FUN_0103a370();
  }
  return;
}


