/*
 * Function: FUN_00080d76
 * Entry:    00080d76
 * Prototype: undefined __stdcall FUN_00080d76(int param_1)
 */


void FUN_00080d76(int param_1)

{
  jdb_panel_context *pjVar1;
  void *buf;
  
  pjVar1 = get_jdb_panel_context();
  buf = (void *)pjVar1->field9_0x24;
  memset(buf,param_1,64000);
  FUN_0004af6c(0,0,buf,0xf000);
  FUN_0004af6c(0,0xc0,buf,0xf000);
  FUN_0004af6c(0,0x180,buf,0x7800);
  return;
}


