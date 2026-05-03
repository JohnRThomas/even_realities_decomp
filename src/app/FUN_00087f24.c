/*
 * Function: FUN_00087f24
 * Entry:    00087f24
 * Prototype: undefined4 __stdcall FUN_00087f24(int * param_1, int param_2, uint param_3, ushort * param_4)
 */


undefined4 FUN_00087f24(int *param_1,int param_2,uint param_3,ushort *param_4)

{
  undefined4 uVar1;
  
  if ((int)(param_1[1] * ((uint)*(ushort *)((int)param_1 + 10) - (uint)*(ushort *)(param_1 + 2)) +
           *param_1) < param_2) {
    if ((int)(param_1[4] * ((uint)*(ushort *)((int)param_1 + 0x16) - (uint)*(ushort *)(param_1 + 5))
             + param_1[3]) < param_2) {
      return 0xffffffea;
    }
    param_1 = param_1 + 3;
  }
  uVar1 = FUN_00087db2(param_1,param_2,param_3,param_4);
  return uVar1;
}


