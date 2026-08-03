/*
 * Function: abort_function
 * Entry:    00083f0a
 * Prototype: undefined __stdcall abort_function(void)
 */


/* exclude_from_export */

void abort_function(void)

{
                    /* WARNING: Subroutine does not return */
  sys_reboot(0);
}


