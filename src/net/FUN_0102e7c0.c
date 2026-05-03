/*
 * Function: FUN_0102e7c0
 * Entry:    0102e7c0
 * Prototype: undefined __stdcall FUN_0102e7c0(void)
 */


void FUN_0102e7c0(void)

{
  bool bVar1;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar2;
  int *piVar3;
  
  if (DAT_21004fad != '\0') {
    return;
  }
  FUN_0102e4b4(1,0);
  piVar3 = &DAT_0103c0ac;
  uVar2 = extraout_r3;
  do {
    if (piVar3 < (int *)((int)&DAT_0103c0bc + 1)) {
      if (&UNK_0103c0bb < piVar3) {
        do {
          bVar1 = FUN_0102e6ec();
        } while (bVar1);
        DAT_21004fad = 1;
        return;
      }
    }
    else {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/logging/log_core.c"
                   ,0x188,uVar2);
      FUN_0103a370();
    }
    uVar2 = 0;
    if (*(char *)(piVar3[1] + 5) != '\0') {
      (**(code **)(*piVar3 + 8))(piVar3);
      uVar2 = extraout_r3_00;
    }
    piVar3 = piVar3 + 4;
  } while( true );
}


