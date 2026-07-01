/*
 * Function: FUN_00019c80
 * Entry:    00019c80
 * Prototype: undefined4 __stdcall FUN_00019c80(int param_1)
 */


undefined4 FUN_00019c80(int param_1)

{
  GlassesState *pGVar1;
  ushort extraout_r1;
  undefined4 extraout_r2;
  
  FUN_00018ba8();
  if (param_1 == 0) {
    pGVar1 = __get_dashboard_state();
    if (*(char *)((int)&pGVar1->field1212_0x1087 + 1) != '\x01') {
      return 0;
    }
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)((int)&pGVar1->field1212_0x1087 + 1) = 0;
  }
  else {
    if (DAT_20007ef4 == (bt_conn *)0x0) {
      return 0;
    }
    discover_gattp(DAT_20007ef4,extraout_r1,extraout_r2);
    pGVar1 = __get_dashboard_state();
    if (*(char *)((int)&pGVar1->field1212_0x1087 + 1) != '\0') {
      return 0;
    }
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)((int)&pGVar1->field1212_0x1087 + 1) = 1;
  }
  pGVar1 = __get_dashboard_state();
  *(undefined4 *)&pGVar1->field_0x1060 = 0;
  pGVar1 = __get_dashboard_state();
  k_sem_give(&pGVar1->sem_6);
  return 0;
}


