/*
 * Function: FUN_0102ae78
 * Entry:    0102ae78
 * Prototype: int * __stdcall FUN_0102ae78(undefined1 * param_1)
 */


int * FUN_0102ae78(undefined1 *param_1)

{
  int *piVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined1 auStack_104 [252];
  
  if (DAT_210045c0 == 0) {
    piVar1 = (int *)&DAT_00000001;
  }
  else {
    FUN_0103bdd4((int)auStack_104,param_1,0xfb);
    piVar1 = FUN_01036958((int *)&DAT_210045b0,auStack_104,0,0);
    if ((piVar1 != (int *)0x0) && (0 < DAT_21000580)) {
      FUN_01039ee2((byte *)"en ESB F\n",extraout_r1,extraout_r2,DAT_21000580);
    }
  }
  return piVar1;
}


