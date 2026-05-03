/*
 * Function: FUN_01038424
 * Entry:    01038424
 * Prototype: uint __stdcall FUN_01038424(uint param_1, int param_2)
 */


uint FUN_01038424(uint param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int extraout_r1;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if (uVar3 != 0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x5c1,uVar3)
    ;
    param_1 = FUN_0103a370();
    param_2 = extraout_r1;
  }
  if (param_2 == -1 && param_1 == 0xffffffff) {
    FUN_01037f28(DAT_21004b30);
    uVar3 = 0xffffffff;
  }
  else {
    iVar2 = FUN_0103831c(param_1,param_2);
    uVar3 = (uint)((longlong)iVar2 * 1000) >> 0xf |
            (int)((ulonglong)((longlong)iVar2 * 1000) >> 0x20) << 0x11;
  }
  return uVar3;
}


