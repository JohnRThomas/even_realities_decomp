/*
 * Function: FUN_010364d8
 * Entry:    010364d8
 * Prototype: uint __stdcall FUN_010364d8(int * param_1, uint param_2, uint param_3, undefined4 param_4, uint param_5, uint param_6)
 */


uint FUN_010364d8(int *param_1,uint param_2,uint param_3,undefined4 param_4,uint param_5,
                 uint param_6)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int extraout_r1;
  int extraout_r1_00;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 uVar5;
  uint extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar6;
  uint *puVar7;
  int *unaff_r11;
  uint local_38;
  uint local_30;
  uint uStack_2c;
  
  puVar7 = (uint *)(param_1 + 5);
  FUN_0103bac4((longlong *)&local_30,param_2,param_5,param_6);
  uVar1 = uStack_2c;
  local_38 = local_30;
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = getBasePriority();
  }
  bVar2 = (bool)isCurrentModePrivileged();
  if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
    setBasePriority(0x40);
  }
  InstructionSynchronizationBarrier(0xf);
  bVar2 = FUN_010368cc(puVar7);
  uVar5 = extraout_r3;
  if (bVar2) {
    FUN_01036904(puVar7);
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = getCurrentExceptionNumber();
      uVar3 = uVar3 & 0x1f;
    }
    if ((uVar3 != 0) && ((param_5 | param_6) != 0)) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/kheap.c",0x4a,
                   param_5 | param_6);
      goto LAB_01036574;
    }
    unaff_r11 = param_1 + 3;
    goto LAB_01036536;
  }
LAB_01036516:
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,uVar5);
LAB_01036574:
  do {
    FUN_0103a370();
    iVar4 = extraout_r1_00;
    uVar3 = extraout_r3_00;
    do {
      bVar2 = param_5 == 0;
      param_5 = 0;
      if (bVar2 && param_6 == 0) break;
      FUN_0103bb0c((int *)&local_30,iVar4,local_38,uVar1);
      param_6 = uStack_2c;
      param_5 = local_30;
      FUN_01037d78(puVar7,uVar6,unaff_r11,uStack_2c,local_30,uStack_2c);
      uVar6 = 0;
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        uVar6 = getBasePriority();
      }
      bVar2 = (bool)isCurrentModePrivileged();
      if ((bVar2) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar2 = FUN_010368cc(puVar7);
      uVar5 = extraout_r3_01;
      if (!bVar2) goto LAB_01036516;
      FUN_01036904(puVar7);
LAB_01036536:
      uVar3 = FUN_0102cca4(param_1,param_2,param_3);
      iVar4 = extraout_r1;
    } while (uVar3 == 0);
    bVar2 = FUN_010368e8(puVar7);
    if (bVar2) {
      bVar2 = (bool)isCurrentModePrivileged();
      if (bVar2) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      return uVar3;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,uVar3);
    local_38 = uVar3;
  } while( true );
}


