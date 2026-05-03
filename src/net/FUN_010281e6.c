/*
 * Function: FUN_010281e6
 * Entry:    010281e6
 * Prototype: int __stdcall FUN_010281e6(int * param_1, short param_2, uint param_3)
 */


int FUN_010281e6(int *param_1,short param_2,uint param_3)

{
  int iVar1;
  
  if (((uint)param_1 & 7) != 0) {
    FUN_01009500(0x22,0x66,param_3,(uint)param_1 & 7);
  }
  if (param_1 != (int *)0x0) {
    *param_1 = (int)(param_1 + 2);
    *(short *)(param_1 + 1) = param_2;
    *(short *)((int)param_1 + 6) = (short)param_3;
  }
  iVar1 = FUN_01028174((int)param_1,8,param_2,((param_3 & 0xffff) + 7 & 0xfffffff8) + 0x10);
  return iVar1;
}


