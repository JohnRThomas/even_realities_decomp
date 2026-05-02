/*
 * Function: FUN_00080bc0
 * Entry:    00080bc0
 * Prototype: int __stdcall FUN_00080bc0(int param_1, void * param_2, size_t param_3, int param_4, int param_5, int param_6)
 */


int FUN_00080bc0(int param_1,void *param_2,size_t param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + param_6 * 4);
  for (iVar2 = 0; iVar2 < param_4; iVar2 = iVar2 + 1) {
    memcpy((void *)(*piVar1 + param_5 % 0x140),param_2,param_3);
    param_2 = (void *)((int)param_2 + param_3);
    piVar1 = piVar1 + 1;
  }
  return param_6;
}


