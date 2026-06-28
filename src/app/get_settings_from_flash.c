/*
 * Function: get_settings_from_flash
 * Entry:    000252b8
 * Prototype: undefined4 __stdcall get_settings_from_flash(GlassesState * param_1)
 */


undefined4 get_settings_from_flash(GlassesState *param_1)

{
  (*(param_1->settings_ctx).write_cb)("dashboard_ts",param_1->dashboard_ts,0x75);
  (*(param_1->settings_ctx).write_cb)("countdown_ts",param_1->countdown_ts,7);
  (*(param_1->settings_ctx).write_cb)
            ("brightness_level",&(param_1->jdb_panel_context).panel_brightness_level,1);
  (*(param_1->settings_ctx).write_cb)("3dof_enable",&(param_1->imu_fusion_context)._dof_enable,1);
  (*(param_1->settings_ctx).write_cb)("display_mode",&param_1->display_mode,1);
  (*(param_1->settings_ctx).write_cb)("wakeup_angle",&(param_1->imu_fusion_context).wakeup_angle,1);
  (*(param_1->settings_ctx).write_cb)("first_enter_flag",&param_1->first_enter_flag,4);
  return 0;
}


