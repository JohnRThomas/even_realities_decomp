/*
 * Function: ?_set_band_for_ESB
 * Entry:    0007f300
 * Prototype: undefined __stdcall ?_set_band_for_ESB(undefined1 param_1)
 */


void __set_band_for_ESB(undefined1 param_1)

{
  undefined4 extraout_r2;
  undefined4 local_48;
  undefined1 auStack_44 [60];
  
  local_48 = 0;
  memset(auStack_44,0,60);
  local_48._0_2_ = CONCAT11(param_1,1);
  global_ipc_service_send(&local_48,4,extraout_r2);
  return;
}


