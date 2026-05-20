/*
 * Function: FUN_00080534
 * Entry:    00080534
 * Prototype: int __stdcall FUN_00080534(undefined4 param_1, undefined4 param_2, int param_3)
 */


int FUN_00080534(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  
  iVar1 = print_object(param_3);
  if ((iVar1 == 0) && (iVar1 = FUN_000804e6(), iVar1 == 0)) {
    pvVar2 = cJSON_malloc(0x4820);
    iVar1 = -(uint)(pvVar2 != (void *)0x0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


