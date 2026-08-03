/*
 * Function: bt_gatt_attr_write_ccc
 * Entry:    0005d710
 * Prototype: ssize_t __stdcall bt_gatt_attr_write_ccc(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset, uint8_t flags)
 */


/* exclude_from_export_ai */

ssize_t bt_gatt_attr_write_ccc
                  (bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset,
                  uint8_t flags)

{
  ushort uVar1;
  bt_gatt_ccc_cfg *pbVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  _bt_gatt_ccc *ccc;
  char local_28 [4];
  char *local_24;
  
  uVar4 = (uint)len;
  ccc = (_bt_gatt_ccc *)attr->user_data;
  if (offset == 0) {
    if (uVar4 - 1 < 2) {
      uVar5 = (ushort)*(byte *)buf;
      if (uVar4 != 1) {
        uVar5 = *(ushort *)buf;
      }
      pbVar2 = find_ccc_cfg(conn,ccc);
      if (pbVar2 == (bt_gatt_ccc_cfg *)0x0) {
        if (uVar5 == 0) {
          return uVar4;
        }
        pbVar2 = find_ccc_cfg((bt_conn *)0x0,ccc);
        if (pbVar2 == (bt_gatt_ccc_cfg *)0x0) {
          local_24 = "No space to store CCC cfg";
          local_28[0] = '\x02';
          local_28[1] = '\0';
          local_28[2] = '\0';
          local_28[3] = '\0';
          LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_28);
          return -0x11;
        }
        bt_addr_le_copy((bt_addr_le_t *)((int)pbVar2 + 1),&(conn->le).dst);
        *(uchar *)pbVar2 = conn->id;
      }
      if ((code *)ccc[4] != (code *)0x0) {
        iVar3 = (*(code *)ccc[4])(conn,attr,uVar5);
        if (iVar3 < 0) {
          return iVar3;
        }
        if (1 < iVar3 - 1U) {
          return -0xe;
        }
      }
      uVar1 = *(ushort *)(pbVar2 + 2);
      *(ushort *)(pbVar2 + 2) = uVar5;
      if (*(ushort *)((int)ccc + 10) != uVar5) {
        gatt_ccc_changed(attr,ccc);
      }
      if (uVar1 != uVar5) {
        gatt_delayed_store_enqueue(conn->id,&(conn->le).dst,0);
      }
      if (uVar5 == 0) {
        bt_addr_le_copy((bt_addr_le_t *)((int)pbVar2 + 1),(bt_addr_le_t *)&DAT_000f0b50);
        *(undefined1 *)pbVar2 = 0;
        *(undefined2 *)(pbVar2 + 2) = 0;
      }
    }
    else {
      uVar4 = 0xfffffff3;
    }
  }
  else {
    uVar4 = 0xfffffff9;
  }
  return uVar4;
}


