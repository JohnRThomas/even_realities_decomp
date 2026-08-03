/*
 * Function: zcbor_list_end_encode
 * Entry:    00089b04
 * Prototype: bool __stdcall zcbor_list_end_encode(zcbor_state_t * state, size_t max_num)
 */


/* exclude_from_export_ai */

bool zcbor_list_end_encode(zcbor_state_t *state,size_t max_num)

{
  bool bVar1;
  
  bVar1 = encode_header_byte(state,ZCBOR_MAJOR_TYPE_SIMPLE,31);
  return bVar1;
}


