/*
 * Function: spim_abort
 * Entry:    00088a6a
 * Prototype: void __stdcall spim_abort(NRF_SPIM_Type * p_spim, spim_control_block_t * p_cb)
 */


/* exclude_from_export */

void spim_abort(NRF_SPIM_Type *p_spim,spim_control_block_t *p_cb)

{
  uint32_t uVar1;
  int iVar2;
  
  iVar2 = 100;
  p_spim[5] = 1;
  do {
    uVar1 = __nrfy_internal_spim_events_process(p_spim,2,(nrfy_spim_xfer_desc_t *)0x0);
    if (uVar1 != 0) break;
    arch_busy_wait(1);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)((int)p_cb + 0x1d) = 0;
  p_spim[0x140] = 0;
  return;
}


