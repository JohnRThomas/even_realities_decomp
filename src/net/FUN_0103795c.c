/*
 * Function: FUN_0103795c
 * Entry:    0103795c
 * Prototype: undefined __stdcall FUN_0103795c(undefined4 * param_1)
 */


void FUN_0103795c(undefined4 *param_1)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int iVar3;
  
  iVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar3 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
  if (bVar2) goto LAB_0103798a;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_0103798a:
    FUN_01036904((uint *)&DAT_21004b68);
    if ((int)((uint)*(byte *)((int)param_1 + 0xd) << 0x1d) < 0) break;
    bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(iVar3);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) & 0xfb;
  FUN_0103778c(param_1);
  FUN_010378f0((uint *)&DAT_21004b68,iVar3);
  return;
}


