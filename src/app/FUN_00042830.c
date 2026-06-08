/*
 * Function: FUN_00042830
 * Entry:    00042830
 * Prototype: undefined __stdcall FUN_00042830(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00042830(void)

{
  GlassesState *pGVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_20003697;
  pGVar1 = __get_dashboard_state();
  if ((uVar2 != *(byte *)(*(int *)&pGVar1->field_0x101c + 2)) ||
     ((((pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) != '\x05' &&
        (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) != '\x13'))
       && (pGVar1 = __get_dashboard_state(), *(char *)(*(int *)&pGVar1->field_0x101c + 2) != '\x14')
       ) && (pGVar1 = __get_dashboard_state(),
            *(char *)(*(int *)&pGVar1->field_0x101c + 2) != '\x15')))) {
    DAT_2001db44 = 0;
    DAT_2001db43 = 0;
  }
  DAT_2001db45 = 1;
  pGVar1 = __get_dashboard_state();
  DAT_20003697 = *(undefined1 *)(*(int *)&pGVar1->field_0x101c + 2);
  return;
}


