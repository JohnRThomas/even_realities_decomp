/*
 * Function: latch_auth_cb
 * Entry:    0005fd6c
 * Prototype: bt_conn_auth_cb * __stdcall latch_auth_cb(bt_smp * smp)
 */


/* exclude_from_export_ai */

bt_conn_auth_cb * latch_auth_cb(bt_smp *smp)

{
  byte *pbVar1;
  
  pbVar1 = smp[3].mackey + 7;
  if (*(undefined **)pbVar1 == &DAT_20006630) {
    *(undefined4 *)pbVar1 = DAT_2000b708;
  }
  return *(bt_conn_auth_cb **)pbVar1;
}


