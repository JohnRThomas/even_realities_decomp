/*
 * Function: FUN_010367dc
 * Entry:    010367dc
 * Prototype: undefined __stdcall FUN_010367dc(void)
 */


void FUN_010367dc(void)

{
  longlong lVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar5;
  int extraout_r2;
  int in_r3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  undefined4 extraout_r3_02;
  uint uVar6;
  uint extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  
  puVar7 = &DAT_0103bf80;
  do {
    if (puVar7 < &UNK_0103bfad) {
      puVar10 = puVar7 + 0xb;
      if ((undefined4 *)((int)&DAT_0103bfa8 + 3) < puVar7) {
        FUN_010379dc();
        puVar9 = (undefined4 *)&DAT_00008000;
        uVar6 = extraout_r3;
        for (puVar7 = &DAT_0103bf80; puVar7 < &UNK_0103bfad; puVar7 = puVar7 + 0xb) {
          if ((undefined4 *)((int)&DAT_0103bfa8 + 3) < puVar7) {
            uVar8 = 0;
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              uVar8 = getBasePriority();
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
              setBasePriority(0x40);
            }
            InstructionSynchronizationBarrier(0xf);
            bVar2 = FUN_010368cc((uint *)&DAT_21004b68);
            if (bVar2) {
              FUN_01036904((uint *)&DAT_21004b68);
              uVar6 = (uint)*(byte *)(DAT_21004b30 + 0xf);
              uVar5 = extraout_r1;
              iVar4 = DAT_21004b30;
              if (uVar6 != 0) goto LAB_01037ac2;
              FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",
                           0x3f8,0);
            }
            else {
              FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                           "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72,extraout_r3_02);
            }
            while( true ) {
              while( true ) {
                FUN_0103a370();
                uVar5 = extraout_r1_00;
                iVar4 = extraout_r2;
                uVar6 = extraout_r3_03;
LAB_01037ac2:
                uVar3 = 0;
                bVar2 = (bool)isCurrentModePrivileged();
                if (bVar2) {
                  uVar3 = getCurrentExceptionNumber();
                  uVar3 = uVar3 & 0x1f;
                }
                if (uVar3 == 0) break;
                FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/sched.c",
                             0x3f9,uVar6);
              }
              *(char *)(iVar4 + 0xf) = (char)(uVar6 + 1);
              FUN_01037734(0,uVar5,iVar4,uVar6 + 1);
              bVar2 = FUN_010368e8((uint *)&DAT_21004b68);
              if (bVar2) break;
              FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                           "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0,extraout_r3_04);
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              setBasePriority(uVar8);
            }
            InstructionSynchronizationBarrier(0xf);
            iVar4 = 0;
            bVar2 = (bool)isCurrentModePrivileged();
            if (bVar2) {
              iVar4 = getBasePriority();
            }
            bVar2 = (bool)isCurrentModePrivileged();
            if ((bVar2) && (uVar6 = getBasePriority(), uVar6 == 0 || 0x40 < uVar6)) {
              setBasePriority(0x40);
            }
            InstructionSynchronizationBarrier(0xf);
            FUN_0103ba5c(iVar4);
            return;
          }
          uVar6 = puVar7[9];
          if (uVar6 != 0xffffffff) {
            uVar6 = uVar6 & ~((int)uVar6 >> 0x1f);
            lVar1 = (longlong)(int)uVar6 * 0x8000 + 999;
            uVar3 = (uint)((ulonglong)lVar1 >> 0x20);
            puVar10 = (undefined4 *)*puVar7;
            if (uVar3 == 0 && (uVar6 & 0x1ffff) == 0) {
              FUN_0103795c(puVar10);
              uVar6 = extraout_r3_00;
            }
            else {
              uVar11 = FUN_01008a3c((uint)lVar1,uVar3,1000,0);
              FUN_0103874c(puVar10 + 6,&LAB_0103ba88_1,(uint)uVar11,(int)((ulonglong)uVar11 >> 0x20)
                          );
              uVar6 = extraout_r3_01;
            }
          }
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/thread.c",0x312,
                     uVar6);
        goto LAB_010367fc;
      }
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/thread.c",0x2f3,
                   in_r3);
      puVar9 = puVar7;
LAB_010367fc:
      FUN_0103a370();
      puVar10 = puVar7;
      puVar7 = puVar9;
    }
    FUN_0103669c(puVar10[-0xb],puVar10[-10],puVar10[-9],puVar10[-8],puVar10[-7],puVar10[-6],
                 puVar10[-5],puVar10[-4],(char)puVar10[-3]);
    in_r3 = puVar10[-0xb];
    *(undefined4 **)(in_r3 + 0x54) = puVar7;
    puVar7 = puVar10;
  } while( true );
}


