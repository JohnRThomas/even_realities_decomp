/*
 * Function: FUN_01038c68
 * Entry:    01038c68
 * Prototype: int __stdcall FUN_01038c68(int * param_1, int param_2, char * param_3, int param_4)
 */


int FUN_01038c68(int *param_1,int param_2,char *param_3,int param_4)

{
  bool bVar1;
  int *piVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar4 = 0;
  iVar5 = 0;
  do {
    if (param_2 <= iVar4) {
      return iVar5;
    }
    uVar6 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar6 = getBasePriority();
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if ((bVar1) && (uVar3 = getBasePriority(), uVar3 == 0 || 0x40 < uVar3)) {
      setBasePriority(0x40);
    }
    InstructionSynchronizationBarrier(0xf);
    bVar1 = FUN_010368cc((uint *)&DAT_21004b78);
    if (bVar1) {
      FUN_01036904((uint *)&DAT_21004b78);
      uVar3 = *(byte *)((int)param_1 + 0xd) & 0x3f;
      switch(uVar3) {
      case 0:
        break;
      case 1:
        if (*(int *)(param_1[4] + 8) != 0) {
          uVar3 = 1;
          goto LAB_01038cdc;
        }
        break;
      case 2:
        if (*(int *)(param_1[4] + 8) != 0) {
          uVar3 = 2;
          goto LAB_01038cdc;
        }
        break;
      default:
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",99,uVar3)
        ;
        goto LAB_01038d6a;
      case 4:
        if (*(int *)param_1[4] != 0) goto LAB_01038d6e;
        break;
      case 8:
        if (*(int *)(param_1[4] + 0x24) != 0) {
          uVar3 = 0x10;
          goto LAB_01038cdc;
        }
      }
      if (param_4 != 0) goto LAB_01038cf6;
      if (*param_3 == '\0') goto LAB_01038cf6;
      uVar3 = *(byte *)((int)param_1 + 0xd) & 0x3f;
      switch(uVar3) {
      case 0:
        goto switchD_01038d32_caseD_0;
      case 1:
        piVar2 = (int *)param_1[4];
        if (piVar2 != (int *)0x0) {
LAB_01038d8c:
          FUN_0103bba0(piVar2,param_1,(int)param_3);
switchD_01038d32_caseD_0:
          param_1[2] = (int)param_3;
          iVar5 = iVar5 + 1;
          goto LAB_01038cf6;
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x95,
                     uVar3);
        break;
      case 2:
        if (param_1[4] != 0) {
          piVar2 = (int *)(param_1[4] + 0x10);
          goto LAB_01038d8c;
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x8d,
                     uVar3);
        break;
      default:
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0xa6,
                     uVar3);
        break;
      case 4:
        if (param_1[4] != 0) {
          piVar2 = (int *)(param_1[4] + 0x14);
          goto LAB_01038d8c;
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x91,
                     uVar3);
        break;
      case 8:
        if (param_1[4] != 0) {
          piVar2 = (int *)(param_1[4] + 0x28);
          goto LAB_01038d8c;
        }
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/poll.c",0x99,
                     uVar3);
      }
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0x72,extraout_r3);
    }
LAB_01038d6a:
    while( true ) {
      FUN_0103a370();
LAB_01038d6e:
      uVar3 = 4;
LAB_01038cdc:
      param_1[2] = 0;
      param_1[3] = param_1[3] & 0xffe03fffU | (uVar3 | (uint)(param_1[3] << 0xb) >> 0x19) << 0xe;
      *param_3 = '\0';
LAB_01038cf6:
      bVar1 = FUN_010368e8((uint *)&DAT_21004b78);
      param_1 = param_1 + 5;
      if (bVar1) break;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/include/zephyr/spinlock.h"
                   ,0xf0,extraout_r3_00);
    }
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar6);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar4 = iVar4 + 1;
  } while( true );
}


