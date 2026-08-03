/*
 * Function: zcbor_int_decode
 * Entry:    0008966c
 * Prototype: bool __stdcall zcbor_int_decode(zcbor_state_t * state, void * result_int, size_t int_size)
 */


/* exclude_from_export_ai */

bool zcbor_int_decode(zcbor_state_t *state,void *result_int,size_t int_size)

{
  bool bVar1;
  int iVar2;
  uint8_t *puVar3;
  zcbor_state_t *in_r3;
  zcbor_decoder_t decoder;
  void *unaff_r4;
  size_t unaff_r5;
  
  iVar2 = ZCBOR_CHECK_ERROR((int *)state,(int *)int_size);
  if ((iVar2 != 0) &&
     (bVar1 = value_extract((size_t)state,(int)result_int + 4,(size_t *)&Reset,decoder,in_r3,
                            unaff_r4,unaff_r5), bVar1)) {
    puVar3 = (state->field0_0x0).payload_mut;
    *(uint8_t **)result_int = puVar3;
    if (*(uint *)((int)result_int + 4) <= (uint)((int)state->payload_end - (int)puVar3)) {
      return true;
    }
    err_restore(state,8);
  }
  return false;
}


