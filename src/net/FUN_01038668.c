/*
 * Function: FUN_01038668
 * Entry:    01038668
 * Prototype: undefined __stdcall FUN_01038668(uint * param_1, undefined4 param_2, int * param_3, undefined4 param_4, uint param_5, int param_6, undefined4 * param_7)
 */


void FUN_01038668(uint *param_1,undefined4 param_2,int *param_3,undefined4 param_4,uint param_5,
                 int param_6,undefined4 *param_7)

{
  FUN_01037d78(param_1,param_2,param_3,param_4,param_5,param_6);
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = *(undefined4 *)(DAT_21004b30 + 0x14);
  }
  return;
}


