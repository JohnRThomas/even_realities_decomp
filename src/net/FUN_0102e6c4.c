/*
 * Function: FUN_0102e6c4
 * Entry:    0102e6c4
 * Prototype: uint __stdcall FUN_0102e6c4(void)
 */


uint FUN_0102e6c4(void)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  
LAB_0102d5de:
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
  bVar2 = FUN_010368cc((uint *)&DAT_21000880);
  uVar3 = (uint)bVar2;
  uVar5 = uVar3;
  if (uVar3 != 0) goto LAB_0102d60a;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
               0x72,extraout_r3);
  do {
    FUN_0103a370();
    uVar5 = uVar3;
LAB_0102d60a:
    FUN_01036904((uint *)&DAT_21000880);
    if (((DAT_2100087c & 8) != 0) || (uVar3 = DAT_21000870, DAT_21000870 < DAT_21000874)) {
      uVar3 = DAT_21000890;
    }
    if (uVar3 == DAT_21000874) {
      uVar3 = 0;
      uVar8 = uVar3;
    }
    else {
      bVar1 = *(byte *)(DAT_2100088c + DAT_21000874 * 4);
      uVar7 = DAT_2100088c + DAT_21000874 * 4;
      uVar3 = bVar1 & 3;
      uVar8 = uVar3;
      if ((bVar1 & 3) != 0) {
        uVar8 = uVar7;
        if ((uVar3 != 2) || (uVar3 = *(uint *)(DAT_2100088c + DAT_21000874 * 4) >> 2, uVar3 == 0)) {
          if ((int)((uint)bVar1 << 0x1f) < 0) {
            *(byte *)(DAT_2100088c + DAT_21000874 * 4) = bVar1 | 2;
            uVar3 = DAT_21000874;
            iVar4 = (*DAT_21000888)(uVar7);
            DAT_21000874 = FUN_0103a3e0(0x2100086c,uVar3,iVar4);
            uVar3 = 0;
            goto LAB_0102d664;
          }
          uVar3 = (*DAT_21000888)(uVar7);
        }
        DAT_21000874 = FUN_0103a3e0(0x2100086c,DAT_21000874,uVar3);
        FUN_0103a3fc(0x2100086c,uVar3);
        uVar3 = uVar5;
      }
    }
LAB_0102d664:
    bVar2 = FUN_010368e8((uint *)&DAT_21000880);
    if (bVar2) break;
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0xf0,extraout_r3_00);
  } while( true );
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  if (uVar3 == 0) {
    return uVar8;
  }
  goto LAB_0102d5de;
}


