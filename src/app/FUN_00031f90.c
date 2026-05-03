/*
 * Function: FUN_00031f90
 * Entry:    00031f90
 * Prototype: undefined __stdcall FUN_00031f90(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_00031f90(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  undefined1 *puVar3;
  uint local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  uStack_8 = param_3;
  iVar2 = cJSON_SetValuestring(0x4410,&local_c,param_3);
  if (-1 < iVar2) {
    puVar3 = (undefined1 *)(local_c << 0x1d);
    if ((int)puVar3 < 0) {
      iVar2 = 2;
      puVar3 = &DAT_2001aa7a;
      DAT_2001aa7a = 2;
    }
    bVar1 = (local_c & 2) != 0;
    if (bVar1) {
      puVar3 = &DAT_2001aa7a;
      DAT_2001aa7a = 1;
    }
    if ((local_c & 1) != 0) {
      print_array(iVar2,(uint)bVar1,puVar3);
      return;
    }
  }
  return;
}


