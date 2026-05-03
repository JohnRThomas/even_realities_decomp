/*
 * Function: FUN_01039088
 * Entry:    01039088
 * Prototype: undefined4 __stdcall FUN_01039088(int * param_1, int param_2)
 */


undefined4 FUN_01039088(int *param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int iVar6;
  int iVar7;
  
  iVar7 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    iVar7 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc((uint *)&DAT_21004b78);
  if (bVar2) goto LAB_010390b8;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  while( true ) {
    FUN_0103a370();
LAB_010390b8:
    FUN_01036904((uint *)&DAT_21004b78);
    piVar3 = (int *)*param_1;
    param_1[3] = param_2;
    param_1[2] = 1;
    if (param_1 != piVar3) break;
    bVar2 = FUN_010368e8((uint *)&DAT_21004b78);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(iVar7);
      }
      InstructionSynchronizationBarrier(0xf);
      return 0;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  }
  iVar6 = *piVar3;
  piVar5 = (int *)piVar3[1];
  *piVar5 = iVar6;
  *(int **)(iVar6 + 4) = piVar5;
  *piVar3 = 0;
  piVar3[1] = 0;
  uVar4 = FUN_0103bc02((int)piVar3,1);
  FUN_010378f0((uint *)&DAT_21004b78,iVar7);
  return uVar4;
}


