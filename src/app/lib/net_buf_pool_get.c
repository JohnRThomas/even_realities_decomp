/*
 * Function: net_buf_pool_get
 * Entry:    000620b4
 * Prototype: net_buf_pool * __stdcall net_buf_pool_get(int id)
 */


/* exclude_from_export */

net_buf_pool * net_buf_pool_get(int id)

{
  return (net_buf_pool *)(&DAT_20003c1c + id * 0x34);
}


