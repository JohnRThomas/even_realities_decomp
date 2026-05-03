/*
 * Function: $_?_value_extract
 * Entry:    0008971c
 * Prototype: bool __stdcall $_?_value_extract(zcbor_state_t * state, void * result, size_t result_len)
 */


bool ____value_extract(zcbor_state_t *state,void *result,size_t result_len)

{
  bool bVar1;
  int iVar2;
  zcbor_decoder_t decoder;
  zcbor_state_t *in_stack_00000000;
  void *in_stack_00000004;
  size_t in_stack_00000008;
  
  iVar2 = ZCBOR_CHECK_ERROR((int *)state,(int *)0x0);
  if (iVar2 != 0) {
    bVar1 = zcbor_multi_decode((size_t)state,(size_t)result,(size_t *)result_len,decoder,
                               in_stack_00000000,in_stack_00000004,in_stack_00000008);
    return bVar1;
  }
  return false;
}


