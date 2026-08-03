/*
 * Function: str_decode
 * Entry:    000896a0
 * Prototype: bool __stdcall str_decode(zcbor_state_t * state, zcbor_string * result, zcbor_major_type_t exp_major_type)
 */


/* exclude_from_export */

bool str_decode(zcbor_state_t *state,zcbor_string *result,zcbor_major_type_t exp_major_type)

{
  bool bVar1;
  
  bVar1 = zcbor_int_decode(state,result,(uint)exp_major_type);
  if (bVar1) {
    (state->field0_0x0).payload_mut = (state->field0_0x0).payload_mut + result->len;
  }
  return bVar1;
}


