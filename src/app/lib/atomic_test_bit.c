/*
 * Function: atomic_test_bit
 * Entry:    000867ae
 * Prototype: bool __stdcall atomic_test_bit(atomic_t * target, int bit)
 */


/* exclude_from_export */

bool atomic_test_bit(atomic_t *target,int bit)

{
  return (bool)((byte)(*target >> (bit & 0xffU)) & 1);
}


