/*
 * Function: uarte_nrfx_rx_buf_rsp
 * Entry:    00088082
 * Prototype: int __stdcall uarte_nrfx_rx_buf_rsp(device * dev, uint8_t * buf, size_t len)
 */


/* exclude_from_export_ai */

int uarte_nrfx_rx_buf_rsp(device *dev,uint8_t *buf,size_t len)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 uVar6;
  
  puVar5 = dev->data;
  iVar3 = *(int *)dev->config;
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
  if (*(int *)(iVar4 + 0x58) == 0) {
    iVar3 = -0xd;
  }
  else if (*(int *)(iVar4 + 100) == 0) {
    *(uint8_t **)(iVar4 + 100) = buf;
    *(size_t *)(*(int *)(puVar5 + 0xc) + 0x68) = len;
    *(uint8_t **)(iVar3 + 0x534) = buf;
    *(size_t *)(iVar3 + 0x538) = len;
    *(uint *)(iVar3 + 0x200) = *(uint *)(iVar3 + 0x200) | 0x20;
    iVar3 = 0;
  }
  else {
    iVar3 = -0x10;
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(uVar6);
  }
  InstructionSynchronizationBarrier(0xf);
  return iVar3;
}


