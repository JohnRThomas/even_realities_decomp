/*
 * Function: get_adv_type
 * Entry:    00084a6a
 * Prototype: uint8_t __stdcall get_adv_type(uint8_t evt_type)
 */


/* exclude_from_export_ai */

uint8_t get_adv_type(uint8_t evt_type)

{
  uint8_t uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(evt_type + 4);
  uVar1 = (uint8_t)(uVar2 & 8);
  if ((uVar2 & 8) != 0) {
    if (-1 < (int)(uVar2 << 0xd)) {
      if ((uVar2 & 0x600) == 0x400) {
        uVar1 = '\x01';
      }
      else {
        uVar1 = '\x02';
      }
      return uVar1;
    }
    uVar1 = '\x01';
  }
  return uVar1;
}


