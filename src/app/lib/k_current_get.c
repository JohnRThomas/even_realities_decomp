/*
 * Function: k_current_get
 * Entry:    00077b54
 * Prototype: k_tid_t __stdcall k_current_get(void)
 */


/* exclude_from_export */

k_tid_t k_current_get(void)

{
  return (k_tid_t)_current.base;
}


