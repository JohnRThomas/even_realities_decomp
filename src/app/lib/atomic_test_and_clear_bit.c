/*
 * Function: atomic_test_and_clear_bit
 * Entry:    00086976
 * Prototype: bool __stdcall atomic_test_and_clear_bit(atomic_t * target, int bit)
 */


/* exclude_from_export */

bool atomic_test_and_clear_bit(atomic_t *target,int bit)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 1 << (bit & 0xffU);
  uVar2 = *target;
  *target = uVar2 & ~uVar1;
  return (uVar1 & uVar2) != 0;
}


