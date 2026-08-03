/*
 * Function: atomic_inc
 * Entry:    000825c4
 * Prototype: atomic_val_t __stdcall atomic_inc(atomic_t * target)
 */


/* exclude_from_export */

atomic_val_t atomic_inc(atomic_t *target)

{
  int iVar1;
  
  iVar1 = *target;
  *target = iVar1 + 1;
  return iVar1;
}


