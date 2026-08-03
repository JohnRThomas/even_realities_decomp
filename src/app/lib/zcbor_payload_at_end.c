/*
 * Function: zcbor_payload_at_end
 * Entry:    000894e6
 * Prototype: bool __stdcall zcbor_payload_at_end(zcbor_state_t * state)
 */


/* exclude_from_export_ai */

bool zcbor_payload_at_end(zcbor_state_t *state)

{
  if (state->indefinite_length_array == false) {
    return state->elem_count == 0;
  }
  if ((state->field0_0x0).payload_mut < state->payload_end) {
    return *(state->field0_0x0).payload_mut == 0xff;
  }
  return false;
}


