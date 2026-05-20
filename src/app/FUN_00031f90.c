/*
 * Function: FUN_00031f90
 * Entry:    00031f90
 * Prototype: undefined __stdcall FUN_00031f90(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_00031f90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  iVar1 = cJSON_SetValuestring(0x4410,&local_c,param_3);
  if (-1 < iVar1) {
    if ((int)(local_c << 0x1d) < 0) {
      DAT_2001aa7a = 2;
    }
    if ((local_c & 2) != 0) {
      DAT_2001aa7a = 1;
    }
    if ((local_c & 1) != 0) {
      print_array();
      return;
    }
  }
  return;
}


