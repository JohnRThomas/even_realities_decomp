/*
 * Function: fixed_data_alloc
 * Entry:    000620e8
 * Prototype: uint8_t * __stdcall fixed_data_alloc(net_buf * buf, size_t * size, k_timeout_t timeout)
 */


/* exclude_from_export_ai */

uint8_t * fixed_data_alloc(net_buf *buf,size_t *size,k_timeout_t timeout)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  puVar2 = *(uint **)(*(int *)(&DAT_20003c48 + (uint)buf->pool_id * 0x34) + 4);
  if (*puVar2 < *size) {
    *size = *puVar2;
  }
  else {
    *size = *size;
  }
  uVar4 = *puVar2;
  uVar3 = puVar2[1];
  iVar1 = net_buf_id(buf);
  return (uint8_t *)(uVar4 * iVar1 + uVar3);
}


