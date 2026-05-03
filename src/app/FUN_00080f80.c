/*
 * Function: FUN_00080f80
 * Entry:    00080f80
 * Prototype: undefined __stdcall FUN_00080f80(undefined4 param_1, void * param_2, size_t param_3)
 */


void FUN_00080f80(undefined4 param_1,void *param_2,size_t param_3)

{
  undefined4 local_10;
  void *pvStack_c;
  
  local_10 = param_1;
  pvStack_c = param_2;
  memcpy((void *)((int)&local_10 + 1),param_2,param_3);
  FUN_00080f08((int)&local_10,param_3 + 1);
  return;
}


