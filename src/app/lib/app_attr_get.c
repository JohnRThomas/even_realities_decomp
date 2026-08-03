/*
 * Function: app_attr_get
 * Entry:    00082f84
 * Prototype: int __stdcall app_attr_get(bt_ancs_client * ancs_c, uint8_t * app_id, uint32_t app_id_len, bt_ancs_write_cb func)
 */


/* exclude_from_export_ai */

int app_attr_get(bt_ancs_client *ancs_c,uint8_t *app_id,uint32_t app_id_len,bt_ancs_write_cb func)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_2c [8];
  sys_snode_t *local_24;
  
  if (app_id_len == 0) {
    return -0x16;
  }
  ancs_c[0x1108] = (bt_ancs_client)0x0;
  uVar3 = *(uint *)(ancs_c + 4);
  *(uint *)(ancs_c + 4) = uVar3 | 4;
  if ((uVar3 & 4) == 0) {
    local_2c._0_4_ = app_id;
    local_2c._4_4_ = app_id_len;
    local_24 = (sys_snode_t *)func;
    net_buf_simple_init_with_data((net_buf_simple *)local_2c,ancs_c + 0x28,0x1000);
    local_2c._4_4_ = local_2c._4_4_ & 0xffff0000;
    local_2c._0_4_ = local_24;
    sVar1 = net_buf_simple_tailroom((net_buf_simple *)local_2c);
    if (sVar1 != 0) {
      net_buf_add_u8((net_buf *)local_2c,'\x01');
      sVar1 = net_buf_simple_tailroom((net_buf_simple *)local_2c);
      if (app_id_len + 1 <= sVar1) {
        net_buf_add_mem((net_buf *)local_2c,app_id,app_id_len);
        net_buf_add_u8((net_buf *)local_2c,'\0');
        *(undefined4 *)(ancs_c + 0x10f8) = 0;
        if (ancs_c[0x10e8] != (bt_ancs_client)0x0) {
          sVar1 = net_buf_simple_tailroom((net_buf_simple *)local_2c);
          if (sVar1 == 0) {
            return -0xc;
          }
          net_buf_add_u8((net_buf *)local_2c,'\0');
          *(int *)(ancs_c + 0x10f8) = *(int *)(ancs_c + 0x10f8) + 1;
        }
        iVar2 = bt_ancs_cp_write(ancs_c,local_2c._4_2_,func);
        *(undefined4 *)(ancs_c + 0x1104) = *(undefined4 *)(ancs_c + 0x10f8);
        return iVar2;
      }
    }
    return -0xc;
  }
  return -0x10;
}


