/*
 * Function: metal_finish
 * Entry:    0006b528
 * Prototype: undefined __stdcall metal_finish(void)
 */


void metal_finish(void)

{
  metal_device_close();
  memset(&DAT_2000be0c,0,0x20);
  return;
}


