/*
 * Function: os_mgmt_echo
 * Entry:    0005577c
 * Prototype: int __stdcall os_mgmt_echo(smp_streamer * ctxt)
 */


/* exclude_from_export_ai */

int os_mgmt_echo(smp_streamer *ctxt)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  size_t sStack_40;
  zcbor_string local_3c;
  zcbor_string local_34;
  char *local_2c;
  undefined4 local_28;
  code *local_24;
  zcbor_string *pzStack_20;
  undefined1 local_1c;
  
  puVar3 = ctxt->writer;
  local_2c = "d";
  local_3c.value = (undefined *)0x0;
  local_3c.len = 0;
  local_24 = (code *)0x8974d;
  local_1c = 0;
  local_28 = 1;
  pzStack_20 = &local_3c;
  iVar2 = zcbor_map_decode_bulk
                    ((zcbor_state_t *)(ctxt->reader + 4),(zcbor_map_decode_key_val *)&local_2c,1,
                     &sStack_40);
  if (iVar2 == 0) {
    local_34.value = "r";
    local_34.len = 1;
    bVar1 = zcbor_tstr_encode((zcbor_state_t *)(puVar3 + 4),&local_34);
    if ((!bVar1) ||
       (bVar1 = zcbor_tstr_encode((zcbor_state_t *)(puVar3 + 4),&local_3c), iVar2 = 0, !bVar1)) {
      iVar2 = 7;
    }
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}


