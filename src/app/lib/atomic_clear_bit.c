/*
 * Function: atomic_clear_bit
 * Entry:    00086804
 * Prototype: void __stdcall atomic_clear_bit(atomic_t * target, int bit)
 */


/* exclude_from_export_ai */

void atomic_clear_bit(atomic_t *target,int bit)

{
  *target = *target & ~(1 << (bit & 0xffU));
  return;
}


