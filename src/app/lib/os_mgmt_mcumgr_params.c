/*
 * Function: os_mgmt_mcumgr_params
 * Entry:    00055724
 * Prototype: int __stdcall os_mgmt_mcumgr_params(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int os_mgmt_mcumgr_params(smp_streamer *ctxt)

{
  bool bVar1;
  zcbor_state_t *state;
  zcbor_string local_10;
  
  local_10.value = "buf_size";
  state = (zcbor_state_t *)(ctxt->writer + 4);
  local_10.len = 8;
  bVar1 = zcbor_tstr_encode(state,&local_10);
  if ((bVar1) && (bVar1 = zcbor_uint32_encode(state,(uint32_t *)&DAT_000009ab), bVar1)) {
    local_10.value = "buf_count";
    local_10.len = 9;
    bVar1 = zcbor_tstr_encode(state,&local_10);
    if ((bVar1) && (bVar1 = zcbor_uint32_encode(state,(uint32_t *)&Reset), bVar1)) {
      return 0;
    }
  }
  return 7;
}


