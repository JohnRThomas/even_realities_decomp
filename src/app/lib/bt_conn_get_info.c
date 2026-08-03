/*
 * Function: bt_conn_get_info
 * Entry:    0005a1f8
 * Prototype: int __stdcall bt_conn_get_info(bt_conn * conn, bt_conn_info * info)
 */


/* exclude_from_export */

int bt_conn_get_info(bt_conn *conn,bt_conn_info *info)

{
  uint8_t uVar1;
  int iVar2;
  int extraout_r1;
  int extraout_r2;
  char *file;
  int line;
  int iVar3;
  char *test;
  
  *(bt_conn_type *)&info->type = conn->type;
  *(uchar *)((int)&info->type + 1) = conn->role;
  *(uchar *)((int)&info->type + 2) = conn->id;
  test = (char *)(uint)conn->state;
  if (&NMI < test) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0","WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",
            2478);
    _ASSERT("\tInvalid conn state %u\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  *(undefined *)&info[1].state = (&DAT_000f1e6c)[(int)test];
  *(undefined1 *)((int)&info[1].state + 3) = 0;
  *(bt_security_t *)((int)&info[1].state + 1) = conn->sec_level;
  uVar1 = bt_conn_enc_key_size(conn);
  *(uint8_t *)(extraout_r1 + 0x26) = uVar1;
  if (*(char *)(extraout_r2 + 2) == '\x01') {
    *(int *)(extraout_r1 + 8) = extraout_r2 + 0x90;
    *(uint *)(extraout_r1 + 4) = (int)&bt_dev + (uint)*(byte *)(extraout_r2 + 8) * 7;
    iVar2 = extraout_r2 + 0x97;
    iVar3 = extraout_r2 + 0x9e;
    if (*(char *)(extraout_r2 + 3) != '\0') {
      iVar2 = extraout_r2 + 0x9e;
      iVar3 = extraout_r2 + 0x97;
    }
    *(int *)(extraout_r1 + 0xc) = iVar2;
    *(int *)(extraout_r1 + 0x10) = iVar3;
    *(undefined2 *)(extraout_r1 + 0x14) = *(undefined2 *)(extraout_r2 + 0xa6);
    *(undefined2 *)(extraout_r1 + 0x16) = *(undefined2 *)(extraout_r2 + 0xac);
    *(undefined2 *)(extraout_r1 + 0x18) = *(undefined2 *)(extraout_r2 + 0xae);
    *(int *)(extraout_r1 + 0x1c) = extraout_r2 + 0xc4;
    *(int *)(extraout_r1 + 0x20) = extraout_r2 + 0xc6;
    if ((*(int *)(extraout_r2 + 0xc0) != 0) &&
       ((int)((uint)*(byte *)(*(int *)(extraout_r2 + 0xc0) + 0xd) << 0x1b) < 0)) {
      *(undefined1 *)(extraout_r1 + 0x27) = 1;
    }
    if ((*(int *)(extraout_r2 + 0xc0) != 0) &&
       ((int)((uint)*(byte *)(*(int *)(extraout_r2 + 0xc0) + 0xd) << 0x1a) < 0)) {
      *(byte *)(extraout_r1 + 0x27) = *(byte *)(extraout_r1 + 0x27) | 2;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = -0x16;
  }
  return iVar2;
}


