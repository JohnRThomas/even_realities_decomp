/*
 * Function: __nrfy_internal_twim_events_process
 * Entry:    00088b4a
 * Prototype: uint32_t __stdcall __nrfy_internal_twim_events_process(NRF_TWIM_Type * p_reg, uint32_t mask, nrfy_twim_xfer_desc_t * p_xfer)
 */


/* exclude_from_export */

uint32_t __nrfy_internal_twim_events_process
                   (NRF_TWIM_Type *p_reg,uint32_t mask,nrfy_twim_xfer_desc_t *p_xfer)

{
  bool bVar1;
  uint32_t *p_evt_mask;
  uint32_t *p_evt_mask_00;
  uint32_t *p_evt_mask_01;
  uint32_t *p_evt_mask_02;
  uint32_t *p_evt_mask_03;
  uint32_t *p_evt_mask_04;
  uint32_t local_c;
  
  local_c = 0;
  bVar1 = __nrfy_internal_twim_event_handle(p_reg,mask,0x148,&local_c);
  bVar1 = __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x104,p_evt_mask);
  bVar1 = __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x124,p_evt_mask_00);
  bVar1 = __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x150,p_evt_mask_01);
  bVar1 = __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x14c,p_evt_mask_02);
  bVar1 = __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x160,p_evt_mask_03);
  __nrfy_internal_twim_event_handle((NRF_TWIM_Type *)(uint)bVar1,mask,0x15c,p_evt_mask_04);
  return local_c;
}


