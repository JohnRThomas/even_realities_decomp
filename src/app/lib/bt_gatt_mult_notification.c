/*
 * Function: bt_gatt_mult_notification
 * Entry:    0005f89c
 * Prototype: void __stdcall bt_gatt_mult_notification(bt_conn * conn, void * data, uint16_t length)
 */


/* exclude_from_export */

void bt_gatt_mult_notification(bt_conn *conn,void *data,uint16_t length)

{
  short sVar1;
  gatt_sub *pgVar2;
  int iVar3;
  bt_gatt_subscribe_params *pbVar4;
  int *piVar5;
  bt_gatt_subscribe_params *params;
  uint len;
  char local_50 [4];
  char *local_4c;
  uint uStack_48;
  size_t local_44;
  size_t local_40;
  short *local_3c;
  net_buf_simple nStack_34;
  
  local_40 = (size_t)length;
  pgVar2 = gatt_sub_find(conn);
  if (pgVar2 != (gatt_sub *)0x0) {
    net_buf_simple_init_with_data(&nStack_34,data,local_40);
    while (4 < nStack_34.len) {
      local_3c = net_buf_simple_pull_mem(&nStack_34,4);
      len = (uint)(ushort)local_3c[1];
      sVar1 = *local_3c;
      if (nStack_34.len < len) {
        local_44 = local_40;
        local_4c = "Invalid data len %u > %u";
        local_50[0] = '\x04';
        local_50[1] = '\0';
        local_50[2] = '\0';
        local_50[3] = '\0';
        uStack_48 = len;
        LOG_ERR(&PTR_s_bt_gatt_0008b8d8,0x2040,local_50);
        return;
      }
      piVar5 = (int *)pgVar2->list;
      if (piVar5 != (int *)0x0) {
        pbVar4 = (bt_gatt_subscribe_params *)*piVar5;
        if (pbVar4 != (bt_gatt_subscribe_params *)0x0) {
          pbVar4 = pbVar4 + -6;
        }
        if ((short)piVar5[-3] != sVar1) goto LAB_0005f952;
        params = piVar5 + -6;
        do {
          if ((*(byte *)((int)params + 0x12) <= conn->sec_level) &&
             (iVar3 = (*(code *)*params)(conn,params,local_3c + 2,len), iVar3 == 0)) {
            bt_gatt_unsubscribe(conn,params);
          }
LAB_0005f952:
          if (pbVar4 == (bt_gatt_subscribe_params *)0x0) break;
          do {
            params = pbVar4;
            if (params[6] == 0) {
              pbVar4 = (bt_gatt_subscribe_params *)0x0;
              if ((short)params[3] != sVar1) goto LAB_0005f958;
              break;
            }
            pbVar4 = (bt_gatt_subscribe_params *)(params[6] + -0x18);
          } while ((short)params[3] != sVar1);
        } while( true );
      }
LAB_0005f958:
      net_buf_simple_pull_mem(&nStack_34,len);
    }
  }
  return;
}


