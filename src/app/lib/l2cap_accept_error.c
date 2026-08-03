/*
 * Function: l2cap_accept_error
 * Entry:    0005a6e4
 * Prototype: int __stdcall l2cap_accept_error(int * conn, int err)
 */


/* exclude_from_export */

int l2cap_accept_error(int *conn,int err)

{
  byte local_18 [4];
  char *local_14;
  int *piStack_10;
  
  local_14 = "No available L2CAP context for conn %p";
  local_18[0] = 3;
  local_18[1] = 0;
  local_18[2] = 0;
  local_18[3] = 0;
  piStack_10 = conn;
  LOG_WRN((char *)&PTR_s_bt_l2cap_0008b910,0x1840,local_18);
  return -0xc;
}


