/*
 * Function: net_buf_id
 * Entry:    000620c4
 * Prototype: int __stdcall net_buf_id(net_buf * buf)
 */


/* exclude_from_export */

int net_buf_id(net_buf *buf)

{
  int iVar1;
  
  iVar1 = (uint)buf->pool_id * 0x34;
  return (uint)((int)buf - *(int *)(&DAT_20003c4c + iVar1)) /
         ((byte)(&DAT_20003c40)[iVar1] + 0x1b & 0xfffffffc);
}


