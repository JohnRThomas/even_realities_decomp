/*
 * Function: zcbor_bstr_encode
 * Entry:    00089ae8
 * Prototype: bool __stdcall zcbor_bstr_encode(zcbor_state_t * state, zcbor_string * input)
 */


/* exclude_from_export_ai */

bool zcbor_bstr_encode(zcbor_state_t *state,zcbor_string *input)

{
  bool bVar1;
  
  bVar1 = str_encode(state,input,ZCBOR_MAJOR_TYPE_BSTR);
  return bVar1;
}


