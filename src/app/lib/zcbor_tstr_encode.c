/*
 * Function: zcbor_tstr_encode
 * Entry:    00089aee
 * Prototype: bool __stdcall zcbor_tstr_encode(zcbor_state_t * state, zcbor_string * input)
 */


/* exclude_from_export */

bool zcbor_tstr_encode(zcbor_state_t *state,zcbor_string *input)

{
  bool bVar1;
  
  bVar1 = str_encode(state,input,ZCBOR_MAJOR_TYPE_TSTR);
  return bVar1;
}


