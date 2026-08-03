/*
 * Function: discovery_complete_error
 * Entry:    00082ba4
 * Prototype: void __stdcall discovery_complete_error(bt_gatt_dm * dm, int err)
 */


/* exclude_from_export */

void discovery_complete_error(bt_gatt_dm *dm,int err)

{
  code *UNRECOVERED_JUMPTABLE;
  
  svc_attr_memory_release(dm);
  atomic_and((atomic_t *)((int)&dm[5].uuid + 3),-2);
  UNRECOVERED_JUMPTABLE = *(code **)(*(int *)((int)&dm[6].context + 2) + 8);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00082bcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)(dm->conn,err,dm->context);
    return;
  }
  return;
}


