/*
 * Function: FUN_0102d240
 * Entry:    0102d240
 * Prototype: uint __stdcall FUN_0102d240(int * param_1, undefined4 * param_2)
 */


uint FUN_0102d240(int *param_1,undefined4 *param_2)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 *puVar5;
  undefined4 *extraout_r3_01;
  uint unaff_r6;
  uint *puVar6;
  undefined4 uVar7;
  
  uVar4 = FUN_0103a2d6((int)param_1,(int)param_2);
  if (-1 < (int)uVar4) {
    puVar6 = (uint *)(param_1 + 5);
    uVar7 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar7 = getBasePriority();
    }
    bVar2 = (bool)isCurrentModePrivileged();
    if ((bVar2) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar2 = FUN_010368cc(puVar6);
    if (bVar2) {
      FUN_01036904(puVar6);
      uVar1 = *(ushort *)((int)param_1 + 0x1e);
      uVar4 = *(ushort *)(param_1 + 7) & 7;
      unaff_r6 = uVar4;
      if (uVar1 == 0xffff) {
        uVar4 = 0xfffffff5;
        goto LAB_0102d2ca;
      }
      if (uVar4 == 2) {
        *(ushort *)((int)param_1 + 0x1e) = uVar1 + 1;
        bVar2 = true;
        goto LAB_0102d29e;
      }
      switch(uVar4) {
      case 0:
      case 4:
      case 6:
        *param_2 = 0;
        puVar5 = (undefined4 *)param_1[1];
        if (puVar5 != (undefined4 *)0x0) goto LAB_0102d2f8;
        *param_1 = (int)param_2;
        param_1[1] = (int)param_2;
        goto LAB_0102d2dc;
      case 1:
        uVar4 = 0xfffffffb;
        goto LAB_0102d2ca;
      default:
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x1c8,
                     (uint)uVar1);
        break;
      case 5:
        uVar4 = 0xffffff7a;
        goto LAB_0102d2ca;
      }
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
    while( true ) {
      FUN_0103a370();
      puVar5 = extraout_r3_01;
      uVar4 = unaff_r6;
LAB_0102d2f8:
      *puVar5 = param_2;
      param_1[1] = (int)param_2;
LAB_0102d2dc:
      unaff_r6 = uVar4;
      if (uVar4 == 0) {
        FUN_0102ceb8(param_1,2,uVar7);
        return 0;
      }
LAB_0102d2ca:
      bVar2 = false;
LAB_0102d29e:
      bVar3 = FUN_010368e8(puVar6);
      if (bVar3) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0xf0,extraout_r3_00);
    }
    bVar3 = (bool)isCurrentModePrivileged();
    if (bVar3) {
      setBasePriority(uVar7);
    }
    InstructionSynchronizationBarrier(0xf);
    if (bVar2) {
      FUN_0103a2f6(param_1,(int)param_2,unaff_r6,0);
    }
  }
  return uVar4;
}


