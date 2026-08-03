/*
 * Function: bt_le_conn_params_valid
 * Entry:    000846cc
 * Prototype: bool __stdcall bt_le_conn_params_valid(bt_le_conn_param * param)
 */


/* exclude_from_export */

bool bt_le_conn_params_valid(bt_le_conn_param *param)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = (uint)param->interval_max;
  if ((((uVar2 < param->interval_min) || (param->interval_min < 6)) || (0xc80 < uVar2)) ||
     ((499 < param->latency || (0xc76 < (param->timeout - 10 & 0xffff))))) {
    bVar1 = false;
  }
  else if (uVar2 * (ushort)(param->latency + 1) < (uint)param->timeout << 2) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}


