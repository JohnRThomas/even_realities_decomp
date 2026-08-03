/*
 * Function: zcbor_simple_decode
 * Entry:    00089782
 * Prototype: bool __stdcall zcbor_simple_decode(zcbor_state_t * state, uint8_t result)
 */


/* exclude_from_export */

bool zcbor_simple_decode(zcbor_state_t *state,uint8_t result)

{
  bool bVar1;
  int iVar2;
  zcbor_decoder_t in_r3;
  zcbor_state_t *in_stack_00000000;
  void *in_stack_00000004;
  size_t in_stack_00000008;
  
  iVar2 = ZCBOR_CHECK_ERROR((int *)state,(int *)&DAT_00000007);
  if (iVar2 != 0) {
    if ((*(state->field0_0x0).payload_mut & 0x1f) < 0x19) {
      bVar1 = value_extract((size_t)state,(uint)result,(size_t *)&DAT_00000001,in_r3,
                            in_stack_00000000,in_stack_00000004,in_stack_00000008);
      return bVar1;
    }
    zcbor_error((int)state,10);
  }
  return false;
}


