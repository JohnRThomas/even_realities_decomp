/*
 * Function: $_?_get_result_len
 * Entry:    00074834
 * Prototype: size_t __stdcall $_?_get_result_len(void * input, size_t max_result_len)
 */


size_t ____get_result_len(void *input,size_t max_result_len)

{
  uint uVar1;
  sbyte sVar2;
  
  do {
    uVar1 = max_result_len;
    if (uVar1 == 0) {
      return 0;
    }
    max_result_len = uVar1 - 1;
  } while (*(char *)((int)input + (uVar1 - 1)) == '\0');
  if (2 < uVar1) {
    if (uVar1 - 2 < 7) {
      sVar2 = "NS"[uVar1 + 1];
    }
    else {
      sVar2 = 0;
    }
    uVar1 = 1 << sVar2;
  }
  return uVar1;
}


