/*
 * Function: FUN_0102ac08
 * Entry:    0102ac08
 * Prototype: undefined __stdcall FUN_0102ac08(undefined1 param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0102ac08(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  char cVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = 0;
  cVar2 = '\n';
  local_18 = (uint)CONCAT12(param_1,0xd01);
  uStack_10 = param_3;
  while ((iVar1 = (**(code **)(DAT_210045f4 + 0xa8))(&local_18,8), iVar1 < 1 &&
         (cVar2 = cVar2 + -1, cVar2 != '\0'))) {
    FUN_01039ddc(10);
  }
  return;
}


