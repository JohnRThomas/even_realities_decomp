/*
 * Function: FUN_00025134
 * Entry:    00025134
 * Prototype: undefined4 __stdcall FUN_00025134(int param_1)
 */


undefined4 FUN_00025134(int param_1)

{
  void *pvVar1;
  
  pvVar1 = memset((void *)(param_1 + 0x1128),0xff,0x11c);
  flash_settings_write_and_verify(0x135000,pvVar1,0x11c);
  return 0;
}


