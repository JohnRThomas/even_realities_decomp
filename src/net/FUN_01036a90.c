/*
 * Function: FUN_01036a90
 * Entry:    01036a90
 * Prototype: int * __stdcall FUN_01036a90(int * param_1, int param_2, uint param_3, int * param_4)
 */


int * FUN_01036a90(int *param_1,int param_2,uint param_3,int *param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 extraout_r3;
  int iVar4;
  uint uVar5;
  undefined4 extraout_r3_00;
  uint *unaff_r6;
  int unaff_r9;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if ((uVar3 == 0) || ((param_3 | (uint)param_4) == 0)) {
    unaff_r6 = (uint *)(param_1 + 2);
    unaff_r9 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      unaff_r9 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc(unaff_r6);
    if (bVar1) goto LAB_01036ae6;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
  }
  else {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/msg_q.c",0xd2,
                 param_3 | (uint)param_4);
  }
LAB_01036ae2:
  do {
    FUN_0103a370();
LAB_01036ae6:
    FUN_01036904(unaff_r6);
    iVar4 = DAT_21004b30;
    if (param_1[9] == 0) {
      if (param_3 != 0 || param_4 != (int *)0x0) {
        *(int *)(DAT_21004b30 + 0x14) = param_2;
        piVar2 = (int *)FUN_01037d78(unaff_r6,unaff_r9,param_1,iVar4,param_3,(int)param_4);
        return piVar2;
      }
      param_4 = (int *)0xffffffdd;
    }
    else {
      FUN_0103bdd4(param_2,(undefined1 *)param_1[7],param_1[3]);
      iVar4 = param_1[7];
      param_1[7] = iVar4 + param_1[3];
      if (iVar4 + param_1[3] == param_1[6]) {
        param_1[7] = param_1[5];
      }
      param_1[9] = param_1[9] + -1;
      param_4 = FUN_01038194(param_1);
      if (param_4 != (int *)0x0) {
        uVar3 = param_1[8];
        uVar5 = param_1[5];
        if ((uVar5 <= uVar3) && (uVar5 = param_1[6], uVar3 < uVar5)) {
          FUN_0103bdd4(uVar3,(undefined1 *)param_4[5],param_1[3]);
          iVar4 = param_1[8];
          param_1[8] = iVar4 + param_1[3];
          if (iVar4 + param_1[3] == param_1[6]) {
            param_1[8] = param_1[5];
          }
          param_1[9] = param_1[9] + 1;
          param_4[0x24] = 0;
          FUN_0103781c(param_4);
          FUN_010378f0(unaff_r6,unaff_r9);
          return (int *)0x0;
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/msg_q.c",0xeb,
                     uVar5);
        goto LAB_01036ae2;
      }
    }
    bVar1 = FUN_010368e8(unaff_r6);
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(unaff_r9);
      }
      InstructionSynchronizationBarrier(0xf);
      return param_4;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  } while( true );
}


