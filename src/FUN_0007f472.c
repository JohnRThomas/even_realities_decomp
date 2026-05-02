/*
 * Function: FUN_0007f472
 * Entry:    0007f472
 * Prototype: undefined4 __stdcall FUN_0007f472(void * param_1, size_t param_2, undefined1 param_3, int param_4)
 */


undefined4 FUN_0007f472(void *param_1,size_t param_2,undefined1 param_3,int param_4)

{
  GlassesState *pGVar1;
  void *pvVar2;
  
  if (param_4 == 0) {
    pGVar1 = __get_dashboard_state();
    pvVar2 = *(void **)&pGVar1->field_0x103c;
  }
  else {
    pGVar1 = __get_dashboard_state();
    pvVar2 = *(void **)&pGVar1->field_0x1038;
  }
  pvVar2 = memcpy(pvVar2,param_1,param_2);
  *(undefined1 *)((int)pvVar2 + 0x200) = param_3;
  return 0;
}


