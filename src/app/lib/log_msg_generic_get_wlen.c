/*
 * Function: log_msg_generic_get_wlen
 * Entry:    0008259c
 * Prototype: uint32_t __stdcall log_msg_generic_get_wlen(mpsc_pbuf_generic * item)
 */


/* exclude_from_export */

uint32_t log_msg_generic_get_wlen(mpsc_pbuf_generic *item)

{
  uint uVar1;
  
  if ((int)((uint)*(byte *)item << 0x1d) < 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (((item->raw & 0xfffff) >> 9) + (uint)(*(ushort *)((int)item + 2) >> 4) + 0x17 &
            0xfffffff8) >> 2;
  }
  return uVar1;
}


