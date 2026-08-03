/*
 * Function: __nrfy_internal_twim_event_handle
 * Entry:    00088b28
 * Prototype: bool __stdcall __nrfy_internal_twim_event_handle(NRF_TWIM_Type * p_reg, uint32_t mask, nrf_twim_event_t event, uint32_t * p_evt_mask)
 */


/* exclude_from_export */

bool __nrfy_internal_twim_event_handle
               (NRF_TWIM_Type *p_reg,uint32_t mask,nrf_twim_event_t event,uint32_t *p_evt_mask)

{
  uint uVar1;
  
  uVar1 = 1 << (event - 0x100U >> 2 & 0xff);
  if (((uVar1 & mask) != 0) && (*(int *)(p_reg->opaque + event) != 0)) {
    *(undefined4 *)(p_reg->opaque + event) = 0;
    *p_evt_mask = *p_evt_mask | uVar1;
  }
  return SUB41(p_reg,0);
}


