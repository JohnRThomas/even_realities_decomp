/*
 * Function: FUN_0008047a
 * Entry:    0008047a
 * Prototype: undefined4 __stdcall FUN_0008047a(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_0008047a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r2;
  char cVar2;
  uint local_c;
  
  cVar2 = 'e';
  local_c = 0;
  while( true ) {
    iVar1 = cJSON_SetValuestring(0x4410,&local_c,param_3);
    if (iVar1 < 0) {
      return 0xffffffff;
    }
    if ((int)(local_c << 0x1f) < 0) break;
    cVar2 = cVar2 + -1;
    cJSON_free(&DAT_00000001);
    param_3 = extraout_r2;
    if (cVar2 == '\0') {
      return 0xfffffffe;
    }
  }
  return 0;
}


