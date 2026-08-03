/*
 * Function: zcbor_bstr_decode
 * Entry:    00089746
 * Prototype: bool __stdcall zcbor_bstr_decode(zcbor_state_t * state, zcbor_string * result)
 */


/* exclude_from_export */

bool zcbor_bstr_decode(zcbor_state_t *state,zcbor_string *result)

{
  bool bVar1;
  
  bVar1 = str_decode(state,result,ZCBOR_MAJOR_TYPE_BSTR);
  return bVar1;
}


