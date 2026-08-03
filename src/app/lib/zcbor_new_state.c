/*
 * Function: zcbor_new_state
 * Entry:    000894a2
 * Prototype: void __stdcall zcbor_new_state(zcbor_state_t * state_array, size_t n_states, uint8_t * payload, size_t payload_len, size_t elem_count)
 */


/* exclude_from_export_ai */

void zcbor_new_state(zcbor_state_t *state_array,size_t n_states,uint8_t *payload,size_t payload_len,
                    size_t elem_count)

{
  int iVar1;
  
  (state_array->field0_0x0).payload_mut = payload;
  state_array->elem_count = elem_count;
  state_array->payload_end = payload + payload_len;
  state_array->indefinite_length_array = false;
  state_array->payload_moved = false;
  if (n_states < 2) {
    *(undefined4 *)((int)&state_array->constant_state + 2) = 0;
  }
  else {
    iVar1 = n_states * 0x18 + -0x18;
    *(int *)((int)&state_array->constant_state + 2) = (int)state_array + iVar1;
    *(undefined4 *)((int)state_array + iVar1) = 0;
    *(size_t *)(*(int *)((int)&state_array->constant_state + 2) + 8) = n_states - 2;
    *(undefined4 *)(*(int *)((int)&state_array->constant_state + 2) + 4) = 0;
    *(undefined4 *)(*(int *)((int)&state_array->constant_state + 2) + 0xc) = 0;
    *(undefined1 *)(*(int *)((int)&state_array->constant_state + 2) + 0x10) = 0;
    if (n_states != 2) {
      **(undefined4 **)((int)&state_array->constant_state + 2) =
           (undefined1 *)((int)&state_array[1].field0_0x0 + 2);
    }
  }
  return;
}


