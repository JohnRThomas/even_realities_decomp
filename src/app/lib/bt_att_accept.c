/*
 * Function: bt_att_accept
 * Entry:    0005bbdc
 * Prototype: int __stdcall bt_att_accept(bt_conn * conn, bt_l2cap_chan * * ch)
 */


/* exclude_from_export */

int bt_att_accept(bt_conn *conn,bt_l2cap_chan **ch)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  byte local_30 [4];
  char *local_2c;
  bt_conn *pbStack_28;
  undefined4 *local_20;
  undefined4 *local_1c;
  
  local_1c = (undefined4 *)k_mem_slab_alloc((k_mem_slab *)&DAT_200038d8,&local_20,(k_timeout_t)0x0);
  if (local_1c == (undefined4 *)0x0) {
    DAT_2000b87c = k_current_get();
    puVar1 = local_20;
    memset(local_20 + 1,0,0x34);
    *puVar1 = conn;
    local_20[1] = 0;
    local_20[2] = 0;
    local_20[0xc] = 0;
    local_20[0xd] = 0;
    iVar2 = k_mem_slab_alloc((k_mem_slab *)&DAT_200038f8,&local_1c,(k_timeout_t)0x0);
    if (iVar2 == 0) {
      pvVar3 = memset(local_1c,0,0x198);
      *(undefined **)((int)pvVar3 + 0xc) = &DAT_200029cc;
      k_queue_init((k_queue *)((int)pvVar3 + 0x128));
      puVar1 = local_1c;
      local_1c[0x48] = 0;
      *local_1c = local_20;
      if (local_20[0xc] == 0) {
        k_queue_init((k_queue *)(local_20 + 3));
        local_20[10] = 0;
        local_20[0xb] = 0;
      }
      puVar4 = puVar1 + 100;
      puVar1[100] = local_20[0xc];
      local_20[0xc] = puVar4;
      if (local_20[0xd] == 0) {
        local_20[0xd] = puVar4;
      }
      *(undefined2 *)((int)local_1c + 0x2e) = 0x17;
      *(undefined2 *)((int)local_1c + 0x1e) = 0x17;
      *ch = (bt_l2cap_chan *)(local_1c + 2);
      return 0;
    }
    pbStack_28 = (bt_conn *)*local_20;
    local_2c = "No available ATT channel for conn %p";
    local_30[0] = 3;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1880,local_30);
  }
  else {
    local_2c = "No available ATT context for conn %p";
    local_30[0] = 3;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    pbStack_28 = conn;
    LOG_WRN(&PTR_s_bt_att_0008b8b0,0x1840,local_30);
  }
  return -0xc;
}


