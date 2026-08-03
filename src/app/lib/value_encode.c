/*
 * Function: value_encode
 * Entry:    000899b8
 * Prototype: bool __stdcall value_encode(zcbor_state_t * state, zcbor_major_type_t major_type, void * input, size_t max_result_len)
 */


/* exclude_from_export */

bool value_encode(zcbor_state_t *state,zcbor_major_type_t major_type,void *input,
                 size_t max_result_len)

{
  bool bVar1;
  uint8_t *puVar2;
  size_t sVar3;
  byte additional;
  char cVar4;
  uint8_t *puVar5;
  
  sVar3 = get_result_len(input,max_result_len);
  puVar5 = (state->field0_0x0).payload_mut;
  puVar2 = state->payload_end;
  if (sVar3 == 1) {
    additional = *(byte *)input;
    if (additional < 0x18) {
      if (puVar2 < puVar5 + 1) goto LAB_000748a6;
      sVar3 = 0;
      goto LAB_00074888;
    }
    if (puVar2 < puVar5 + 2) {
LAB_000748a6:
      zcbor_error(state,8);
      return false;
    }
LAB_0007487c:
    cVar4 = '\0';
  }
  else {
    if (puVar2 < puVar5 + sVar3 + 1) goto LAB_000748a6;
    if (sVar3 == 0) {
      additional = *(byte *)input;
      goto LAB_00074888;
    }
    if (6 < sVar3 - 2) goto LAB_0007487c;
    cVar4 = "NS"[sVar3 + 1];
  }
  additional = cVar4 + 0x18;
LAB_00074888:
  bVar1 = encode_header_byte(state,major_type,additional);
  if (!bVar1) {
    return false;
  }
  puVar2 = (uint8_t *)(sVar3 + (int)input);
  while (puVar2 != input) {
    puVar5 = (state->field0_0x0).payload_mut;
    (state->field0_0x0).payload_mut = puVar5 + 1;
    puVar2 = puVar2 + -1;
    *puVar5 = *puVar2;
  }
  state->elem_count = state->elem_count + 1;
  return true;
}


