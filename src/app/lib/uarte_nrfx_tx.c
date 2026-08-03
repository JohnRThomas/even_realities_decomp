/*
 * Function: uarte_nrfx_tx
 * Entry:    00065ccc
 * Prototype: int __stdcall uarte_nrfx_tx(device * dev, uint8_t * buf, size_t len, int32_t timeout)
 */


/* exclude_from_export */

int uarte_nrfx_tx(device *dev,uint8_t *buf,size_t len,int32_t timeout)

{
  bool bVar1;
  uint uVar2;
  longlong lVar3;
  k_timeout_t period;
  uint extraout_r0;
  uint extraout_r1;
  undefined *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  puVar4 = dev->data;
  iVar6 = *(int *)dev->config;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getBasePriority();
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if ((bVar1) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(int *)(*(int *)(puVar4 + 0xc) + 0xc) == 0) {
    *(size_t *)(*(int *)(puVar4 + 0xc) + 0xc) = len;
    *(uint8_t **)(*(int *)(puVar4 + 0xc) + 8) = buf;
    *(undefined4 *)(iVar6 + 0x304) = 0x400000;
    if (((uint)buf & 0xe0000000) == 0x20000000) {
      *(uint8_t **)(*(int *)(puVar4 + 0xc) + 0x10) = buf;
      *(size_t *)(*(int *)(puVar4 + 0xc) + 0x14) = len;
    }
    else {
      *(undefined4 *)(*(int *)(puVar4 + 0xc) + 0x1c) = 0;
      setup_tx_cache((int)puVar4);
    }
    start_tx_locked((int)dev);
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    if ((puVar4[0xb] == '\x01') && (timeout != -1)) {
      lVar3 = (longlong)(timeout & ~(timeout >> 0x1f)) * 0x8000 + 999999;
      __aeabi_uldivmod((int)lVar3,(int)((ulonglong)lVar3 >> 0x20),1000000,0);
      period.ticks._4_4_ = 0;
      period.ticks._0_4_ = extraout_r1;
      k_timer_start((k_timer *)(*(int *)(puVar4 + 0xc) + 0x20),
                    (k_timeout_t)((ulonglong)extraout_r0 << 0x20),period);
    }
    iVar6 = 0;
  }
  else {
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setBasePriority(uVar5);
    }
    InstructionSynchronizationBarrier(0xf);
    iVar6 = -0x10;
  }
  return iVar6;
}


