/*
 * Function: get_settings_from_flash
 * Entry:    000252b8
 * Prototype: undefined4 __stdcall get_settings_from_flash(GlassesState * param_1)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 get_settings_from_flash(GlassesState *param_1)

{
  (**(code **)&param_1->field_0x1054)("dashboard_ts",param_1->glasses_state_struct_0FF0,0x75);
  (**(code **)&param_1->field_0x1054)("countdown_ts",param_1->glasses_state_struct_0FF4,7);
  (**(code **)&param_1->field_0x1054)
            ("brightness_level",&(param_1->jdb_panel_context).field834_0x369,1);
  (**(code **)&param_1->field_0x1054)("3dof_enable",&param_1->field_0xf64,1);
  (**(code **)&param_1->field_0x1054)("display_mode",&param_1->field_0xfee,1);
  (**(code **)&param_1->field_0x1054)("wakeup_angle",&param_1->field_0xef8,1);
  (**(code **)&param_1->field_0x1054)("first_enter_flag",&param_1->field_0x1064);
  return 0;
}


