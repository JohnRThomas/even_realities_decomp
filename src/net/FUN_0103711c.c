/*
 * Function: FUN_0103711c
 * Entry:    0103711c
 * Prototype: undefined __stdcall FUN_0103711c(int param_1)
 */


void FUN_0103711c(int param_1)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 extraout_r3;
  undefined4 uVar5;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 *puVar6;
  undefined4 *puVar7;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 uVar10;
  
LAB_01037128:
  do {
    puVar7 = (undefined4 *)0x0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      puVar7 = (undefined4 *)getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc((uint *)&DAT_21004b58);
    uVar5 = extraout_r3;
    if (bVar1) goto LAB_01037152;
LAB_01037140:
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",
                 0x72,uVar5);
LAB_0103714e:
    FUN_0103a370();
LAB_01037152:
    FUN_01036904((uint *)&DAT_21004b58);
    puVar6 = *(undefined4 **)(param_1 + 0x98);
    if (puVar6 != (undefined4 *)0x0) {
      uVar5 = *puVar6;
      if (puVar6 == *(undefined4 **)(param_1 + 0x9c)) {
        *(undefined4 *)(param_1 + 0x9c) = uVar5;
      }
      *(undefined4 *)(param_1 + 0x98) = uVar5;
      *(uint *)(param_1 + 0xb0) = *(uint *)(param_1 + 0xb0) | 2;
      pcVar8 = (code *)puVar6[1];
      puVar6[3] = puVar6[3] & 0xfffffffb | 1;
      bVar1 = FUN_010368e8((uint *)&DAT_21004b58);
      uVar5 = extraout_r3_00;
      if (bVar1) {
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          setBasePriority(puVar7);
        }
        InstructionSynchronizationBarrier(0xf);
        if (pcVar8 == (code *)0x0) {
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x29b,
                       extraout_r3_00);
          goto LAB_0103714e;
        }
        (*pcVar8)(puVar6);
        uVar10 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar10 = getBasePriority();
        }
        bVar1 = (bool)isCurrentModePrivileged();
        if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x40 < uVar2)) {
          setBasePriority(0x40);
        }
        InstructionSynchronizationBarrier(0xf);
        bVar1 = FUN_010368cc((uint *)&DAT_21004b58);
        uVar5 = extraout_r3_01;
        if (!bVar1) goto LAB_01037140;
        FUN_01036904((uint *)&DAT_21004b58);
        puVar3 = DAT_21004b50;
        uVar2 = puVar6[3];
        if ((int)(uVar2 << 0x1e) < 0) {
          puVar6[3] = uVar2 & 0xfffffffc;
          if (puVar3 != (undefined4 *)0x0) {
            puVar7 = (undefined4 *)0x0;
            puVar9 = (undefined4 *)*puVar3;
            while (puVar3 != (undefined4 *)0x0) {
              puVar4 = puVar3;
              if (puVar6 == (undefined4 *)puVar3[1]) {
                puVar4 = (undefined4 *)*puVar3;
                if (puVar7 == (undefined4 *)0x0) {
                  DAT_21004b50 = puVar4;
                  if (DAT_21004b54 == puVar3) {
                    DAT_21004b54 = puVar4;
                  }
                }
                else {
                  *puVar7 = puVar4;
                  if (DAT_21004b54 == puVar3) {
                    DAT_21004b54 = puVar7;
                  }
                }
                *puVar3 = 0;
                FUN_01036fe4(puVar3 + 2);
                puVar4 = puVar7;
              }
              puVar3 = puVar9;
              puVar7 = puVar4;
              if (puVar9 != (undefined4 *)0x0) {
                puVar9 = (undefined4 *)*puVar9;
              }
            }
          }
        }
        else {
          puVar6[3] = uVar2 & 0xfffffffe;
        }
        uVar2 = *(uint *)(param_1 + 0xb0) & 0xfffffffd;
        *(uint *)(param_1 + 0xb0) = uVar2;
        bVar1 = FUN_010368e8((uint *)&DAT_21004b58);
        uVar5 = extraout_r3_02;
        if (bVar1) {
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(uVar10);
          }
          InstructionSynchronizationBarrier(0xf);
          if (-1 < (int)(uVar2 << 0x17)) {
            FUN_01038220();
          }
          goto LAB_01037128;
        }
      }
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0xf0,uVar5);
      goto LAB_0103714e;
    }
    uVar2 = FUN_0103ba04((uint *)(param_1 + 0xb0),2);
    if (uVar2 != 0) {
      do {
        bVar1 = FUN_010385d0((int *)(param_1 + 0xa8),1,0);
      } while (bVar1);
    }
    FUN_01038668((uint *)&DAT_21004b58,puVar7,(int *)(param_1 + 0xa0),0xffffffff,0xffffffff,-1,
                 (undefined4 *)0x0);
  } while( true );
}


