/*
 * Function: uarte_nrfx_tx_abort
 * Entry:    000883dc
 * Prototype: int __stdcall uarte_nrfx_tx_abort(device * dev)
 */


/* exclude_from_export_ai */

int uarte_nrfx_tx_abort(device *dev)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  
  puVar2 = dev->data;
  iVar3 = *(int *)dev->config;
  iVar1 = *(int *)(puVar2 + 0xc);
  if (*(int *)(iVar1 + 8) == 0) {
    iVar1 = -0xe;
  }
  else {
    *(undefined1 *)(iVar1 + 0xcd) = 0;
    z_impl_k_timer_stop((k_timer *)(*(int *)(puVar2 + 0xc) + 0x20));
    iVar1 = 0;
    *(undefined4 *)(iVar3 + 0xc) = 1;
  }
  return iVar1;
}


