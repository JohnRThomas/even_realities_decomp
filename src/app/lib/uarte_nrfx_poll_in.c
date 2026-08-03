/*
 * Function: uarte_nrfx_poll_in
 * Entry:    000880ea
 * Prototype: int __stdcall uarte_nrfx_poll_in(device * dev, uchar * c)
 */


/* exclude_from_export_ai */

int uarte_nrfx_poll_in(device *dev,uchar *c)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)dev->config;
  if (*(int *)(dev->data + 0xc) == 0) {
    if (puVar2[0x44] == 0) {
      iVar1 = -1;
    }
    else {
      *c = **(uchar **)(dev->data + 0x18);
      puVar2[0x44] = 0;
      *puVar2 = 1;
      iVar1 = 0;
    }
  }
  else {
    iVar1 = -0x86;
  }
  return iVar1;
}


