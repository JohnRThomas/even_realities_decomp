/*
 * Function: FUN_01036f34
 * Entry:    01036f34
 * Prototype: uint * __stdcall FUN_01036f34(uint * param_1, undefined4 param_2, uint param_3, uint param_4)
 */


uint * FUN_01036f34(uint *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r3;
  uint uVar3;
  undefined4 extraout_r3_00;
  uint *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  
  puVar5 = param_1 + 2;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc(puVar5);
  if (bVar1) goto LAB_01036f6c;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01036f6c:
    FUN_01036904(puVar5);
    puVar4 = (uint *)*param_1;
    if (puVar4 == (uint *)0x0) {
      puVar4 = (uint *)0x0;
      if ((param_3 | param_4) != 0) {
        iVar2 = FUN_01037d78(puVar5,uVar6,(int *)(param_1 + 3),param_3 | param_4,param_3,param_4);
        if (iVar2 != 0) {
          return (uint *)0x0;
        }
        return *(uint **)(DAT_21004b30 + 0x14);
      }
    }
    else {
      uVar3 = *puVar4;
      *param_1 = uVar3 & 0xfffffffc;
      if (puVar4 == (uint *)param_1[1]) {
        param_1[1] = uVar3 & 0xfffffffc;
      }
      puVar4 = FUN_0103b9a2(puVar4,1);
    }
    bVar1 = FUN_010368e8(puVar5);
    if (bVar1) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return puVar4;
}


