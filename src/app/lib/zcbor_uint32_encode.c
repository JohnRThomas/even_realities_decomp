/*
 * Function: zcbor_uint32_encode
 * Entry:    00089ad0
 * Prototype: bool __stdcall zcbor_uint32_encode(zcbor_state_t * state, uint32_t * input)
 */


/* exclude_from_export_ai */

bool zcbor_uint32_encode(zcbor_state_t *state,uint32_t *input)

{
  bool bVar1;
  uint32_t *local_c [2];
  
  local_c[0] = input;
  bVar1 = zcbor_uint_encode(state,local_c,4);
  return bVar1;
}


