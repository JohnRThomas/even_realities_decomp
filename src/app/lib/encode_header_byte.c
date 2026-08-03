/*
 * Function: encode_header_byte
 * Entry:    00089984
 * Prototype: bool __stdcall encode_header_byte(zcbor_state_t * state, zcbor_major_type_t major_type, uint8_t additional)
 */


/* exclude_from_export_ai */

bool encode_header_byte(zcbor_state_t *state,zcbor_major_type_t major_type,uint8_t additional)

{
  bool bVar1;
  int extraout_r1;
  int err;
  uint extraout_r2;
  byte *pbVar2;
  
  bVar1 = zcbor_check_error(*(zcbor_state_t **)((int)&state->constant_state + 2));
  if (bVar1) {
    pbVar2 = (state->field0_0x0).payload_mut;
    if (pbVar2 < state->payload_end) {
      if (extraout_r2 < 32) {
        (state->field0_0x0).payload_mut = pbVar2 + 1;
        *pbVar2 = (byte)extraout_r2 | (byte)(extraout_r1 << 5);
        return true;
      }
      err = 0xe;
    }
    else {
      err = 8;
    }
    zcbor_error(state,err);
  }
  return false;
}


