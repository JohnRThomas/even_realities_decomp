/*
 * Function: FUN_0007f6c8
 * Entry:    0007f6c8
 * Prototype: undefined4 __stdcall FUN_0007f6c8(GlassesState * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_0007f6c8(GlassesState *param_1)

{
  int iVar1;
  GlassesState *pGVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  iVar1 = load_sys_setting(param_1);
  if (((iVar1 == 0) && (iVar1 = load_usr_setting((int)param_1), iVar1 == 0)) &&
     (iVar1 = load_burial_point((int)param_1,extraout_r1,extraout_r2,extraout_r3), iVar1 == 0)) {
    pGVar2 = __get_dashboard_state();
    FUN_000806c6((undefined1 *)pGVar2->glasses_state_struct_0FF4);
  }
  return 0;
}


