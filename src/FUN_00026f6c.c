/*
 * Function: FUN_00026f6c
 * Entry:    00026f6c
 * Prototype: int __stdcall FUN_00026f6c(undefined4 param_1, uint param_2, undefined4 param_3)
 */


int FUN_00026f6c(undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  local_c = param_2;
  uStack_8 = param_3;
  FUN_0007fcd0(global_st25dv_context_ptr,(uint)&local_c,param_3);
  iVar1 = (local_c >> 0x10) + 1;
  return (local_c & 0xff) * iVar1 + iVar1;
}


