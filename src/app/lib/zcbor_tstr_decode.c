/*
 * Function: zcbor_tstr_decode
 * Entry:    0008974c
 * Prototype: bool __stdcall zcbor_tstr_decode(zcbor_state_t * state, zcbor_string * result)
 */


/* exclude_from_export */

bool zcbor_tstr_decode(zcbor_state_t *state,zcbor_string *result)

{
  bool bVar1;
  
  bVar1 = str_decode(state,result,ZCBOR_MAJOR_TYPE_TSTR);
  return bVar1;
}


