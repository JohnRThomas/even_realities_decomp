/*
 * Function: zcbor_uint_encode
 * Entry:    00089a9e
 * Prototype: bool __stdcall zcbor_uint_encode(zcbor_state_t * state, void * input_uint, size_t uint_size)
 */


/* exclude_from_export_ai */

bool zcbor_uint_encode(zcbor_state_t *state,void *input_uint,size_t uint_size)

{
  bool bVar1;
  
  if (uint_size != 0) {
    bVar1 = value_encode(state,ZCBOR_MAJOR_TYPE_PINT,input_uint,uint_size);
    return bVar1;
  }
  zcbor_error(state,0xe);
  return false;
}


