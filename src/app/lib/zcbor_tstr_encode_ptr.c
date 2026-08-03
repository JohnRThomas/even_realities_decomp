/*
 * Function: zcbor_tstr_encode_ptr
 * Entry:    00084156
 * Prototype: bool __stdcall zcbor_tstr_encode_ptr(void * state, char * string, size_t size)
 */


/* exclude_from_export */

bool zcbor_tstr_encode_ptr(void *state,char *string,size_t size)

{
  bool bVar1;
  zcbor_string local_10;
  size_t sStack_8;
  
  local_10.value = string;
  local_10.len = size;
  sStack_8 = size;
  bVar1 = zcbor_tstr_encode(state,&local_10);
  return bVar1;
}


