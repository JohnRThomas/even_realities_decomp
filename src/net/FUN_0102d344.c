/*
 * Function: FUN_0102d344
 * Entry:    0102d344
 * Prototype: int __stdcall FUN_0102d344(int * param_1, int param_2)
 */


int FUN_0102d344(int *param_1,int param_2)

{
  int *piVar1;
  int extraout_r1;
  uint uVar2;
  
  uVar2 = param_1[1] & 3;
  param_1[2] = param_2;
  if (uVar2 == 2) {
    piVar1 = (int *)*param_1;
    param_1[1] = 0;
    if (piVar1 == (int *)0x0) {
      return 0;
    }
  }
  else {
    if (uVar2 == 3) {
      param_1[1] = 0;
      return *param_1;
    }
    if (uVar2 == 1) {
      param_1[1] = 0;
      return 0;
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/notify.c",0x45,
                 param_1);
    piVar1 = (int *)FUN_0103a370();
    param_2 = extraout_r1;
  }
  FUN_01039088(piVar1,param_2);
  return 0;
}


