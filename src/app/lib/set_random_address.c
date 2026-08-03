/*
 * Function: set_random_address
 * Entry:    000848ba
 * Prototype: int __stdcall set_random_address(bt_addr_t * addr)
 */


/* exclude_from_export_ai */

int set_random_address(bt_addr_t *addr)

{
  int iVar1;
  int extraout_r0;
  uint in_r1;
  net_buf *pnStack_10;
  uint uStack_c;
  
  if (addr == (bt_addr_t *)0x0) {
    iVar1 = -0x16;
  }
  else {
    pnStack_10 = (net_buf *)addr;
    uStack_c = in_r1;
    iVar1 = bt_rand(&pnStack_10,6);
    if (iVar1 == 0) {
      uStack_c = uStack_c & 0xffff3fff;
      le_set_random_address((net_buf *)addr,&pnStack_10);
      iVar1 = extraout_r0;
    }
  }
  return iVar1;
}


