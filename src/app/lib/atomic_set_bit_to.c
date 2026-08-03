/*
 * Function: atomic_set_bit_to
 * Entry:    00084b6c
 * Prototype: void __stdcall atomic_set_bit_to(atomic_t * target, int bit, bool val)
 */


/* exclude_from_export */

void atomic_set_bit_to(atomic_t *target,int bit,bool val)

{
  *target = *target & bit;
  return;
}


