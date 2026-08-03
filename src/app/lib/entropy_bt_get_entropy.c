/*
 * Function: entropy_bt_get_entropy
 * Entry:    0008704e
 * Prototype: int __stdcall entropy_bt_get_entropy(void * buf, size_t len)
 */


/* exclude_from_export */

int entropy_bt_get_entropy(void *buf,size_t len)

{
  bool bVar1;
  int iVar2;
  size_t in_r2;
  
  bVar1 = bt_is_ready();
  if (bVar1) {
    iVar2 = bt_hci_le_rand((void *)len,in_r2);
    return iVar2;
  }
  return -11;
}


