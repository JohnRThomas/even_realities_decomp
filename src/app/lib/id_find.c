/*
 * Function: id_find
 * Entry:    00057f94
 * Prototype: int __stdcall id_find(bt_addr_le_t * addr)
 */


/* exclude_from_export */

int id_find(bt_addr_le_t *addr)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  bt_addr_le_t *b;
  uint uVar4;
  
  b = (bt_addr_le_t *)&bt_dev;
  uVar4 = (uint)DAT_20002007;
  uVar1 = 0;
  do {
    uVar3 = uVar1;
    if (uVar4 <= (uVar3 & 0xff)) {
      return -2;
    }
    bVar2 = bt_addr_le_eq(addr,b);
    b = b + 1;
    uVar1 = uVar3 + 1;
  } while (!bVar2);
  return uVar3;
}


