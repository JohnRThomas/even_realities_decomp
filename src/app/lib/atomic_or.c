/*
 * Function: atomic_or
 * Entry:    00084622
 * Prototype: atomic_val_t __stdcall atomic_or(atomic_t * target, atomic_val_t value)
 */


/* exclude_from_export */

atomic_val_t atomic_or(atomic_t *target,atomic_val_t value)

{
  uint uVar1;
  
  uVar1 = *target;
  *target = uVar1 | value;
  return uVar1;
}


