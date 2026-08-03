/*
 * Function: __nrfy_internal_spim_events_process
 * Entry:    000889ee
 * Prototype: uint32_t __stdcall __nrfy_internal_spim_events_process(NRF_SPIM_Type * p_reg, uint32_t mask, nrfy_spim_xfer_desc_t * p_xfer)
 */


/* exclude_from_export */

uint32_t __nrfy_internal_spim_events_process
                   (NRF_SPIM_Type *p_reg,uint32_t mask,nrfy_spim_xfer_desc_t *p_xfer)

{
  uint32_t *p_evt_mask;
  uint32_t *p_evt_mask_00;
  uint32_t local_1c;
  
  local_1c = 0;
  __nrfy_internal_spim_event_handle(p_reg,mask,0x14c,&local_1c);
  __nrfy_internal_spim_event_handle(p_reg,mask,0x104,p_evt_mask);
  __nrfy_internal_spim_event_handle(p_reg,mask,0x118,p_evt_mask_00);
  __nrfy_internal_spim_event_handle(p_reg,mask,0x110,&local_1c);
  __nrfy_internal_spim_event_handle(p_reg,mask,0x120,&local_1c);
  return local_1c;
}


