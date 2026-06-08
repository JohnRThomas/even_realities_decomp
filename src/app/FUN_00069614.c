/*
 * Function: $_FUN_00069614
 * Entry:    00069614
 * Prototype: undefined __stdcall $_FUN_00069614(undefined4 param_1, int param_2, undefined4 param_3, uint param_4)
 */


void __FUN_00069614(undefined4 param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int16_t **ppiVar4;
  bool bVar5;
  nrfx_pdm_evt_t local_14;
  
  uVar3 = Peripherals::PDM0_S.EVENTS_STARTED;
  local_14._9_3_ = SUB43(param_4 >> 8,0);
  local_14._1_3_ = SUB43((uint)param_2 >> 8,0);
  if (uVar3 == 0) {
    uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
    iVar1 = param_2;
    uVar2 = param_4;
    if (uVar3 != 0) {
      Peripherals::PDM0_S.EVENTS_STOPPED = 0;
      uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
      Peripherals::PDM0_S.ENABLE = 0;
      nrfx_pdm_m_cb.op_state = NRFX_PDM_STATE_IDLE;
      local_14.buffer_released = nrfx_pdm_m_cb.buff_address[nrfx_pdm_m_cb.active_buffer];
      local_14._8_4_ = (uint)(uint3)local_14._9_3_ << 8;
      local_14._0_4_ = (uint)(uint3)local_14._1_3_ << 8;
      if (local_14.buffer_released != (int16_t *)0x0) {
        nrfx_pdm_m_cb.buff_address[nrfx_pdm_m_cb.active_buffer] = (int16_t *)0x0;
        (*nrfx_pdm_m_cb.event_handler)(&local_14);
      }
      local_14.buffer_released = nrfx_pdm_m_cb.buff_address[~(uint)nrfx_pdm_m_cb.active_buffer & 1];
      if (local_14.buffer_released != (int16_t *)0x0) {
        nrfx_pdm_m_cb.buff_address[~(uint)nrfx_pdm_m_cb.active_buffer & 1] = (int16_t *)0x0;
        (*nrfx_pdm_m_cb.event_handler)(&local_14);
      }
      nrfx_pdm_m_cb.active_buffer = '\0';
      iVar1 = local_14._0_4_;
      uVar2 = local_14._8_4_;
    }
    goto LAB_0006968c;
  }
  Peripherals::PDM0_S.EVENTS_STARTED = 0;
  uVar3 = Peripherals::PDM0_S.EVENTS_STARTED;
  uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
  if (uVar3 != 0) {
    Peripherals::PDM0_S.EVENTS_STOPPED = 0;
    uVar3 = Peripherals::PDM0_S.EVENTS_STOPPED;
  }
  uVar3 = ~(uint)nrfx_pdm_m_cb.active_buffer & 1;
  if ((nrfx_pdm_m_cb.buff_address[uVar3] == (int16_t *)0x0) &&
     (nrfx_pdm_m_cb.op_state != NRFX_PDM_STATE_STARTING)) {
    iVar1 = param_2;
    uVar3 = param_4;
    if (nrfx_pdm_m_cb.error == '\0') {
      local_14._0_4_ = (uint)(uint3)local_14._1_3_ << 8;
      local_14.error = 1;
      nrfx_pdm_m_cb.error = '\x01';
      local_14.buffer_released = (int16_t *)0x0;
      goto LAB_0006967c;
    }
  }
  else {
    bVar5 = nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_STARTING;
    if (bVar5) {
      ppiVar4 = (int16_t **)0x1;
    }
    else {
      ppiVar4 = nrfx_pdm_m_cb.buff_address + (nrfx_pdm_m_cb.active_buffer - 1);
    }
    if (bVar5) {
      nrfx_pdm_m_cb.op_state = (nrfx_pdm_state_t)ppiVar4;
      local_14.buffer_released = (int16_t *)0x2;
    }
    else {
      local_14.buffer_released = ppiVar4[1];
      ppiVar4[1] = (int16_t *)0x0;
    }
    local_14._8_4_ = param_4 & 0xffffff00;
    nrfx_pdm_m_cb.error = '\0';
    if (bVar5) {
      local_14.buffer_released = (int16_t *)0x0;
    }
    else {
      nrfx_pdm_m_cb.active_buffer = (uint8_t)uVar3;
    }
    local_14.buffer_requested = true;
LAB_0006967c:
    (*nrfx_pdm_m_cb.event_handler)(&local_14);
    iVar1 = local_14._0_4_;
    uVar3 = local_14._8_4_;
  }
  local_14._8_4_ = uVar3;
  local_14._0_4_ = iVar1;
  iVar1 = local_14._0_4_;
  uVar2 = local_14._8_4_;
  if (nrfx_pdm_m_cb.op_state == NRFX_PDM_STATE_STARTING) {
    nrfx_pdm_m_cb.op_state = NRFX_PDM_STATE_RUNNING;
  }
LAB_0006968c:
  local_14._8_4_ = uVar2;
  local_14._0_4_ = iVar1;
  if (nrfx_pdm_m_cb.irq_buff_request != '\0') {
    local_14.buffer_requested = true;
    local_14.buffer_released = (int16_t *)0x0;
    local_14._8_4_ = local_14._8_4_ & 0xffffff00;
    nrfx_pdm_m_cb.irq_buff_request = '\0';
    (*nrfx_pdm_m_cb.event_handler)(&local_14);
  }
  return;
}


