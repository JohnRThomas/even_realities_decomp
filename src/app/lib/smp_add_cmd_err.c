/*
 * Function: smp_add_cmd_err
 * Entry:    000548b8
 * Prototype: bool __stdcall smp_add_cmd_err(zcbor_state_t * zse, uint16_t group, uint16_t ret)
 */


/* exclude_from_export_ai */

bool smp_add_cmd_err(zcbor_state_t *zse,uint16_t group,uint16_t ret)

{
  bool bVar1;
  zcbor_string local_18;
  
  if ((uint32_t *)(uint)ret == (uint32_t *)0x0) {
    bVar1 = true;
  }
  else {
    *(uint16_t *)&zse[2].payload_bak = group;
    local_18.value = "err";
    *(uint16_t *)((int)&zse[2].payload_bak + 2) = ret;
    local_18.len = 3;
    bVar1 = zcbor_tstr_encode(zse,&local_18);
    if ((bVar1) && (bVar1 = zcbor_map_start_encode(zse,2), bVar1)) {
      local_18.value = "group";
      local_18.len = 5;
      bVar1 = zcbor_tstr_encode(zse,&local_18);
      if ((bVar1) && (bVar1 = zcbor_uint32_encode(zse,(uint32_t *)(uint)group), bVar1)) {
        local_18.value = "rc";
        local_18.len = 2;
        bVar1 = zcbor_tstr_encode(zse,&local_18);
        if ((bVar1) && (bVar1 = zcbor_uint32_encode(zse,(uint32_t *)(uint)ret), bVar1)) {
          bVar1 = zcbor_map_end_encode(zse,2);
          return bVar1;
        }
      }
    }
    bVar1 = false;
  }
  return bVar1;
}


