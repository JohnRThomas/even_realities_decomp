/*
 * Function: img_mgmt_erase
 * Entry:    0005542c
 * Prototype: int __stdcall img_mgmt_erase(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int img_mgmt_erase(smp_streamer *ctxt)

{
  int iVar1;
  int iVar2;
  uint16_t ret;
  undefined *puVar3;
  int local_34 [2];
  image_version iStack_2c;
  char *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  undefined1 local_14;
  
  local_24 = "slot";
  puVar3 = ctxt->writer;
  local_20 = 4;
  local_34[0] = 1;
  local_34[1] = 0;
  local_1c = 0x8973d;
  local_18 = local_34;
  local_14 = 0;
  iVar1 = zcbor_map_decode_bulk
                    ((zcbor_state_t *)(ctxt->reader + 4),(zcbor_map_decode_key_val *)&local_24,1,
                     (size_t *)(local_34 + 1));
  if (iVar1 == 0) {
    iVar2 = img_mgmt_read_info(local_34[0],&iStack_2c,(uint8_t *)0x0,(uint32_t *)0x0);
    iVar1 = 0;
    if ((iVar2 == 0) && (iVar2 = img_mgmt_slot_in_use(local_34[0]), iVar2 != 0)) {
      ret = 9;
    }
    else {
      iVar2 = img_mgmt_flash_check_empty((uint8_t)local_34[0]);
      img_mgmt_reset_upload();
      if (iVar2 == 0) {
        return 0;
      }
      ret = (uint16_t)iVar2;
    }
    smp_add_cmd_err((zcbor_state_t *)(puVar3 + 4),1,ret);
  }
  else {
    iVar1 = 3;
  }
  return iVar1;
}


