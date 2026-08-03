/*
 * Function: zcbor_map_start_decode
 * Entry:    00089752
 * Prototype: bool __stdcall zcbor_map_start_decode(zcbor_state_t * state)
 */


/* exclude_from_export */

bool zcbor_map_start_decode(zcbor_state_t *state)

{
  bool bVar1;
  
  bVar1 = list_map_start_decode(state,ZCBOR_MAJOR_TYPE_MAP);
  if (bVar1) {
    if (state->indefinite_length_array != false) {
      return true;
    }
    if (state->elem_count < 0x7fffffff) {
      state->elem_count = state->elem_count << 1;
      return true;
    }
    err_restore(state,5);
  }
  return false;
}


