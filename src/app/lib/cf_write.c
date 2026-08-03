/*
 * Function: cf_write
 * Entry:    0005d868
 * Prototype: ssize_t __stdcall cf_write(bt_conn * conn, bt_gatt_attr * attr, void * buf, uint16_t len, uint16_t offset, uint8_t flags)
 */


/* exclude_from_export_ai */

ssize_t cf_write(bt_conn *conn,bt_gatt_attr *attr,void *buf,uint16_t len,uint16_t offset,
                uint8_t flags)

{
  gatt_cf_cfg *cfg;
  uint uVar1;
  uint uVar2;
  char local_20 [4];
  char *local_1c;
  
  uVar2 = (uint)len;
  if (offset < 2) {
    if (offset + uVar2 < 2) {
      cfg = find_cf_cfg(conn);
      if ((cfg == (gatt_cf_cfg *)0x0) &&
         (cfg = find_cf_cfg((bt_conn *)0x0), cfg == (gatt_cf_cfg *)0x0)) {
        uVar2 = 0xffffffef;
        local_1c = "No space to store Client Supported Features";
        local_20[0] = '\x02';
        local_20[1] = '\0';
        local_20[2] = '\0';
        local_20[3] = '\0';
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x1080,local_20);
      }
      else {
        if (uVar2 != 0) {
          uVar1 = 0;
          do {
            if (((int)((uint)(cfg->data_CF_NUM_BYTES_ >> (uVar1 & 0xff)) << 0x1f) < 0) &&
               (-1 < (int)((uint)(*(byte *)buf >> (uVar1 & 0xff)) << 0x1f))) {
              return -0x13;
            }
            uVar1 = uVar1 + 1;
          } while (uVar1 != 3);
          cfg->data_CF_NUM_BYTES_ = cfg->data_CF_NUM_BYTES_ | *(byte *)buf & 7;
        }
        bt_addr_le_copy(&cfg->peer,&(conn->le).dst);
        cfg->id = conn->id;
        set_change_aware(cfg,true);
      }
    }
    else {
      uVar2 = 0xfffffff3;
    }
  }
  else {
    uVar2 = 0xfffffff9;
  }
  return uVar2;
}


