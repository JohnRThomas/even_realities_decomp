/*
 * Function: rx_timeout
 * Entry:    00088336
 * Prototype: void __stdcall rx_timeout(k_timer * timer)
 */


/* exclude_from_export */

void rx_timeout(k_timer *timer)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  size_t len;
  int iVar4;
  undefined4 *puVar5;
  device *dev;
  bool bVar6;
  
  puVar5 = (undefined4 *)timer->user_data;
  if (*(char *)(puVar5[3] + 0xce) != '\0') {
    return;
  }
  dev = (device *)*puVar5;
  *(undefined4 *)(*(int *)dev->config + 0x308) = 0x10;
  iVar4 = puVar5[3];
  iVar3 = *(int *)(iVar4 + 0xb8);
  bVar6 = *(int *)(iVar4 + 0x6c) != iVar3;
  if (bVar6) {
    *(int *)(iVar4 + 0x6c) = iVar3;
    iVar4 = puVar5[3];
    iVar3 = *(int *)(iVar4 + 0x74);
  }
  if (bVar6) {
    *(int *)(iVar4 + 0x7c) = iVar3;
  }
  iVar4 = puVar5[3];
  len = *(int *)(iVar4 + 0x6c) - *(int *)(iVar4 + 0x70);
  if ((int)len < 0) {
    *(int *)(iVar4 + 0xb8) = *(int *)(iVar4 + 0x70);
    uVar1 = *(uint *)(puVar5[3] + 0x5c);
    uVar2 = *(uint *)(puVar5[3] + 0x60);
    if (uVar2 <= uVar1) goto LAB_00088382;
LAB_0008839a:
    len = uVar1 - uVar2;
    if ((int)len < 1) goto LAB_00088382;
    bVar6 = true;
  }
  else {
    uVar1 = *(uint *)(iVar4 + 0x5c);
    uVar2 = *(uint *)(iVar4 + 0x60);
    if (uVar1 < len + uVar2) goto LAB_0008839a;
    if (len == 0) goto LAB_00088382;
    bVar6 = false;
    if (*(int *)(iVar4 + 0x78) <= *(int *)(iVar4 + 0x7c)) {
      *(int *)(iVar4 + 0x7c) = *(int *)(iVar4 + 0x7c) - *(int *)(iVar4 + 0x78);
      goto LAB_00088382;
    }
  }
  notify_uart_rx_rdy(dev,len);
  *(size_t *)(puVar5[3] + 0x60) = *(int *)(puVar5[3] + 0x60) + len;
  *(size_t *)(puVar5[3] + 0x70) = *(int *)(puVar5[3] + 0x70) + len;
  if (bVar6) {
    z_impl_k_timer_stop((k_timer *)(puVar5[3] + 0x80));
  }
LAB_00088382:
  *(undefined4 *)(*(int *)dev->config + 0x304) = 0x10;
  return;
}


