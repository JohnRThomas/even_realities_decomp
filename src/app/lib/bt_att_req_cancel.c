/*
 * Function: bt_att_req_cancel
 * Entry:    0005cda8
 * Prototype: void __stdcall bt_att_req_cancel(bt_conn * conn, bt_att_req * req)
 */


/* exclude_from_export_ai */

void bt_att_req_cancel(bt_conn *conn,bt_att_req *req)

{
  bt_att *pbVar1;
  int *piVar2;
  int *piVar3;
  
  if (((conn == (bt_conn *)0x0) || (req == (bt_att_req *)0x0)) ||
     (pbVar1 = att_get(conn), pbVar1 == (bt_att *)0x0)) {
    return;
  }
  piVar3 = *(int **)((int)&pbVar1[1].prep_queue + 2);
  if (piVar3 == (int *)0x0) {
LAB_0005cdf6:
    sys_slist_find_and_remove((sys_slist_t *)&pbVar1->reqs,(sys_snode_t *)req);
  }
  else {
    piVar2 = piVar3 + -100;
    piVar3 = (int *)*piVar3;
    if (piVar3 != (int *)0x0) {
      piVar3 = piVar3 + -100;
    }
    while (req != (bt_att_req *)piVar2[0x49]) {
      if (piVar3 == (int *)0x0) goto LAB_0005cdf6;
      while (piVar2 = piVar3, piVar3 = (int *)0x0, piVar2[100] != 0) {
        piVar3 = (int *)(piVar2[100] + -400);
        if (req == (bt_att_req *)piVar2[0x49]) goto LAB_0005cde6;
      }
    }
LAB_0005cde6:
    piVar2[0x49] = (int)&DAT_2000b880;
  }
  bt_att_req_free(req);
  return;
}


