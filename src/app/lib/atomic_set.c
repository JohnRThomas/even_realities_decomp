/*
 * Function: atomic_set
 * Entry:    000822e6
 * Prototype: atomic_val_t __stdcall atomic_set(atomic_t * target, atomic_val_t value)
 */


/* exclude_from_export */

atomic_val_t atomic_set(atomic_t *target,atomic_val_t value)

{
  *target = value;
  return (atomic_val_t)target;
}


