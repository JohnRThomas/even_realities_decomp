/*
 * Function: FUN_00080534
 * Entry:    00080534
 * Prototype: int __stdcall FUN_00080534(uint param_1, uint param_2, int param_3)
 */


int FUN_00080534(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  
  iVar1 = print_object(param_3,param_2,param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_000804e6(param_1,param_2,extraout_r2), iVar1 == 0)) {
    iVar1 = cJSON_malloc(0x4820,4,extraout_r2_00);
    iVar1 = -(uint)(iVar1 != 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


