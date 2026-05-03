/*
 * Function: FUN_0008040c
 * Entry:    0008040c
 * Prototype: undefined __stdcall FUN_0008040c(void)
 */


void FUN_0008040c(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (-1 < (int)((uint)(byte)pGVar1->field_0x106d << 0x1d)) {
    pGVar1 = __get_dashboard_state();
    pGVar1->field_0x106d = pGVar1->field_0x106d | 4;
    pGVar1 = __get_dashboard_state();
    k_sem_give(&pGVar1->sem_4);
  }
  return;
}


