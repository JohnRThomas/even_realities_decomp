/*
 * Function: zcbor_int32_encode
 * Entry:    00089abc
 * Prototype: bool __stdcall zcbor_int32_encode(zcbor_state_t * state, int32_t * input)
 */


/* exclude_from_export_ai */

bool zcbor_int32_encode(zcbor_state_t *state,int32_t *input)

{
  bool bVar1;
  int32_t *local_c [2];
  
  local_c[0] = input;
  bVar1 = zcbor_int_encode(state,local_c,4);
  return bVar1;
}


