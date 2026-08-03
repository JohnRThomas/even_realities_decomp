/*
 * Function: zcbor_check_error
 * Entry:    0008995e
 * Prototype: bool __stdcall zcbor_check_error(zcbor_state_t * state)
 */


/* exclude_from_export */

bool zcbor_check_error(zcbor_state_t *state)

{
  if ((state != (zcbor_state_t *)0x0) && (state->indefinite_length_array != false)) {
    return state->payload_end == (uint8_t *)0x0;
  }
  return true;
}


