/*
 * Function: FUN_00044b24
 * Entry:    00044b24
 * Prototype: undefined __stdcall FUN_00044b24(void)
 */


void FUN_00044b24(void)

{
  GlassesState *pGVar1;
  
  pGVar1 = __get_dashboard_state();
  if (((((*(char *)(*(int *)&pGVar1->field_0x101c + 2) == '\x05') ||
        (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) == '\x13'))
       || (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) == '\x14')
       ) || (pGVar1 = __get_dashboard_state(),
            *(char *)(*(int *)&pGVar1->field_0x101c + 2) == '\x15')) &&
     ((DAT_2001db40 == '\x02' &&
      (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 3) == '\x01'))))
  {
    DAT_2001db43 = 1;
  }
  return;
}


