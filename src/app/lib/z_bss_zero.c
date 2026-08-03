/*
 * Function: z_bss_zero
 * Entry:    00074ad4
 * Prototype: void __stdcall z_bss_zero(void)
 */


/* exclude_from_export */

void z_bss_zero(void)

{
  memset(&ancs_work_thread,0,0x1a4ec);
  return;
}


