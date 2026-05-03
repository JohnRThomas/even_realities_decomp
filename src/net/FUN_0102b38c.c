/*
 * Function: FUN_0102b38c
 * Entry:    0102b38c
 * Prototype: int __stdcall FUN_0102b38c(undefined4 param_1, undefined4 param_2)
 */


int FUN_0102b38c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  
  if (DAT_21004600 == 1) {
    iVar1 = FUN_0102ddd8((int *)&DAT_210045f8,param_1,param_2);
    if ((iVar1 < 0) && (0 < DAT_21000580)) {
      FUN_01039ee2((byte *)"send data failed %d\n",iVar1,extraout_r2,DAT_21000580);
    }
  }
  else {
    if (0 < DAT_21000580) {
      FUN_01039ee2((byte *)"ipc service not ready!\n",param_2,param_2,DAT_21000580);
    }
    iVar1 = -1;
  }
  return iVar1;
}


