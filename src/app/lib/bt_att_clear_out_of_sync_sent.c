/*
 * Function: bt_att_clear_out_of_sync_sent
 * Entry:    00085d2a
 * Prototype: void __stdcall bt_att_clear_out_of_sync_sent(bt_conn * conn)
 */


/* exclude_from_export_ai */

void bt_att_clear_out_of_sync_sent(bt_conn *conn)

{
  bt_att *pbVar1;
  int *piVar2;
  
  pbVar1 = att_get(conn);
  if (pbVar1 != (bt_att *)0x0) {
    for (piVar2 = *(int **)((int)&pbVar1[1].prep_queue + 2); piVar2 != (int *)0x0;
        piVar2 = (int *)*piVar2) {
      atomic_clear_bit(piVar2 + -0x1c,5);
    }
  }
  return;
}


