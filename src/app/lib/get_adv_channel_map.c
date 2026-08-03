/*
 * Function: get_adv_channel_map
 * Entry:    00084914
 * Prototype: uint8_t __stdcall get_adv_channel_map(uint32_t options)
 */


/* exclude_from_export_ai */

uint8_t get_adv_channel_map(uint32_t options)

{
  byte bVar1;
  
  if ((options & 0x8000) == 0) {
    bVar1 = 7;
  }
  else {
    bVar1 = 6;
  }
  if ((int)(options << 0xf) < 0) {
    bVar1 = bVar1 & 5;
  }
  if ((int)(options << 0xe) < 0) {
    bVar1 = bVar1 & 0xfb;
  }
  return bVar1;
}


