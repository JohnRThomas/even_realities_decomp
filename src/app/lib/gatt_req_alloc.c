/*
 * Function: gatt_req_alloc
 * Entry:    0005c96c
 * Prototype: bt_att_req * __stdcall gatt_req_alloc(bt_att_func_t func, void * params, bt_att_encode_t encode, uint8_t op, size_t len)
 */


/* exclude_from_export_ai */

bt_att_req *
gatt_req_alloc(bt_att_func_t func,void *params,bt_att_encode_t encode,uint8_t op,size_t len)

{
  k_tid_t puVar1;
  int iVar2;
  bt_att_req *pbVar3;
  k_timeout_t timeout;
  void *local_14;
  bt_att_encode_t puStack_10;
  
  local_14 = (void *)0x0;
  puStack_10 = encode;
  puVar1 = k_current_get();
  if (DAT_2000b87c == puVar1) {
    params = (bt_att_func_t)0x0;
    func = params;
  }
  timeout.ticks._4_4_ = params;
  timeout.ticks._0_4_ = func;
  iVar2 = k_mem_slab_alloc((k_mem_slab *)&DAT_20003938,&local_14,timeout);
  if (iVar2 == 0) {
    pbVar3 = memset(local_14,0,0x1c);
  }
  else {
    pbVar3 = (bt_att_req *)0x0;
  }
  return pbVar3;
}


