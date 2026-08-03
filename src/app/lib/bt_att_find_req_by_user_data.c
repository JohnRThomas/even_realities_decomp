/*
 * Function: bt_att_find_req_by_user_data
 * Entry:    00085cf2
 * Prototype: bt_att_req * __stdcall bt_att_find_req_by_user_data(bt_conn * conn, void * user_data)
 */


/* exclude_from_export_ai */

bt_att_req * bt_att_find_req_by_user_data(bt_conn *conn,void *user_data)

{
  bt_att *pbVar1;
  bt_att_req *pbVar2;
  int *piVar3;
  
  pbVar1 = att_get(conn);
  pbVar2 = (bt_att_req *)0x0;
  if (pbVar1 != (bt_att *)0x0) {
    for (piVar3 = *(int **)((int)&pbVar1[1].prep_queue + 2); piVar3 != (int *)0x0;
        piVar3 = (int *)*piVar3) {
      if (*(void **)((int)&((bt_att_req *)piVar3[-0x1b])->user_data + 2) == user_data) {
        return (bt_att_req *)piVar3[-0x1b];
      }
    }
    for (pbVar2 = (bt_att_req *)pbVar1->reqs;
        (pbVar2 != (bt_att_req *)0x0 && (*(void **)((int)&pbVar2->user_data + 2) != user_data));
        pbVar2 = (bt_att_req *)pbVar2->node) {
    }
  }
  return pbVar2;
}


