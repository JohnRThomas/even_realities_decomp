/*
 * Function: FUN_00035a84
 * Entry:    00035a84
 * Prototype: undefined __stdcall FUN_00035a84(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_00035a84(void)

{
  GlassesState *pGVar1;
  
  if ((&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d] != 0) {
    pGVar1 = __get_dashboard_state();
    (&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d] =
         (&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d] - (uint)(byte)pGVar1->field_0x10d7;
  }
  return;
}


