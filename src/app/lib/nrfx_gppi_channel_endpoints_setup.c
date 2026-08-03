/*
 * Function: nrfx_gppi_channel_endpoints_setup
 * Entry:    0008888c
 * Prototype: void __stdcall nrfx_gppi_channel_endpoints_setup(uint8_t channel, uint32_t eep, uint32_t tep)
 */


/* exclude_from_export */

void nrfx_gppi_channel_endpoints_setup(uint8_t channel,uint32_t eep,uint32_t tep)

{
  nrfx_gppi_event_endpoint_setup(channel,eep);
  nrfx_gppi_task_endpoint_setup(channel,tep);
  return;
}


