/*
 * Function: $_?_zcbor_bstr_decode
 * Entry:    00089746
 * Prototype: bool __stdcall $_?_zcbor_bstr_decode(zcbor_state_t * state, zcbor_string * result)
 */


bool ____zcbor_bstr_decode(zcbor_state_t *state,zcbor_string *result)

{
  bool bVar1;
  
  bVar1 = str_decode(state,result,2);
  return bVar1;
}


