/*
 * Function: zcbor_uint_decode
 * Entry:    0008971c
 * Prototype: bool __stdcall zcbor_uint_decode(zcbor_state_t * state, void * result, size_t result_len)
 */


/* exclude_from_export */

bool zcbor_uint_decode(zcbor_state_t *state,void *result,size_t result_len)

{
  bool bVar1;
  int iVar2;
  zcbor_decoder_t decoder;
  zcbor_state_t *in_stack_00000000;
  void *in_stack_00000004;
  size_t in_stack_00000008;
  
  iVar2 = ZCBOR_CHECK_ERROR((int *)state,(int *)0x0);
  if (iVar2 != 0) {
    bVar1 = value_extract((size_t)state,(size_t)result,(size_t *)result_len,decoder,
                          in_stack_00000000,in_stack_00000004,in_stack_00000008);
    return bVar1;
  }
  return false;
}


