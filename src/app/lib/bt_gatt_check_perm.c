/*
 * Function: bt_gatt_check_perm
 * Entry:    00086472
 * Prototype: uint8_t __stdcall bt_gatt_check_perm(bt_conn * conn, bt_gatt_attr * attr, uint16_t mask)
 */


/* exclude_from_export_ai */

uint8_t bt_gatt_check_perm(bt_conn *conn,bt_gatt_attr *attr,uint16_t mask)

{
  ushort uVar1;
  bool bVar2;
  uint8_t uVar3;
  bt_security_t bVar4;
  undefined *puVar5;
  
  uVar1 = attr->perm;
  if (((int)((uint)mask << 0x1f) < 0) && (((uVar1 & 0x95) == 0 || (attr->read == (undefined *)0x0)))
     ) {
    return '\x02';
  }
  if (((int)((uint)mask << 0x1e) < 0) &&
     (((uVar1 & 0x12a) == 0 || (attr->write == (undefined *)0x0)))) {
    return '\x03';
  }
  uVar1 = mask & uVar1;
  if ((uVar1 & 0x3c) == 0) {
LAB_000864ba:
    uVar3 = '\0';
  }
  else {
    if (conn->encrypt == '\0') {
      bVar2 = bt_conn_ltk_present(conn);
      if (bVar2) {
        return '\x0f';
      }
    }
    else if ((((uVar1 & 0x30) == 0) || (bVar4 = bt_conn_get_security(conn), 2 < bVar4)) &&
            (((uVar1 & 0x180) == 0 ||
             ((puVar5 = (conn->le).keys, puVar5 != (undefined *)0x0 &&
              ((int)((uint)(byte)puVar5[0xd] << 0x1b) < 0)))))) goto LAB_000864ba;
    uVar3 = '\x05';
  }
  return uVar3;
}


