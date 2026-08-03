/*
 * Function: __nrfy_internal_spim_event_handle
 * Entry:    000889c4
 * Prototype: bool __stdcall __nrfy_internal_spim_event_handle(NRF_SPIM_Type * p_reg, uint32_t mask, nrf_spim_event_t event, uint32_t * p_evt_mask)
 */


/* exclude_from_export */

bool __nrfy_internal_spim_event_handle
               (NRF_SPIM_Type *p_reg,uint32_t mask,nrf_spim_event_t event,uint32_t *p_evt_mask)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 1 << (event - 0x100U >> 2 & 0xff);
  bVar1 = false;
  if (((uVar2 & mask) != 0) && (bVar1 = false, *(int *)((int)p_reg + event) != 0)) {
    bVar1 = true;
    *(undefined4 *)((int)p_reg + event) = 0;
    *p_evt_mask = *p_evt_mask | uVar2;
  }
  return bVar1;
}


