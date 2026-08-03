/*
 * Function: atomic_and
 * Entry:    00084660
 * Prototype: atomic_val_t __stdcall atomic_and(atomic_t * target, atomic_val_t value)
 */


/* exclude_from_export */

atomic_val_t atomic_and(atomic_t *target,atomic_val_t value)

{
  *target = *target & value;
  return (atomic_val_t)target;
}


