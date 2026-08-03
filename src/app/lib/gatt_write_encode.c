/*
 * Function: gatt_write_encode
 * Entry:    00085fd2
 * Prototype: int __stdcall gatt_write_encode(net_buf * buf, size_t len, void * user_data)
 */


/* exclude_from_export_ai */

int gatt_write_encode(net_buf *buf,size_t len,void *user_data)

{
  undefined2 *puVar1;
  size_t sVar2;
  int iVar3;
  
  puVar1 = net_buf_add((net_buf *)&(buf->field6_0xc).field0,2);
  *puVar1 = *(undefined2 *)((int)user_data + 4);
  sVar2 = net_buf_append_bytes
                    (buf,(uint)*(ushort *)((int)user_data + 0xc),*(void **)((int)user_data + 8),
                     (k_timeout_t)0x0,(net_buf_allocator_cb)0x0,(void *)0x0);
  if (*(ushort *)((int)user_data + 0xc) == sVar2) {
    iVar3 = 0;
  }
  else {
    iVar3 = -0xc;
  }
  return iVar3;
}


