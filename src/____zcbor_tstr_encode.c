/*
 * Function: $_?_zcbor_tstr_encode
 * Entry:    00089aee
 * Prototype: bool __stdcall $_?_zcbor_tstr_encode(zcbor_state_t * state, zcbor_string * input)
 */


bool ____zcbor_tstr_encode(zcbor_state_t *state,zcbor_string *input)

{
  bool bVar1;
  
  bVar1 = str_encode(state,input,3);
  return bVar1;
}


