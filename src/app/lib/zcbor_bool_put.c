/*
 * Function: zcbor_bool_put
 * Entry:    00089b28
 * Prototype: bool __stdcall zcbor_bool_put(zcbor_state_t * state, bool * input)
 */


/* exclude_from_export_ai */

bool zcbor_bool_put(zcbor_state_t *state,bool *input)

{
  bool bVar1;
  undefined1 local_9 [5];
  
  bVar1 = value_encode(state,ZCBOR_MAJOR_TYPE_SIMPLE,local_9,1);
  return bVar1;
}


