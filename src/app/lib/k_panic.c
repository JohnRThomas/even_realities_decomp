/*
 * Function: k_panic
 * Entry:    00081a84
 * Prototype: void __stdcall k_panic(void)
 */


/* exclude_from_export */

void k_panic(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
  return;
}


