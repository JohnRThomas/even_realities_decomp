/*
 * Function: list_map_end_decode
 * Entry:    000895a6
 * Prototype: bool __stdcall list_map_end_decode(zcbor_state_t * state)
 */


/* exclude_from_export */

bool list_map_end_decode(zcbor_state_t *state)

{
  bool bVar1;
  size_t max_elem_count;
  
  max_elem_count = 0;
  if (state->indefinite_length_array != false) {
    bVar1 = array_end_expect(state);
    if (!bVar1) {
      return bVar1;
    }
    max_elem_count = 0xffffffff;
    state->indefinite_length_array = false;
  }
  bVar1 = zcbor_process_backup(state,7,max_elem_count);
  return bVar1;
}


