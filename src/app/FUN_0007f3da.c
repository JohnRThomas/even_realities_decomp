/*
 * Function: FUN_0007f3da
 * Entry:    0007f3da
 * Prototype: undefined4 __stdcall FUN_0007f3da(undefined4 param_1, undefined4 param_2)
 */


undefined4 FUN_0007f3da(undefined4 param_1,undefined4 param_2)

{
  GlassesState *pGVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined3 uStack_c;
  undefined1 uStack_9;
  
  local_10 = 0;
  uStack_9 = (undefined1)((uint)param_2 >> 0x18);
  uStack_c = 0;
  pGVar1 = __get_dashboard_state();
  iVar2 = memcmp(pGVar1->field2780_0x1080 + 1,&local_10,7);
  uVar3 = 0;
  if (iVar2 != 0) {
    local_10 = 0xffffffff;
    _uStack_c = CONCAT13(uStack_9,0xffffff);
    pGVar1 = __get_dashboard_state();
    iVar2 = memcmp(pGVar1->field2780_0x1080 + 1,&local_10,7);
    uVar3 = 0;
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}


