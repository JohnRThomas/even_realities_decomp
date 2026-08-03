/*
 * Function: list_map_start_decode
 * Entry:    000896b6
 * Prototype: bool __stdcall list_map_start_decode(zcbor_state_t * state, zcbor_major_type_t exp_major_type)
 */


/* exclude_from_export */

bool list_map_start_decode(zcbor_state_t *state,zcbor_major_type_t exp_major_type)

{
  bool bVar1;
  int iVar2;
  size_t in_r2;
  uint decoder;
  zcbor_state_t *state_00;
  int *input;
  
  input = (int *)(uint)exp_major_type;
  state_00 = state;
  iVar2 = ZCBOR_CHECK_ERROR((int *)state,input);
  if (iVar2 != 0) {
    decoder = *(state->field0_0x0).payload_mut & 0x1f;
    if (decoder == 0x1f) {
      input = (int *)0xffffffef;
      if (state->elem_count == 0) {
        zcbor_error((int)state,3);
        return false;
      }
      (state->field0_0x0).payload_mut = (state->field0_0x0).payload_mut + 1;
      state->elem_count = state->elem_count - 1;
    }
    else {
      bVar1 = value_extract((size_t)state,(size_t)&stack0xffffffec,(size_t *)&Reset,decoder,state_00
                            ,input,in_r2);
      if (!bVar1) {
        return false;
      }
      iVar2 = 0;
    }
    bVar1 = zcbor_new_backup(state,(size_t)input);
    if (bVar1) {
      state->indefinite_length_array = SUB41(iVar2,0);
      return true;
    }
    state->field0_0x0 = (zcbor_state_t_union)state->payload_bak;
    state->elem_count = state->elem_count + 1;
  }
  return false;
}


