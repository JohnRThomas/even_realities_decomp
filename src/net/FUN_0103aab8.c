/*
 * Function: FUN_0103aab8
 * Entry:    0103aab8
 * Prototype: undefined __stdcall FUN_0103aab8(uint * param_1, uint param_2, uint param_3, undefined1 * param_4)
 */


/* WARNING: Removing unreachable block (ram,0x0102e5dc) */
/* WARNING: Removing unreachable block (ram,0x0102e5de) */

void FUN_0103aab8(uint *param_1,uint param_2,uint param_3,undefined1 *param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar3;
  undefined8 uVar4;
  
  if (param_1 == (uint *)0x0) {
    FUN_0103aa54(&DAT_21004664);
    return;
  }
  if (param_4 != (undefined1 *)0x0) {
    FUN_0103bdd4((int)param_1 + ((param_3 << 0xc) >> 0x15) + 0x10,param_4,param_3 >> 0x14);
  }
  *param_1 = param_3;
  param_1[1] = param_2;
  uVar2 = (*DAT_2100061c)();
  param_1[2] = uVar2;
  FUN_0102d54c(&DAT_2100086c,(byte *)param_1);
  uVar4 = FUN_0103aa54(&DAT_21004668);
  if (DAT_21004fad == '\0') {
    if (DAT_21004660 != 0) {
      if ((int)uVar4 == 0) {
        FUN_01038c08((int *)0x21002790,(int)((ulonglong)uVar4 >> 0x20),0x8000,0,0,0);
      }
      else if ((int)uVar4 == 9) {
        FUN_0103bb66((int *)0x21002790);
        FUN_01036fe4((int *)&DAT_21000944);
        return;
      }
    }
  }
  else {
    uVar3 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar3 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc((uint *)0x21004658);
    if (bVar1) goto LAB_0102e938;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,extraout_r3);
    while( true ) {
      FUN_0103a370();
LAB_0102e938:
      FUN_01036904((uint *)0x21004658);
      FUN_0102e6ec();
      bVar1 = FUN_010368e8((uint *)0x21004658);
      if (bVar1) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0xf0,extraout_r3_00);
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar3);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


