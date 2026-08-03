/*
 * Function: z_SysNmiOnReset
 * Entry:    0005341c
 * Prototype: void __stdcall z_SysNmiOnReset(void)
 */


/* exclude_from_export_ai */

void z_SysNmiOnReset(void)

{
  do {
    WaitForInterrupt();
  } while( true );
}


