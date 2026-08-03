/*
 * Function: uarte_nrfx_rx_disable
 * Entry:    0008818a
 * Prototype: int __stdcall uarte_nrfx_rx_disable(device * dev)
 */


/* exclude_from_export_ai */

int uarte_nrfx_rx_disable(device *dev)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = dev->data;
  iVar2 = *(int *)dev->config;
  if (*(int *)(*(int *)(puVar3 + 0xc) + 0x58) == 0) {
    iVar1 = -0xe;
  }
  else {
    if (*(int *)(*(int *)(puVar3 + 0xc) + 100) != 0) {
      *(uint *)(iVar2 + 0x200) = *(uint *)(iVar2 + 0x200) & 0xffffffdf;
      *(undefined4 *)(iVar2 + 0x14c) = 0;
    }
    z_impl_k_timer_stop((k_timer *)(*(int *)(puVar3 + 0xc) + 0x80));
    iVar1 = 0;
    *(undefined1 *)(*(int *)(puVar3 + 0xc) + 0xca) = 0;
    *(undefined1 *)(*(int *)(puVar3 + 0xc) + 0xcb) = 1;
    *(undefined4 *)(iVar2 + 4) = 1;
  }
  return iVar1;
}


