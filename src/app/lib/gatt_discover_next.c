/*
 * Function: gatt_discover_next
 * Entry:    000864e6
 * Prototype: void __stdcall gatt_discover_next(bt_conn * conn, uint16_t last_handle, bt_gatt_discover_params * params)
 */


/* exclude_from_export_ai */

void gatt_discover_next(bt_conn *conn,uint16_t last_handle,bt_gatt_discover_params *params)

{
  int iVar1;
  
  if (last_handle != 0) {
    if (last_handle == 0xffff) {
      *(undefined2 *)&params->attr_handle = 0xffff;
      goto LAB_00086506;
    }
    *(uint16_t *)&params->attr_handle = last_handle + 1;
    if (params->end_handle < (ushort)(last_handle + 1)) goto LAB_00086506;
  }
  iVar1 = bt_gatt_discover(conn,params);
  if (iVar1 == 0) {
    return;
  }
LAB_00086506:
                    /* WARNING: Could not recover jumptable at 0x00086512. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)params->func)(conn,0,params);
  return;
}


