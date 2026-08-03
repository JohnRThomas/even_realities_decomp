/*
 * Function: os_mgmt_bootloader_info
 * Entry:    000557e4
 * Prototype: int __stdcall os_mgmt_bootloader_info(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int os_mgmt_bootloader_info(smp_streamer *ctxt)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  zcbor_state_t *state;
  size_t local_40;
  void *local_3c;
  uint local_38;
  zcbor_string local_34;
  char *local_2c;
  undefined4 local_28;
  code *local_24;
  void **ppvStack_20;
  undefined1 local_1c;
  
  puVar3 = ctxt->writer;
  local_28 = 5;
  ppvStack_20 = &local_3c;
  local_24 = (code *)0x8974d;
  local_3c = (void *)0x0;
  local_38 = 0;
  local_1c = 0;
  local_2c = "query";
  iVar2 = zcbor_map_decode_bulk
                    ((zcbor_state_t *)(ctxt->reader + 4),(zcbor_map_decode_key_val *)&local_2c,1,
                     &local_40);
  state = (zcbor_state_t *)(puVar3 + 4);
  if (iVar2 == 0) {
    if (local_40 == 0) {
      local_34.value = "bootloader";
      local_34.len = 10;
      bVar1 = zcbor_tstr_encode(state,&local_34);
      if (bVar1) {
        local_34.value = "MCUboot";
        local_34.len = 7;
        bVar1 = zcbor_tstr_encode(state,&local_34);
LAB_0005584a:
        if (bVar1 != false) {
          return 0;
        }
      }
    }
    else {
      bVar1 = zcbor_map_decode_bulk_key_found((zcbor_map_decode_key_val *)&local_2c,1,"query");
      local_34.len = local_38;
      if (((!bVar1) || (local_38 != 4)) || (iVar2 = memcmp("mode",local_3c,4), iVar2 != 0))
      goto LAB_00055818;
      local_34.value = "mode";
      bVar1 = zcbor_tstr_encode(state,&local_34);
      if (bVar1) {
        bVar1 = zcbor_int32_encode(state,(int32_t *)&DAT_00000003);
        goto LAB_0005584a;
      }
    }
    iVar2 = 7;
  }
  else {
LAB_00055818:
    iVar2 = 3;
  }
  return iVar2;
}


