/*
 * Function: FUN_0102ceb8
 * Entry:    0102ceb8
 * Prototype: undefined __stdcall FUN_0102ceb8(int * param_1, int param_2, undefined4 param_3)
 */


void FUN_0102ceb8(int *param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  uint extraout_r1_02;
  ushort uVar6;
  ushort extraout_r2;
  ushort extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar7;
  undefined4 extraout_r3_03;
  code *pcVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  uint uVar12;
  uint *puVar13;
  
  uVar6 = *(ushort *)(param_1 + 7);
  if ((int)((uint)uVar6 << 0x1c) < 0) {
    if (param_2 == 1) {
      uVar6 = uVar6 | 0x10;
    }
    else {
      uVar6 = uVar6 | 0x20;
    }
    *(ushort *)(param_1 + 7) = uVar6;
    goto LAB_0102cefc;
  }
  uVar5 = uVar6 & 7;
  if (param_2 != 2) goto switchD_0102cee0_caseD_1;
LAB_0102ced0:
  iVar3 = FUN_0103a29e(param_1);
  if (iVar3 == 0) goto LAB_0102cefc;
  uVar5 = extraout_r1;
  uVar7 = extraout_r3;
  switch(iVar3) {
  case 1:
    break;
  default:
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x16b,
                 extraout_r3);
    goto LAB_0102cfdc;
  case 3:
    goto switchD_0102cee0_caseD_3;
  case 4:
    if (extraout_r1 != 2) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x15d,
                   extraout_r3);
      goto LAB_0102cfdc;
    }
    if (*(short *)((int)param_1 + 0x1e) == 0) {
      pcVar8 = *(code **)(param_1[4] + 4);
      if (pcVar8 == (code *)0x0) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x161,
                     param_1[4]);
        goto LAB_0102cfdc;
      }
      uVar6 = *(ushort *)(param_1 + 7) & 0xfff8 | 4;
      uVar12 = 4;
      *(ushort *)(param_1 + 7) = uVar6;
      puVar10 = (undefined4 *)0x0;
      iVar3 = 0;
      goto LAB_0102d038;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x15e,
                 extraout_r3);
    goto LAB_0102cfdc;
  case 5:
    if (extraout_r1 != 1) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x164,
                   extraout_r3);
      goto LAB_0102cfdc;
    }
    if (*param_1 != 0) {
      pcVar8 = *(code **)(param_1[4] + 8);
      if (pcVar8 == (code *)0x0) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x168,
                     param_1[4]);
        goto LAB_0102cfdc;
      }
      puVar10 = (undefined4 *)0x0;
      iVar3 = 0;
      uVar6 = *(ushort *)(param_1 + 7) & 0xfff8 | 5;
      uVar12 = 5;
      *(ushort *)(param_1 + 7) = uVar6;
      goto LAB_0102d038;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x165,0);
    goto LAB_0102cfdc;
  }
switchD_0102cee0_caseD_1:
  iVar3 = param_1[6];
  uVar6 = *(ushort *)(param_1 + 7);
  if (iVar3 < 0) {
    puVar10 = (undefined4 *)*param_1;
    *param_1 = 0;
    param_1[1] = 0;
    *(ushort *)(param_1 + 7) = uVar6 & 0xfff8 | 1;
LAB_0102cfb4:
    uVar6 = *(ushort *)(param_1 + 7);
    uVar12 = uVar6 & 7;
    if (uVar12 != uVar5) {
LAB_0102d136:
      pcVar8 = (code *)0x0;
      goto LAB_0102d038;
    }
    if (puVar10 != (undefined4 *)0x0) {
      pcVar8 = (code *)0x0;
      bVar2 = false;
      goto LAB_0102d048;
    }
  }
  else {
    uVar5 = uVar6 & 7;
    if (uVar5 - 5 < 2) {
      puVar10 = (undefined4 *)*param_1;
      *param_1 = 0;
      param_1[1] = 0;
      puVar11 = puVar10;
      if (uVar5 == 6) {
        for (; puVar11 != (undefined4 *)0x0; puVar11 = (undefined4 *)*puVar11) {
          *(short *)((int)param_1 + 0x1e) = *(short *)((int)param_1 + 0x1e) + 1;
        }
        uVar6 = uVar6 & 0xfff8 | 2;
      }
      else {
        uVar6 = uVar6 & 0xfff8;
      }
      *(ushort *)(param_1 + 7) = uVar6;
      iVar4 = FUN_0103a29e(param_1);
      uVar5 = extraout_r1_00;
      if (iVar4 != 0) {
        *(ushort *)(param_1 + 7) = extraout_r2 | 0x20;
      }
      goto LAB_0102cfb4;
    }
    if (uVar5 != 4) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",0x11b,
                   (uint)uVar6);
      goto LAB_0102cfdc;
    }
    *(ushort *)(param_1 + 7) = uVar6 & 0xfff8;
    iVar4 = FUN_0103a29e(param_1);
    if (iVar4 != 0) {
      *(ushort *)(param_1 + 7) = extraout_r2_00 | 0x20;
    }
    uVar6 = *(ushort *)(param_1 + 7);
    uVar12 = uVar6 & 7;
    if (uVar12 != extraout_r1_01) {
      puVar10 = (undefined4 *)0x0;
      goto LAB_0102d136;
    }
  }
LAB_0102cf84:
  uVar6 = *(ushort *)(param_1 + 7);
  uVar5 = (uint)uVar6;
  if (-1 < (int)(uVar5 << 0x1b)) {
    if (-1 < (int)(uVar5 << 0x1a)) {
LAB_0102cefc:
      bVar2 = FUN_010368e8((uint *)(param_1 + 5));
      uVar7 = extraout_r3_00;
      if (bVar2) {
        bVar2 = (bool)isCurrentModePrivileged();
        if (bVar2) {
          setBasePriority(param_3);
        }
        InstructionSynchronizationBarrier(0xf);
        return;
      }
      do {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0xf0,uVar7);
LAB_0102cfdc:
        while( true ) {
          while( true ) {
            while( true ) {
              while( true ) {
                FUN_0103a370();
                uVar5 = extraout_r1_02;
                uVar7 = extraout_r3_01;
switchD_0102cee0_caseD_3:
                if (uVar5 == 0) break;
                FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",
                             0x156,uVar7);
              }
              if (*param_1 != 0) break;
              FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",
                           0x157,0);
            }
            pcVar8 = *(code **)param_1[4];
            if (pcVar8 != (code *)0x0) break;
            FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/onoff.c",
                         0x15a,(int *)param_1[4]);
          }
          uVar12 = 6;
          uVar6 = *(ushort *)(param_1 + 7) & 0xfff8 | 6;
          *(ushort *)(param_1 + 7) = uVar6;
          puVar10 = (undefined4 *)0x0;
          iVar3 = 0;
LAB_0102d038:
          if (param_1[2] == 0) {
            if (puVar10 == (undefined4 *)0x0) {
              if (pcVar8 == (code *)0x0) goto LAB_0102cf84;
              bVar2 = false;
            }
            else {
              bVar2 = false;
            }
          }
          else {
            bVar2 = true;
          }
LAB_0102d048:
          puVar13 = (uint *)(param_1 + 5);
          *(ushort *)(param_1 + 7) = uVar6 | 8;
          bVar1 = FUN_010368e8(puVar13);
          uVar7 = extraout_r3_02;
          if (!bVar1) break;
          bVar1 = (bool)isCurrentModePrivileged();
          if (bVar1) {
            setBasePriority(param_3);
          }
          InstructionSynchronizationBarrier(0xf);
          if ((bVar2) && (puVar11 = (undefined4 *)param_1[2], puVar11 != (undefined4 *)0x0)) {
            puVar9 = (undefined4 *)*puVar11;
            while (puVar11 != (undefined4 *)0x0) {
              (*(code *)puVar11[1])(param_1,puVar11,uVar12,iVar3);
              puVar11 = puVar9;
              if (puVar9 != (undefined4 *)0x0) {
                puVar9 = (undefined4 *)*puVar9;
              }
            }
          }
          while (puVar10 != (undefined4 *)0x0) {
            puVar11 = (undefined4 *)*puVar10;
            FUN_0103a2f6(param_1,(int)puVar10,uVar12,iVar3);
            puVar10 = puVar11;
          }
          if (pcVar8 != (code *)0x0) {
            (*pcVar8)(param_1,&LAB_0102d1ec_1);
          }
          param_3 = 0;
          bVar2 = (bool)isCurrentModePrivileged();
          if (bVar2) {
            param_3 = getBasePriority();
          }
          bVar2 = (bool)isCurrentModePrivileged();
          if ((bVar2) && (uVar5 = getBasePriority(), uVar5 == 0 || 0x40 < uVar5)) {
            setBasePriority(0x40);
          }
          InstructionSynchronizationBarrier(0xf);
          bVar2 = FUN_010368cc(puVar13);
          if (bVar2) {
            FUN_01036904(puVar13);
            *(ushort *)(param_1 + 7) = *(ushort *)(param_1 + 7) & 0xfff7;
            goto LAB_0102cf84;
          }
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                       "WEST_TOPDIR/zephyr/include/zephyr/spinlock.h",0x72,extraout_r3_03);
        }
      } while( true );
    }
    *(ushort *)(param_1 + 7) = uVar6 & 0xffdf;
    goto LAB_0102ced0;
  }
  *(ushort *)(param_1 + 7) = uVar6 & 0xffef;
  uVar5 = uVar5 & 7;
  goto switchD_0102cee0_caseD_1;
}


