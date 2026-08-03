/*
 * Function: bt_conn_index
 * Entry:    00059c4c
 * Prototype: uint8_t __stdcall bt_conn_index(bt_conn * conn)
 */


/* exclude_from_export */

uint8_t bt_conn_index(bt_conn *conn)

{
  char *test;
  char *file;
  int line;
  
  if (conn != &acl_conns) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "index >= 0 && index < ((size_t) (((int) sizeof(char[1 - 2 * !(!__builtin_types_compatible_p(__typeof__(acl_conns), __typeof__(&(acl_conns)[0])))]) - 1) + (sizeof(acl_conns) / sizeof((acl_conns)[0]))))"
            ,"WEST_TOPDIR/zephyr/subsys/bluetooth/host/conn.c",1345);
    _ASSERT("\tInvalid bt_conn pointer\n",test,file,line);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  return '\0';
}


