/*
 * Function: update_ccc
 * Entry:    0005e800
 * Prototype: uint8_t __stdcall update_ccc(bt_gatt_attr * attr, uint16_t handle, void * user_data)
 */


/* exclude_from_export_ai */

uint8_t update_ccc(bt_gatt_attr *attr,uint16_t handle,void *user_data)

{
  ushort uVar1;
  bool bVar2;
  byte bVar3;
  bt_security_t bVar4;
  gatt_sc_cfg *pgVar5;
  uint uVar6;
  int iVar7;
  bt_conn *conn;
  _bt_gatt_ccc *ccc;
  uint local_48;
  char *local_44;
  bt_gatt_attr *pbStack_40;
  char local_28 [4];
  char *local_24;
  
  conn = *(bt_conn **)user_data;
  if (attr->write == (undefined *)0x5d711) {
    ccc = (_bt_gatt_ccc *)attr->user_data;
    if (((short)ccc[2] != 0) &&
       (bVar2 = bt_conn_is_peer_addr_le(conn,(uint8_t)*ccc,(bt_addr_le_t *)((int)ccc + 1)), bVar2))
    {
      bVar3 = bt_gatt_check_perm(conn,attr,0x12a);
      local_48 = (uint)bVar3;
      if (local_48 != 0) {
        if (local_48 == 3) {
          local_44 = "CCC %p not writable";
          pbStack_40 = attr;
          LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1880,(char *)&local_48);
          return '\x01';
        }
        if (local_48 == 5) {
          bVar3 = 3;
        }
        else {
          bVar3 = 2;
        }
        bVar4 = bt_conn_get_security(conn);
        if (bVar4 < bVar3) {
          if (bVar3 <= *(byte *)((int)user_data + 4)) {
            return '\x01';
          }
          *(byte *)((int)user_data + 4) = bVar3;
          return '\x01';
        }
      }
      gatt_ccc_changed(attr,ccc);
      if (((ccc == (_bt_gatt_ccc *)&DAT_20002a40) &&
          (pgVar5 = find_sc_cfg(conn->id,&(conn->le).dst), pgVar5 != (gatt_sc_cfg *)0x0)) &&
         ((pgVar5->data_start != 0 || (pgVar5->data_end != 0)))) {
        bVar3 = bt_conn_index(conn);
        uVar6 = (uint)bVar3;
        uVar1 = pgVar5->data_end;
        *(ushort *)(&DAT_20010902 + uVar6 * 4) = pgVar5->data_start;
        *(ushort *)(&DAT_20010904 + uVar6 * 4) = uVar1;
        iVar7 = uVar6 * 0x18;
        *(undefined **)(&DAT_2000b8ac + iVar7) = &DAT_20010902 + (short)(ushort)bVar3 * 4;
        *(undefined ***)(&DAT_2000b8a0 + iVar7) = &PTR_DAT_0008ef6c;
        *(undefined4 *)(&DAT_2000b8a4 + iVar7) = 0x8638d;
        *(undefined2 *)(&DAT_2000b8b0 + iVar7) = 4;
        iVar7 = bt_gatt_indicate(conn,(bt_gatt_indicate_params *)
                                      ((short)(ushort)bVar3 * 0x18 + 0x2000b89c));
        if (iVar7 != 0) {
          local_24 = "SC restore indication failed";
          local_28[0] = '\x02';
          local_28[1] = '\0';
          local_28[2] = '\0';
          local_28[3] = '\0';
          LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1040,local_28);
        }
      }
    }
  }
  return '\x01';
}


