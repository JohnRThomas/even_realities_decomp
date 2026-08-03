/*
 * Function: str_encode
 * Entry:    000899d8
 * Prototype: bool __stdcall str_encode(zcbor_state_t * state, zcbor_string * input, zcbor_major_type_t major_type)
 */


/* exclude_from_export */

bool str_encode(zcbor_state_t *state,zcbor_string *input,zcbor_major_type_t major_type)

{
  bool bVar1;
  size_t sVar2;
  uint8_t *puVar3;
  uint uVar4;
  uint8_t *puVar5;
  
  puVar3 = (state->field0_0x0).payload_mut;
  puVar5 = state->payload_end;
  if (((puVar3 < puVar5) && (uVar4 = input->len, uVar4 <= (uint)((int)puVar5 - (int)puVar3))) &&
     ((input->value == (undefined *)0x0 ||
      (sVar2 = get_result_len(&input->len,4), puVar3 + sVar2 + uVar4 + 1 <= puVar5)))) {
    bVar1 = value_encode(state,major_type,&input->len,4);
    if (bVar1) {
      if ((state->field0_0x0).payload_mut != input->value) {
        memmove((state->field0_0x0).payload_mut,input->value,input->len);
      }
      (state->field0_0x0).payload_mut = (state->field0_0x0).payload_mut + input->len;
      return true;
    }
  }
  else {
    zcbor_error(state,8);
  }
  return false;
}


