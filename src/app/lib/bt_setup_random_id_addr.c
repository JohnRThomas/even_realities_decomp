/*
 * Function: bt_setup_random_id_addr
 * Entry:    000586a4
 * Prototype: int __stdcall bt_setup_random_id_addr(void)
 */


/* exclude_from_export */

int bt_setup_random_id_addr(void)

{
  int iVar1;
  uint8_t *irk;
  byte bVar2;
  bt_addr_le_t local_30;
  bt_hci_vs_static_addr bStack_28;
  
  if ((DAT_20002007 == 0) &&
     (DAT_20002007 = bt_read_static_addr(&bStack_28,'\x01'), DAT_20002007 != 0)) {
    bVar2 = 0;
    do {
      if ((uint)DAT_20002007 <= (uint)bVar2) {
        return 0;
      }
      bt_addr_copy(&local_30.a,&(&bStack_28)[bVar2].bdaddr);
      local_30.type = '\x01';
      iVar1 = id_create((uint8_t)irk,&local_30,irk);
      bVar2 = bVar2 + 1;
    } while (iVar1 == 0);
    return iVar1;
  }
  iVar1 = bt_id_create((bt_addr_le_t *)0x0,(uint8_t *)0x0);
  return iVar1;
}


