/*
 * Function: img_mgmt_reset_upload
 * Entry:    00055290
 * Prototype: void __stdcall img_mgmt_reset_upload(void)
 */


/* exclude_from_export_ai */

void img_mgmt_reset_upload(void)

{
  void *pvVar1;
  
  pvVar1 = memset(&DAT_2000b560,0,0x2c);
  *(undefined4 *)((int)pvVar1 + -4) = 0xffffffff;
  return;
}


