/*
 * Function: img_mgmt_upload_good_rsp
 * Entry:    000552ac
 * Prototype: int __stdcall img_mgmt_upload_good_rsp(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int img_mgmt_upload_good_rsp(smp_streamer *ctxt)

{
  bool bVar1;
  int iVar2;
  zcbor_string local_10;
  
  local_10.value = "off";
  local_10.len = 3;
  bVar1 = zcbor_tstr_encode((zcbor_state_t *)&ctxt->reader,&local_10);
  if ((bVar1) && (bVar1 = zcbor_uint32_encode((zcbor_state_t *)&ctxt->reader,DAT_2000b560), bVar1))
  {
    iVar2 = 0;
  }
  else {
    iVar2 = 7;
  }
  return iVar2;
}


