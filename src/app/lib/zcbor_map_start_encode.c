/*
 * Function: zcbor_map_start_encode
 * Entry:    00089afc
 * Prototype: bool __stdcall zcbor_map_start_encode(zcbor_state_t * state, size_t max_num)
 */


/* exclude_from_export_ai */

bool zcbor_map_start_encode(zcbor_state_t *state,size_t max_num)

{
  bool bVar1;
  
  bVar1 = encode_header_byte(state,ZCBOR_MAJOR_TYPE_MAP,31);
  return bVar1;
}


