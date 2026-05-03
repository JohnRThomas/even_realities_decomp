/*
 * Function: FUN_0103874c
 * Entry:    0103874c
 * Prototype: undefined __stdcall FUN_0103874c(undefined4 * param_1, undefined4 param_2, uint param_3, int param_4)
 */


void FUN_0103874c(undefined4 *param_1,undefined4 param_2,uint param_3,int param_4)

{
  bool bVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  undefined4 extraout_r3;
  int iVar5;
  undefined4 extraout_r3_00;
  undefined4 *puVar6;
  undefined4 uVar7;
  
  if (param_4 == -1 && param_3 == 0xffffffff) {
    return;
  }
  puVar6 = (undefined4 *)*param_1;
  puVar2 = param_1;
  if (puVar6 == (undefined4 *)0x0) goto LAB_0103877a;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/timeout.c",0x6e,param_4
              );
  do {
    while( true ) {
      puVar2 = (undefined4 *)FUN_0103a370();
      param_2 = extraout_r1;
LAB_0103877a:
      puVar2[2] = param_2;
      uVar7 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar7 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar1 = FUN_010368cc((uint *)&DAT_21004b70);
      if (bVar1) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    FUN_01036904((uint *)&DAT_21004b70);
    if ((int)((param_4 + 1) - (uint)(param_3 != 0xffffffff)) < 0 ==
        (SBORROW4(param_4,-1) != SBORROW4(param_4 + 1,(uint)(param_3 != 0xffffffff)))) {
      uVar3 = FUN_010386c0();
      param_4 = param_4 + (uint)(0xfffffffe < param_3);
      iVar5 = param_3 + 1 + uVar3;
      puVar2 = (undefined4 *)(param_4 + ((int)uVar3 >> 0x1f) + (uint)CARRY4(param_3 + 1,uVar3));
    }
    else {
      iVar5 = (-DAT_210044f0 - 2) - param_3;
      puVar2 = (undefined4 *)
               ((((-1 - DAT_210044f4) - (uint)(0xfffffffe < DAT_210044f0)) - param_4) -
               (uint)(-DAT_210044f0 - 2 < param_3));
      if ((int)puVar2 < (int)(uint)(iVar5 == 0)) {
        iVar5 = 1;
        puVar2 = puVar6;
      }
    }
    param_1[4] = iVar5;
    param_1[5] = puVar2;
    puVar2 = DAT_21000754;
    if ((undefined4 **)DAT_21000750 != &DAT_21000750) {
      puVar6 = DAT_21000750;
    }
    for (; puVar6 != (undefined4 *)0x0; puVar6 = (undefined4 *)*puVar6) {
      uVar3 = puVar6[4];
      param_4 = puVar6[5];
      uVar4 = param_1[4];
      iVar5 = param_1[5];
      if ((int)((iVar5 - param_4) - (uint)(uVar4 < uVar3)) < 0 !=
          (SBORROW4(iVar5,param_4) != SBORROW4(iVar5 - param_4,(uint)(uVar4 < uVar3)))) {
        puVar2 = (undefined4 *)puVar6[1];
        param_4 = (param_4 - iVar5) - (uint)(uVar3 < uVar4);
        puVar6[4] = uVar3 - uVar4;
        puVar6[5] = param_4;
        *param_1 = puVar6;
        param_1[1] = puVar2;
        *puVar2 = param_1;
        puVar6[1] = param_1;
        goto LAB_01038836;
      }
      param_1[4] = uVar4 - uVar3;
      param_1[5] = (iVar5 - param_4) - (uint)(uVar4 < uVar3);
      if (puVar6 == puVar2) break;
    }
    *param_1 = &DAT_21000750;
    param_1[1] = puVar2;
    *puVar2 = param_1;
    DAT_21000754 = param_1;
LAB_01038836:
    if (((undefined4 **)DAT_21000750 != &DAT_21000750) && (param_1 == DAT_21000750)) {
      uVar3 = FUN_010386d4();
      FUN_01031f1c(uVar3);
    }
    bVar1 = FUN_010368e8((uint *)&DAT_21004b70);
    if (bVar1) {
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar7);
      }
      InstructionSynchronizationBarrier(0xf);
      return;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  } while( true );
}


