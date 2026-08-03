/*
 * Function: img_mgmt_translate_error_code
 * Entry:    00055270
 * Prototype: int __stdcall img_mgmt_translate_error_code(uint16_t err)
 */


/* exclude_from_export_ai */

int img_mgmt_translate_error_code(uint16_t err)

{
  int iVar1;
  
  if ((ushort)(err - 3) < 0x1a) {
    iVar1 = (int)(char)(&DAT_000f084d)[(ushort)(err - 3)];
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}


