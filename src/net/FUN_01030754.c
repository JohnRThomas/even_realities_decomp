/*
 * Function: FUN_01030754
 * Entry:    01030754
 * Prototype: undefined __stdcall FUN_01030754(uint * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01030754(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint *puVar1;
  char cVar2;
  uint *unaff_r4;
  uint unaff_r6;
  undefined *unaff_r7;
  int unaff_r8;
  
  if (param_1 == (uint *)0x0) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/subsys/net/buf.c",0x1d3,
                 param_4);
    puVar1 = (uint *)FUN_0103a370();
    goto LAB_010307be;
  }
  unaff_r6 = 0;
  unaff_r8 = 0x34;
  unaff_r7 = &DAT_21000994;
  unaff_r4 = param_1;
  do {
    param_1 = (uint *)unaff_r4[1];
    cVar2 = (char)unaff_r4[2] + -1;
    *(char *)(unaff_r4 + 2) = cVar2;
    if (cVar2 != '\0') {
      return;
    }
    if (unaff_r4[5] != 0) {
      if (-1 < (int)((uint)*(byte *)((int)unaff_r4 + 9) << 0x1f)) {
        (**(code **)(**(int **)(unaff_r7 + unaff_r8 * (uint)*(byte *)((int)unaff_r4 + 10) + 0x2c) +
                    8))(unaff_r4);
      }
      unaff_r4[5] = unaff_r6;
    }
    unaff_r4[3] = unaff_r6;
    puVar1 = (uint *)(unaff_r7 + unaff_r8 * (uint)*(byte *)((int)unaff_r4 + 10));
    unaff_r4[1] = unaff_r6;
    if ((code *)puVar1[10] == (code *)0x0) {
LAB_010307be:
      FUN_0103b9d0(puVar1,unaff_r4);
    }
    else {
      (*(code *)puVar1[10])(unaff_r4);
    }
    unaff_r4 = param_1;
  } while (param_1 != (uint *)0x0);
  return;
}


