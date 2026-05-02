/*
 * Function: FUN_00025b28
 * Entry:    00025b28
 * Prototype: undefined __stdcall FUN_00025b28(undefined4 param_1, uint param_2)
 */


void FUN_00025b28(undefined4 param_1,uint param_2)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  *(undefined4 *)&pGVar1->field_0x1060 = param_1;
  if ((DAT_20017d2f != param_2) && (DAT_20017d2f == 0)) {
    DAT_20017d2f = (byte)param_2;
  }
  pGVar1 = __get_dashboard_state();
  k_sem_give(&pGVar1->sem_6);
  return;
}


