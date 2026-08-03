/*
 * Function: atomic_get
 * Entry:    00084e5a
 * Prototype: atomic_val_t __stdcall atomic_get(atomic_t * target)
 */


/* exclude_from_export */

atomic_val_t atomic_get(atomic_t *target)

{
  return *target;
}


