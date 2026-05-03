/*
 * Function: FUN_01036e20
 * Entry:    01036e20
 * Prototype: undefined4 __stdcall FUN_01036e20(uint * param_1, uint * param_2, uint * param_3, int param_4, char param_5)
 */


undefined4 FUN_01036e20(uint *param_1,uint *param_2,uint *param_3,int param_4,char param_5)

{
  bool bVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  uint *puVar5;
  int iVar6;
  
  puVar5 = param_1 + 2;
  iVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    iVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar1 = FUN_010368cc(puVar5);
  if (bVar1) goto LAB_01036e5e;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_01036e5e:
    FUN_01036904(puVar5);
    if (param_5 != '\0') {
      param_2 = (uint *)param_1[1];
    }
    piVar2 = FUN_01038194((int *)(param_1 + 3));
    if (piVar2 != (int *)0x0) {
      piVar2[5] = (int)param_3;
      piVar2[0x24] = 0;
      FUN_0103781c(piVar2);
      goto LAB_01036e84;
    }
    if (param_4 == 0) break;
    puVar3 = FUN_010391b8(0,8,extraout_r2,extraout_r3_00);
    if (puVar3 != (uint *)0x0) {
      puVar3[1] = (uint)param_3;
      *puVar3 = 1;
      param_3 = puVar3;
      goto LAB_01036ecc;
    }
    bVar1 = FUN_010368e8(puVar5);
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(iVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0xfffffff4;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_01);
  }
  *param_3 = 0;
LAB_01036ecc:
  uVar4 = *param_3 & 3;
  if (param_2 == (uint *)0x0) {
    *param_3 = *param_1 | uVar4;
    *param_1 = (uint)param_3;
    if (param_1[1] != 0) goto LAB_01036efc;
  }
  else {
    if (3 < *param_2) {
      *param_3 = *param_2 & 0xfffffffc | uVar4;
      *param_2 = (uint)param_3 | *param_2 & 3;
      goto LAB_01036efc;
    }
    *param_3 = uVar4;
    puVar3 = (uint *)param_1[1];
    if (puVar3 == (uint *)0x0) {
      *param_1 = (uint)param_3;
      param_1[1] = (uint)param_3;
      goto LAB_01036efc;
    }
    *puVar3 = *puVar3 & 3 | (uint)param_3;
  }
  param_1[1] = (uint)param_3;
LAB_01036efc:
  FUN_0103bcb6((int *)(param_1 + 5),4);
LAB_01036e84:
  FUN_010378f0(puVar5,iVar6);
  return 0;
}


