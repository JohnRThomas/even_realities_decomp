/*
 * Function: FUN_0102e6b4
 * Entry:    0102e6b4
 * Prototype: int __stdcall FUN_0102e6b4(uint param_1)
 */


/* WARNING: Removing unreachable block (ram,0x0102d4d6) */
/* WARNING: Removing unreachable block (ram,0x0102d4e0) */
/* WARNING: Removing unreachable block (ram,0x0102d4f6) */
/* WARNING: Removing unreachable block (ram,0x0102d4fa) */
/* WARNING: Removing unreachable block (ram,0x0102d510) */
/* WARNING: Removing unreachable block (ram,0x0102d514) */
/* WARNING: Removing unreachable block (ram,0x0102d518) */
/* WARNING: Removing unreachable block (ram,0x0102d526) */

int FUN_0102e6b4(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  int local_34;
  uint local_30;
  int local_2c [2];
  
  uVar3 = 0;
  iVar5 = 0;
  local_34 = 0;
  local_2c[0] = 0;
  if (param_1 <= DAT_21000890) {
    do {
      uVar6 = 0;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        uVar6 = getBasePriority();
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if ((bVar1) && (uVar4 = getBasePriority(), uVar4 == 0 || 0x40 < uVar4)) {
        setBasePriority(0x40);
      }
      InstructionSynchronizationBarrier(0xf);
      bVar1 = FUN_010368cc((uint *)&DAT_21000880);
      uVar4 = uVar3;
      if (bVar1) goto LAB_0102d440;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
      while( true ) {
        FUN_0103a370();
        uVar4 = uVar3;
LAB_0102d440:
        FUN_01036904((uint *)&DAT_21000880);
        if (local_2c[0] != 0) {
          FUN_0103a540(&DAT_2100086c,uVar4,local_2c[0]);
          local_2c[0] = 0;
        }
        iVar2 = FUN_0103a398(&DAT_2100086c,(int *)&local_30);
        uVar3 = DAT_2100086c;
        if (local_30 < param_1) {
          if (iVar2 == 0) {
            iVar2 = FUN_0103a452(&DAT_2100086c,local_30,&local_34,local_2c);
          }
          else {
            FUN_0103a414(&DAT_2100086c,local_30);
            uVar3 = uVar4;
          }
        }
        else {
          iVar5 = DAT_2100088c + DAT_2100086c * 4;
          *(byte *)(DAT_2100088c + DAT_2100086c * 4) =
               *(byte *)(DAT_2100088c + DAT_2100086c * 4) & 0xfc;
          DAT_2100086c = FUN_0103a3e0(0x2100086c,DAT_2100086c,param_1);
          if (DAT_2100086c == DAT_21000878) {
            DAT_2100087c = DAT_2100087c | 8;
          }
          iVar2 = 0;
          uVar3 = uVar4;
        }
        bVar1 = FUN_010368e8((uint *)&DAT_21000880);
        if (bVar1) break;
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0,extraout_r3_00);
      }
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        setBasePriority(uVar6);
      }
      InstructionSynchronizationBarrier(0xf);
      if (local_34 != 0) {
        if (DAT_21000884 != (code *)0x0) {
          (*DAT_21000884)(&DAT_2100086c);
        }
        local_34 = 0;
      }
    } while (iVar2 != 0);
  }
  return iVar5;
}


