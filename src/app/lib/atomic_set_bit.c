/*
 * Function: atomic_set_bit
 * Entry:    00086848
 * Prototype: void __stdcall atomic_set_bit(atomic_t * target, int bit)
 */


/* exclude_from_export */

void atomic_set_bit(atomic_t *target,int bit)

{
  *target = *target | 1 << (bit & 0xffU);
  return;
}


