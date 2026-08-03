/*
 * Function: uarte_nrfx_poll_out
 * Entry:    000882e2
 * Prototype: void __stdcall uarte_nrfx_poll_out(device * dev, uchar c)
 */


/* exclude_from_export_ai */

void uarte_nrfx_poll_out(device *dev,uchar c)

{
  bool bVar1;
  uint uVar2;
  uint8_t uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  puVar5 = dev->data;
  uVar6 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar6 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar4 = *(int *)(puVar5 + 0xc);
  *(uint *)(iVar4 + 0xc0) = *(uint *)(iVar4 + 0xc0) & ~(uint)c;
  iVar4 = *(int *)(puVar5 + 0xc);
  if (*(int *)(iVar4 + 0xc0) == 0) {
    if (c == 2) {
      uVar3 = rx_flush((device *)dev->config,(uint8_t *)(iVar4 + 0xc4),5);
      *(uint8_t *)(iVar4 + 0xc9) = uVar3;
    }
    *(undefined4 *)(*(int *)dev->config + 0x500) = 0;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return;
}


