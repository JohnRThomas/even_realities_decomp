/*
 * Function: net_buf_append_bytes
 * Entry:    000626fc
 * Prototype: size_t __stdcall net_buf_append_bytes(net_buf * buf, size_t len, void * value, k_timeout_t timeout, net_buf_allocator_cb allocate_cb, void * user_data)
 */


/* exclude_from_export */

size_t net_buf_append_bytes
                 (net_buf *buf,size_t len,void *value,k_timeout_t timeout,
                 net_buf_allocator_cb allocate_cb,void *user_data)

{
  k_timeout_t timeout_00;
  net_buf *frag;
  size_t sVar1;
  uint uVar2;
  net_buf_union *buf_00;
  size_t sVar3;
  undefined4 uVar4;
  undefined4 in_stack_0000000c;
  
  uVar4 = (undefined4)((ulonglong)timeout.ticks >> 0x20);
  frag = net_buf_frag_last(buf);
  sVar3 = 0;
  while( true ) {
    buf_00 = &frag->field6_0xc;
    sVar1 = net_buf_simple_tailroom(&buf_00->b);
    uVar2 = len;
    if (sVar1 <= len) {
      uVar2 = net_buf_simple_tailroom(&buf_00->b);
    }
    uVar2 = uVar2 & 0xffff;
    net_buf_add_mem((net_buf *)&buf_00->field0,value,uVar2);
    len = len - uVar2;
    sVar3 = sVar3 + uVar2;
    value = (void *)((int)value + uVar2);
    if (len == 0) {
      return sVar3;
    }
    if (user_data == (void *)0x0) {
      timeout_00.ticks._4_4_ = allocate_cb;
      timeout_00.ticks._0_4_ = uVar4;
      frag = net_buf_alloc_len((net_buf_pool *)(&DAT_20003c1c + (uint)buf->pool_id * 0x34),len,
                               timeout_00);
    }
    else {
      frag = (net_buf *)(*user_data)(uVar4,allocate_cb,in_stack_0000000c);
    }
    if (frag == (net_buf *)0x0) break;
    net_buf_frag_add(buf,frag);
  }
  return sVar3;
}


