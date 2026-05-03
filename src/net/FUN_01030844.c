/*
 * Function: FUN_01030844
 * Entry:    01030844
 * Prototype: int __stdcall FUN_01030844(int * param_1, uint param_2)
 */


int FUN_01030844(int *param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r3;
  
  uVar1 = *(ushort *)(param_1 + 1);
  iVar3 = *param_1;
  uVar2 = FUN_0103ac28(param_1);
  if (uVar2 < param_2) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf_simple.c",
                 0x3e,extraout_r3);
    FUN_0103a370();
  }
  *(ushort *)(param_1 + 1) = uVar1 + (short)param_2;
  return iVar3 + (uint)uVar1;
}


