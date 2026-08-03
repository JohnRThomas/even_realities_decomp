/*
 * Function: zcbor_uint32_decode
 * Entry:    0008973c
 * Prototype: bool __stdcall zcbor_uint32_decode(zcbor_state_t * state, uint32_t * result)
 */


/* exclude_from_export */

bool zcbor_uint32_decode(zcbor_state_t *state,uint32_t *result)

{
  bool bVar1;
  
  bVar1 = zcbor_uint_decode(state,result,4);
  return bVar1;
}


