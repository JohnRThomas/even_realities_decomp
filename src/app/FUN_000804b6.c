/*
 * Function: FUN_000804b6
 * Entry:    000804b6
 * Prototype: int __stdcall FUN_000804b6(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_000804b6(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  int iVar2;
  bool bVar3;
  uint local_c;
  
  iVar2 = 100;
  local_c = 0;
  do {
    iVar1 = cJSON_SetValuestring(0x4714,&local_c,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_c == 0) break;
    cJSON_free(&DAT_00000001);
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
    param_3 = extraout_r2;
  } while (bVar3);
  iVar1 = -1;
  if (iVar2 != -1) {
    iVar1 = 0;
  }
  return iVar1;
}


