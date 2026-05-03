/*
 * Function: FUN_00031990
 * Entry:    00031990
 * Prototype: int __stdcall FUN_00031990(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_00031990(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  uint local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  iVar1 = cJSON_SetValuestring(0xff00,&local_c,param_3);
  if ((iVar1 < 0) || (4 < local_c + 0xdfddcdfd)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (0x15U >> (local_c + 0xdfddcdfd & 0xff) & 1) - 1;
  }
  return iVar1;
}


