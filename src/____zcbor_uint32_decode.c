/*
 * Function: $_?_zcbor_uint32_decode
 * Entry:    0008973c
 * Prototype: bool __stdcall $_?_zcbor_uint32_decode(zcbor_state_t * state, uint32_t * result)
 */


bool ____zcbor_uint32_decode(zcbor_state_t *state,uint32_t *result)

{
  bool bVar1;
  
  bVar1 = ____value_extract(state,result,4);
  return bVar1;
}


