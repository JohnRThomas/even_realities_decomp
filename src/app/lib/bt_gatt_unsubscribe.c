/*
 * Function: bt_gatt_unsubscribe
 * Entry:    0005f79c
 * Prototype: int __stdcall bt_gatt_unsubscribe(bt_conn * conn, bt_gatt_subscribe_params * params)
 */


/* WARNING: Removing unreachable block (ram,0x0005f822) */
/* exclude_from_export */

int bt_gatt_unsubscribe(bt_conn *conn,bt_gatt_subscribe_params *params)

{
  bool bVar1;
  gatt_sub *sub;
  int iVar2;
  char *test;
  char *test_00;
  uint extraout_r1;
  uint bit;
  char *file;
  char *file_00;
  int line;
  int line_00;
  int *piVar3;
  bool bVar4;
  
  if (conn == (bt_conn *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","conn","WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c"
            ,5340);
    _ASSERT("\tinvalid parameters\n\n",test,file,line);
  }
  else {
    if (params != (bt_gatt_subscribe_params *)0x0) {
      if (conn->state == 7) {
        sub = gatt_sub_find(conn);
        if ((sub != (gatt_sub *)0x0) && (piVar3 = (int *)sub->list, piVar3 != (int *)0x0)) {
          bVar1 = false;
          bVar4 = false;
          bit = extraout_r1;
          do {
            if (params == piVar3 + -6) {
              bVar1 = true;
            }
            else {
              bit = (uint)*(ushort *)(params + 3);
              if (*(ushort *)(piVar3 + -3) == bit) {
                bVar4 = true;
              }
            }
            piVar3 = (int *)*piVar3;
          } while (piVar3 != (int *)0x0);
          if (bVar1) {
            atomic_test_bit(params + 5,bit);
            if (bVar4) {
              sys_slist_find_and_remove((sys_slist_t *)&sub->list,(sys_snode_t *)(params + 6));
              if (sub->list == 0) {
                gatt_sub_free(sub);
              }
              (*(code *)*params)(conn,params,0);
            }
            else {
              *(undefined2 *)(params + 4) = 0;
              iVar2 = gatt_write_ccc(conn,params);
              if (iVar2 != 0) {
                return iVar2;
              }
              sys_slist_find_and_remove((sys_slist_t *)&sub->list,(sys_snode_t *)(params + 6));
              if (sub->list == 0) {
                gatt_sub_free(sub);
              }
            }
            return 0;
          }
        }
        iVar2 = -0x16;
      }
      else {
        iVar2 = -0x80;
      }
      return iVar2;
    }
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","params",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/gatt.c",0x14dd);
    _ASSERT("\tinvalid parameters\n\n",test_00,file_00,line_00);
  }
                    /* WARNING: Subroutine does not return */
  k_panic();
}


