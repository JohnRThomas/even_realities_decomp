/*
 * Function: FUN_0102e610
 * Entry:    0102e610
 * Prototype: undefined __stdcall FUN_0102e610(void)
 */


void FUN_0102e610(void)

{
  undefined4 uVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar2;
  int *piVar3;
  
  uVar1 = FUN_0102e5f8();
  piVar3 = &DAT_0103c0ac;
  uVar2 = extraout_r3;
  do {
    if (piVar3 < (int *)((int)&DAT_0103c0bc + 1)) {
      if (&UNK_0103c0bb < piVar3) {
        return;
      }
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_core.c"
                   ,0x1d1,uVar2);
      FUN_0103a370();
    }
    uVar2 = 0;
    if ((*(char *)(piVar3[1] + 5) != '\0') && (uVar2 = 0, *(code **)(*piVar3 + 4) != (code *)0x0)) {
      (**(code **)(*piVar3 + 4))(piVar3,uVar1);
      uVar2 = extraout_r3_00;
    }
    piVar3 = piVar3 + 4;
  } while( true );
}


