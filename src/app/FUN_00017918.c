/*
 * Function: FUN_00017918
 * Entry:    00017918
 * Prototype: undefined __stdcall FUN_00017918(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00017918(void)

{
  GlassesState *pGVar1;
  
  FUN_0002c6dc();
  pGVar1 = __get_dashboard_state();
  if ((pGVar1->field_0x1 == '\b') || (DAT_20019a62 == '\x02')) {
    DAT_2001095d = DAT_2001095d + 1;
    if (4 < DAT_2001095d) {
      DAT_20019a62 = '\0';
      FUN_0002c6f4(0);
    }
    if (DAT_20019a62 != '\0') {
      return;
    }
  }
  DAT_2001095d = 0;
  return;
}


