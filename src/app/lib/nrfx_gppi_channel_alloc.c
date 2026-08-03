/*
 * Function: nrfx_gppi_channel_alloc
 * Entry:    0004f430
 * Prototype: nrfx_err_t __stdcall nrfx_gppi_channel_alloc(uint8_t * p_channel)
 */


/* exclude_from_export_ai */

nrfx_err_t nrfx_gppi_channel_alloc(uint8_t *p_channel)

{
  nrfx_err_t nVar1;
  undefined4 in_r1;
  sbyte local_9 [5];
  
  local_9[0] = (sbyte)((uint)in_r1 >> 0x18);
  nVar1 = gppi_channel_alloc((uint8_t *)local_9);
  if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
    Peripherals::IPC_S.RECEIVE_CNF_10_ = 0x400;
    Peripherals::IPC_S.SEND_CNF_11_ = 0x800;
    nrfx_gppi_task_endpoint_setup(local_9[0],(uint32_t)&Peripherals::IPC_S.TASKS_SEND_11_);
    nrfx_gppi_event_endpoint_setup(local_9[0],(uint32_t)&Peripherals::IPC_S.EVENTS_RECEIVE_10_);
    nrfx_gppi_channels_enable(1 << local_9[0]);
    nVar1 = NRFX_SUCCESS;
  }
  else {
    nVar1 = ~NRFX_ERROR_BUSY;
  }
  return nVar1;
}


