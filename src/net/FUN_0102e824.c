/*
 * Function: FUN_0102e824
 * Entry:    0102e824
 * Prototype: undefined __stdcall FUN_0102e824(void)
 */


/* WARNING: Removing unreachable block (ram,0x0102e832) */

void FUN_0102e824(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 uVar4;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar5;
  bool bVar6;
  int *piVar7;
  uint uVar8;
  uint uVar9;
  
LAB_0102e848:
  uVar2 = FUN_0102e4b4(0,0);
  if (uVar2 == 0) {
    uVar8 = 0xffffffff;
    uVar9 = 0xffffffff;
  }
  else {
    uVar8 = 0x667;
    uVar9 = 0;
  }
  iVar3 = FUN_0103be10();
  DAT_21004660 = *(int *)(iVar3 + 8);
  if ((DAT_21004660 != 0) && (9 < DAT_21004668)) {
    FUN_01036fe4((int *)&DAT_21000944);
  }
  bVar1 = false;
  do {
    do {
      bVar6 = bVar1;
      if ((uVar2 != 0) && (uVar2 = FUN_0102e450(uVar2), uVar2 == 0)) {
        uVar8 = 0xffffffff;
        uVar9 = 0xffffffff;
      }
      bVar1 = FUN_0102e6ec();
    } while (bVar1);
    uVar4 = extraout_r1;
    if (bVar6 != false) {
      piVar7 = &DAT_0103c0ac;
      uVar5 = extraout_r3;
      while( true ) {
        if (&DAT_0103c0bc < piVar7) {
          FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                       "WEST_TOPDIR/zephyr/subsys/logging/log_core.c",0x350,uVar5);
          FUN_0103a370();
          goto LAB_0102e848;
        }
        if (&UNK_0103c0bb < piVar7) break;
        uVar5 = 0;
        if (*(code **)(*piVar7 + 0x18) != (code *)0x0) {
          (**(code **)(*piVar7 + 0x18))(piVar7,0);
          uVar4 = extraout_r1_00;
          uVar5 = extraout_r3_00;
        }
        piVar7 = piVar7 + 4;
      }
    }
    FUN_0103705c((int *)&DAT_21000944,uVar4,uVar8,uVar9);
  } while( true );
}


