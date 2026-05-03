/*
 * Function: FUN_0103b984
 * Entry:    0103b984
 * Prototype: bool __stdcall FUN_0103b984(int * param_1, int param_2)
 */


bool FUN_0103b984(int *param_1,int param_2)

{
  char cVar1;
  int *piVar2;
  bool bVar3;
  bool bVar4;
  int extraout_r1;
  int iVar5;
  undefined4 extraout_r3;
  uint uVar6;
  undefined4 extraout_r3_00;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 uVar9;
  
  if (*(char *)((int)param_1 + 0xe) == param_2) {
    return false;
  }
  uVar9 = 0;
  bVar3 = (bool)isCurrentModePrivileged();
  if (bVar3) {
    uVar9 = getBasePriority();
  }
  bVar3 = (bool)isCurrentModePrivileged();
  if ((bVar3) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar3 = FUN_010368cc((uint *)&DAT_21004b68);
  if (!bVar3) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
    goto LAB_01037ea4;
  }
  FUN_01036904((uint *)&DAT_21004b68);
  cVar1 = (char)param_2;
  param_2 = (int)cVar1;
  if ((*(byte *)((int)param_1 + 0xd) & 0x1f) != 0) goto LAB_01037ea8;
  if (param_1[6] != 0) goto LAB_01037ea8;
  uVar6 = *(byte *)((int)param_1 + 0xd) & 0x7f;
  *(char *)((int)param_1 + 0xd) = (char)uVar6;
  FUN_01037b1c(&DAT_21004b40,param_1,0,uVar6);
  *(char *)((int)param_1 + 0xe) = cVar1;
  *(byte *)((int)param_1 + 0xd) = *(byte *)((int)param_1 + 0xd) | 0x80;
  piVar2 = DAT_21004b44;
  if (param_1 == (int *)&DAT_210043a8) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0xc1,
                 &DAT_210043a8);
    goto LAB_01037ea4;
  }
  puVar7 = (undefined4 *)&DAT_21004b28;
  iVar5 = extraout_r1;
  piVar8 = (int *)0x0;
  if ((int **)DAT_21004b40 != &DAT_21004b40) {
    piVar8 = DAT_21004b40;
  }
  for (; piVar8 != (int *)0x0; piVar8 = (int *)*piVar8) {
    iVar5 = (int)*(char *)((int)piVar8 + 0xe);
    if ((param_2 != iVar5) && (param_2 < iVar5)) {
      puVar7 = (undefined4 *)piVar8[1];
      *param_1 = (int)piVar8;
      param_1[1] = (int)puVar7;
      *puVar7 = param_1;
      piVar8[1] = (int)param_1;
      goto LAB_01037ef2;
    }
    if (DAT_21004b44 == piVar8) break;
  }
  *param_1 = (int)&DAT_21004b40;
  param_1[1] = (int)DAT_21004b44;
  *DAT_21004b44 = (int)param_1;
  DAT_21004b44 = param_1;
LAB_01037ef2:
  FUN_01037734(1,iVar5,piVar2,puVar7);
  while (bVar4 = FUN_010368e8((uint *)&DAT_21004b68), !bVar4) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
LAB_01037ea4:
    FUN_0103a370();
LAB_01037ea8:
    bVar3 = false;
    *(char *)((int)param_1 + 0xe) = (char)param_2;
  }
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    setBasePriority(uVar9);
  }
  InstructionSynchronizationBarrier(0xf);
  return bVar3;
}


