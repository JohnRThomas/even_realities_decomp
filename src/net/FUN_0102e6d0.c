/*
 * Function: FUN_0102e6d0
 * Entry:    0102e6d0
 * Prototype: undefined __stdcall FUN_0102e6d0(uint * param_1)
 */


void FUN_0102e6d0(uint *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint *puVar5;
  undefined4 uVar6;
  
  iVar1 = DAT_2100465c;
  iVar3 = (**(code **)(DAT_2100465c + 0x1c))(param_1);
  puVar5 = (uint *)(iVar1 + 0x14);
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc(puVar5);
  if (bVar2) goto LAB_0102d6fe;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_0102d6fe:
    FUN_01036904(puVar5);
    *(byte *)param_1 = (byte)*param_1 & 0xfe;
    if ((*(int *)(iVar1 + 0x10) << 0x1e < 0) &&
       (param_1 != (uint *)(*(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0xc) * 4))) {
      *param_1 = *param_1 & 3 | iVar3 << 2;
    }
    else {
      *(byte *)param_1 = (byte)*param_1 & 0xfd;
      if (*(int *)(iVar1 + 0xc) == *(int *)(iVar1 + 8)) {
        uVar4 = FUN_0103a3e0(iVar1,*(int *)(iVar1 + 0xc),iVar3);
        *(uint *)(iVar1 + 8) = uVar4;
      }
      FUN_0103a3fc(iVar1,iVar3);
    }
    bVar2 = FUN_010368e8(puVar5);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  FUN_01036fe4((int *)(iVar1 + 0x2c));
  return;
}


