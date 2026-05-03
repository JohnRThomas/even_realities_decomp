/*
 * Function: FUN_01036958
 * Entry:    01036958
 * Prototype: int * __stdcall FUN_01036958(int * param_1, undefined1 * param_2, uint param_3, uint param_4)
 */


int * FUN_01036958(int *param_1,undefined1 *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  int *piVar2;
  uint uVar3;
  undefined4 extraout_r3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_r3_00;
  uint *unaff_r6;
  int unaff_r7;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if ((uVar3 == 0) || ((param_3 | param_4) == 0)) {
    unaff_r6 = (uint *)(param_1 + 2);
    unaff_r7 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      unaff_r7 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc(unaff_r6);
    if (bVar1) goto LAB_010369ae;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
  }
  else {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/msg_q.c",0x76,
                 param_3 | param_4);
  }
LAB_010369aa:
  do {
    FUN_0103a370();
LAB_010369ae:
    FUN_01036904(unaff_r6);
    iVar5 = DAT_21004b30;
    if ((uint)param_1[9] < (uint)param_1[4]) {
      piVar2 = FUN_01038194(param_1);
      if (piVar2 != (int *)0x0) {
        FUN_0103bdd4(piVar2[5],param_2,param_1[3]);
        piVar2[0x24] = 0;
        FUN_0103781c(piVar2);
        FUN_010378f0(unaff_r6,unaff_r7);
        return (int *)0x0;
      }
      uVar3 = param_1[8];
      uVar4 = param_1[5];
      param_4 = 0;
      if ((uVar3 < uVar4) || (uVar4 = param_1[6], uVar4 <= uVar3)) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/msg_q.c",0x90,
                     uVar4);
        goto LAB_010369aa;
      }
      FUN_0103bdd4(uVar3,param_2,param_1[3]);
      iVar5 = param_1[8];
      param_1[8] = iVar5 + param_1[3];
      if (iVar5 + param_1[3] == param_1[6]) {
        param_1[8] = param_1[5];
      }
      param_1[9] = param_1[9] + 1;
      FUN_0103bcb6(param_1 + 10,0x10);
      param_1 = (int *)0x0;
    }
    else {
      if (param_3 != 0 || param_4 != 0) {
        *(undefined1 **)(DAT_21004b30 + 0x14) = param_2;
        piVar2 = (int *)FUN_01037d78(unaff_r6,unaff_r7,param_1,iVar5,param_3,param_4);
        return piVar2;
      }
      param_1 = (int *)0xffffffdd;
    }
    bVar1 = FUN_010368e8(unaff_r6);
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(unaff_r7);
      }
      InstructionSynchronizationBarrier(0xf);
      return param_1;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  } while( true );
}


