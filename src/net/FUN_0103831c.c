/*
 * Function: FUN_0103831c
 * Entry:    0103831c
 * Prototype: int __stdcall FUN_0103831c(uint param_1, int param_2)
 */


int FUN_0103831c(uint param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  undefined4 extraout_r1;
  uint uVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  int iVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  
  uVar3 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  if (uVar3 == 0) {
    if (param_1 == 0 && param_2 == 0) {
      FUN_01038220();
      return 0;
    }
    uVar3 = param_1;
    if ((int)((param_2 + 1) - (uint)(param_1 < 0xfffffffe)) < 0 !=
        (SBORROW4(param_2,-1) != SBORROW4(param_2 + 1,(uint)(param_1 < 0xfffffffe))))
    goto LAB_01038384;
    uVar6 = FUN_0103bab8();
    uVar3 = param_1 + (int)uVar6;
    do {
      uVar5 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar5 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar1 = getBasePriority(), uVar1 == 0 || 0x40 < uVar1)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
      if (bVar2) {
        FUN_01036904((uint *)&DAT_21004b68);
        DAT_21004b5c = DAT_21004b30;
        FUN_01037c9c(DAT_21004b30,extraout_r1);
        FUN_0103874c(DAT_21004b30 + 6,&LAB_0103ba88_1,param_1,param_2);
        *(byte *)((int)DAT_21004b30 + 0xd) = *(byte *)((int)DAT_21004b30 + 0xd) | 0x10;
        bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
        if (bVar2) {
          FUN_0102f3d0(uVar5);
          iVar4 = (uint)*(byte *)((int)DAT_21004b30 + 0xd) << 0x1b;
          if (-1 < iVar4) {
            uVar6 = FUN_0103bab8();
            iVar4 = uVar3 - (uint)uVar6;
            if ((int)-(uint)(uVar3 < (uint)uVar6) < (int)(uint)(iVar4 == 0)) {
              return 0;
            }
            return iVar4;
          }
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x5b2,
                       iVar4);
        }
        else {
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                       "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x111,extraout_r3_00);
        }
      }
      else {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72,extraout_r3);
      }
LAB_01038380:
      uVar3 = FUN_0103a370();
LAB_01038384:
      uVar3 = -uVar3 - 2;
    } while( true );
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",0x596,uVar3);
  goto LAB_01038380;
}


