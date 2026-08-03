/*
 * Function: uarte_nrfx_err_check
 * Entry:    00087fe2
 * Prototype: int __stdcall uarte_nrfx_err_check(device * dev)
 */


/* exclude_from_export */

int uarte_nrfx_err_check(device *dev)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)dev->config + 0x480);
  *(int *)(*(int *)dev->config + 0x480) = iVar1;
  return iVar1;
}


