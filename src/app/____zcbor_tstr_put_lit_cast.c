/*
 * Function: $_?_zcbor_tstr_put_lit_cast
 * Entry:    00084156
 * Prototype: bool __stdcall $_?_zcbor_tstr_put_lit_cast(void * state, char * string, size_t size)
 */


bool ____zcbor_tstr_put_lit_cast(void *state,char *string,size_t size)

{
  bool bVar1;
  zcbor_string local_10;
  size_t sStack_8;
  
  local_10.value = string;
  local_10.len = size;
  sStack_8 = size;
  bVar1 = ____zcbor_tstr_encode(state,&local_10);
  return bVar1;
}


