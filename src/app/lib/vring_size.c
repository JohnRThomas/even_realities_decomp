/*
 * Function: vring_size
 * Entry:    00082386
 * Prototype: int __stdcall vring_size(uint num, ulong align)
 */


/* exclude_from_export_ai */

int vring_size(uint num,ulong align)

{
  return ((align * num + 3 & 0xfffffffc) + (num * 0x12 + 9 & 0xfffffffc) + num * 8 + 8) * 2;
}


