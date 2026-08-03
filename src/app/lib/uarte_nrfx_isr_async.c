/*
 * Function: uarte_nrfx_isr_async
 * Entry:    000663d4
 * Prototype: void __stdcall uarte_nrfx_isr_async(device * dev)
 */


/* exclude_from_export */

void uarte_nrfx_isr_async(device *dev)

{
  longlong lVar1;
  k_timeout_t period;
  undefined4 extraout_r0;
  uint uVar2;
  undefined4 extraout_r1;
  int iVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined *puVar11;
  bool bVar12;
  k_timeout_t duration;
  undefined1 local_2c [4];
  dword local_28;
  dword dStack_24;
  
  iVar7 = *(int *)dev->config;
  puVar5 = dev->data;
  if (*(int *)(iVar7 + 0x108) != 0) {
    *(undefined4 *)(iVar7 + 0x108) = 0;
    *(int *)(*(int *)(puVar5 + 0xc) + 0xb8) = *(int *)(*(int *)(puVar5 + 0xc) + 0xb8) + 1;
    return;
  }
  if (*(int *)(iVar7 + 0x124) != 0) {
    *(undefined4 *)(iVar7 + 0x124) = 0;
    iVar9 = *(int *)(*(int *)dev->config + 0x480);
    *(int *)(*(int *)dev->config + 0x480) = iVar9;
    memset(local_2c,0,0x14);
    local_2c[0] = 6;
    if (iVar9 << 0x1f < 0) {
      bVar8 = 1;
    }
    else if (iVar9 << 0x1e < 0) {
      bVar8 = 2;
    }
    else if (iVar9 << 0x1d < 0) {
      bVar8 = 4;
    }
    else {
      bVar8 = (byte)iVar9 & 8;
    }
    local_28 = CONCAT31(local_28._1_3_,bVar8);
    user_callback(dev,(uart_event *)local_2c);
    uarte_nrfx_rx_disable(dev);
  }
  if ((*(int *)(iVar7 + 0x110) != 0) && (*(int *)(iVar7 + 0x304) << 0x1b < 0)) {
    *(undefined4 *)(iVar7 + 0x110) = 0;
    puVar5 = dev->data;
    puVar10 = *(undefined4 **)dev->config;
    *(undefined1 *)(*(int *)(puVar5 + 0xc) + 0xce) = 1;
    z_impl_k_timer_stop((k_timer *)(*(int *)(puVar5 + 0xc) + 0x80));
    iVar9 = puVar10[0x14f];
    bVar8 = *(byte *)(*(int *)(puVar5 + 0xc) + 0xc9);
    *(undefined1 *)(*(int *)(puVar5 + 0xc) + 0xc9) = 0;
    iVar3 = *(int *)(puVar5 + 0xc);
    uVar6 = ((uint)bVar8 - *(int *)(iVar3 + 0x60)) + iVar9;
    uVar2 = uVar6 & ~((int)uVar6 >> 0x1f);
    *(uint *)(iVar3 + 0x70) = *(int *)(iVar3 + 0x70) + uVar2;
    if (0 < (int)uVar6) {
      notify_uart_rx_rdy(dev,uVar2);
    }
    iVar9 = *(int *)(puVar5 + 0xc);
    if (*(char *)(iVar9 + 0xca) == '\0') {
      *(undefined1 *)(iVar9 + 0xce) = 0;
    }
    else {
      rx_buf_release(dev,(uint8_t **)(iVar9 + 0x58));
      uVar4 = 0;
      bVar12 = (bool)isCurrentModePrivileged();
      if (bVar12) {
        uVar4 = getBasePriority();
      }
      bVar12 = (bool)isCurrentModePrivileged();
      if ((bVar12) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
        setBasePriority(0x20);
      }
      InstructionSynchronizationBarrier(0xf);
      iVar9 = *(int *)(*(int *)(puVar5 + 0xc) + 100);
      if (iVar9 == 0) {
        puVar10[1] = 1;
      }
      else {
        *(int *)(*(int *)(puVar5 + 0xc) + 0x58) = iVar9;
        *(undefined4 *)(*(int *)(puVar5 + 0xc) + 0x5c) =
             *(undefined4 *)(*(int *)(puVar5 + 0xc) + 0x68);
        *(undefined4 *)(*(int *)(puVar5 + 0xc) + 100) = 0;
        *(undefined4 *)(*(int *)(puVar5 + 0xc) + 0x68) = 0;
        *(undefined4 *)(*(int *)(puVar5 + 0xc) + 0x60) = 0;
        if (puVar10[0x53] == 0) {
          *puVar10 = 1;
        }
        puVar10[0x80] = puVar10[0x80] & 0xffffffdf;
      }
      bVar12 = (bool)isCurrentModePrivileged();
      if (bVar12) {
        setBasePriority(uVar4);
      }
      InstructionSynchronizationBarrier(0xf);
      *(undefined1 *)(*(int *)(puVar5 + 0xc) + 0xce) = 0;
    }
  }
  if ((*(int *)(iVar7 + 0x14c) != 0) && (*(int *)(iVar7 + 0x110) == 0)) {
    *(undefined4 *)(iVar7 + 0x14c) = 0;
    puVar5 = dev->data;
    memset(local_2c,0,0x14);
    local_2c[0] = 3;
    user_callback(dev,(uart_event *)local_2c);
    iVar3 = *(int *)(puVar5 + 0xc);
    iVar9 = *(int *)(iVar3 + 0x74);
    if (iVar9 != -1) {
      *(int *)(iVar3 + 0x7c) = iVar9;
      iVar9 = *(int *)(puVar5 + 0xc);
      uVar2 = *(uint *)(iVar9 + 0x78);
      lVar1 = (longlong)(int)(uVar2 & ~((int)uVar2 >> 0x1f)) * 0x8000 + 999999;
      __aeabi_uldivmod((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),1000000,0);
      period.ticks._4_4_ = extraout_r0;
      period.ticks._0_4_ = extraout_r1;
      duration.ticks._4_4_ = extraout_r0;
      duration.ticks._0_4_ = extraout_r1;
      k_timer_start((k_timer *)(iVar9 + 0x80),duration,period);
    }
  }
  if ((*(int *)(iVar7 + 0x144) != 0) && (*(int *)(iVar7 + 0x110) == 0)) {
    *(undefined4 *)(iVar7 + 0x144) = 0;
    puVar5 = dev->data;
    puVar11 = dev->config;
    rx_buf_release(dev,(uint8_t **)(*(int *)(puVar5 + 0xc) + 0x58));
    rx_buf_release(dev,(uint8_t **)(*(int *)(puVar5 + 0xc) + 100));
    *(undefined1 *)(*(int *)(puVar5 + 0xc) + 0xca) = 0;
    if (*(char *)(*(int *)(puVar5 + 0xc) + 0xcb) != '\0') {
      *(undefined1 *)(*(int *)(puVar5 + 0xc) + 0xcb) = 0;
      rx_flush((device *)dev->config,(uint8_t *)0x0,0);
    }
    if (*(int *)(puVar11 + 4) << 0x1b < 0) {
      uarte_nrfx_poll_out(dev,'\x02');
    }
    notify_rx_disable(dev);
  }
  if ((*(int *)(iVar7 + 0x120) != 0) && (*(int *)(iVar7 + 0x304) << 0x17 < 0)) {
    iVar9 = *(int *)dev->config;
    uVar4 = 0;
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      uVar4 = getBasePriority();
    }
    bVar12 = (bool)isCurrentModePrivileged();
    if ((bVar12) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    if (*(int *)(iVar9 + 0x120) != 0) {
      *(undefined4 *)(iVar9 + 0x120) = 0;
      *(undefined4 *)(iVar9 + 0xc) = 1;
    }
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  if (*(int *)(iVar7 + 0x158) == 0) {
    return;
  }
  if (-1 < *(int *)(iVar7 + 0x304) << 9) {
    return;
  }
  puVar5 = dev->data;
  iVar7 = *(int *)dev->config;
  if (*(int *)((int)dev->config + 4) << 0x1b < 0) {
    *(undefined4 *)(iVar7 + 0x308) = 0x400000;
    uarte_nrfx_poll_out(dev,'\x01');
    if (*(int *)(*(int *)(puVar5 + 0xc) + 0xc) == 0) {
      return;
    }
  }
  if (*(int *)(*(int *)(puVar5 + 0xc) + 8) == 0) {
    return;
  }
  uVar4 = 0;
  bVar12 = (bool)isCurrentModePrivileged();
  if (bVar12) {
    uVar4 = getBasePriority();
  }
  bVar12 = (bool)isCurrentModePrivileged();
  if ((bVar12) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
    setBasePriority(0x20);
  }
  InstructionSynchronizationBarrier(0xf);
  if (*(int *)(*(int *)(puVar5 + 0xc) + 0xbc) < 0) {
    dStack_24 = *(dword *)(iVar7 + 0x54c);
  }
  else {
    dStack_24 = *(dword *)(*(int *)(puVar5 + 0xc) + 0xbc);
  }
  bVar12 = (bool)isCurrentModePrivileged();
  if (bVar12) {
    setBasePriority(uVar4);
  }
  InstructionSynchronizationBarrier(0xf);
  iVar9 = *(int *)(puVar5 + 0xc);
  if (*(char *)(iVar9 + 0xcd) == '\0') {
    if ((*(int *)(iVar9 + 8) != *(int *)(iVar9 + 0x10)) &&
       (bVar12 = *(dword *)(iVar9 + 0x14) == dStack_24,
       dStack_24 = *(int *)(iVar9 + 0x1c) + dStack_24, bVar12)) {
      *(dword *)(iVar9 + 0x1c) = dStack_24;
      iVar9 = setup_tx_cache((int)puVar5);
      if (iVar9 != 0) goto LAB_00066628;
      dStack_24 = *(dword *)(*(int *)(puVar5 + 0xc) + 0x1c);
    }
    z_impl_k_timer_stop((k_timer *)(*(int *)(puVar5 + 0xc) + 0x20));
    memset(local_2c,0,0x14);
    local_28 = *(dword *)(*(int *)(puVar5 + 0xc) + 8);
    if (dStack_24 != *(dword *)(*(int *)(puVar5 + 0xc) + 0xc)) {
      local_2c[0] = 1;
    }
    *(undefined4 *)(iVar7 + 0x308) = 0x400000;
    *(undefined4 *)(*(int *)(puVar5 + 0xc) + 8) = 0;
    *(undefined4 *)(*(int *)(puVar5 + 0xc) + 0xc) = 0;
    user_callback(dev,(uart_event *)local_2c);
  }
  else {
LAB_00066628:
    uVar4 = 0;
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      uVar4 = getBasePriority();
    }
    bVar12 = (bool)isCurrentModePrivileged();
    if ((bVar12) && (uVar2 = getBasePriority(), uVar2 == 0 || 0x20 < uVar2)) {
      setBasePriority(0x20);
    }
    InstructionSynchronizationBarrier(0xf);
    start_tx_locked((int)dev);
    bVar12 = (bool)isCurrentModePrivileged();
    if (bVar12) {
      setBasePriority(uVar4);
    }
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}


