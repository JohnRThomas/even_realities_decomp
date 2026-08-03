/*
 * Function: is_tx_ready
 * Entry:    0008826e
 * Prototype: bool __stdcall is_tx_ready(device * dev)
 */


/* exclude_from_export */

bool is_tx_ready(device *dev)

{
  bool bVar1;
  
  if (*(int *)(dev->name + 0x158) == 0) {
    bVar1 = false;
    if (-1 < (int)dev->config << 0x1e) {
      return *(int *)(dev->name + 0x120) != 0;
    }
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}


