/*
 * Function: FUN_00081216
 * Entry:    00081216
 * Prototype: undefined1 __stdcall FUN_00081216(void)
 */


undefined1 FUN_00081216(void)

{
  undefined1 uVar1;
  int iVar2;
  GlassesState *pGVar3;
  
  iVar2 = update_burial_point_day_index();
  if (iVar2 == 0) {
    pGVar3 = __get_dashboard_state();
    uVar1 = pGVar3->field_0x113d;
  }
  else {
    uVar1 = 7;
  }
  return uVar1;
}


