/*
 * Function: FUN_00080d76
 * Entry:    00080d76
 * Prototype: undefined __stdcall FUN_00080d76(int param_1)
 */


void FUN_00080d76(int param_1)

{
  undefined1 *puVar1;
  void *buf;
  
  puVar1 = __get_something_from_glasses_state();
  buf = *(void **)(puVar1 + 0x24);
  memset(buf,param_1,64000);
  FUN_0004af6c(0,0,buf,0xf000);
  FUN_0004af6c(0,0xc0,buf,0xf000);
  FUN_0004af6c(0,0x180,buf,0x7800);
  return;
}


