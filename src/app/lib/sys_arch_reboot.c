/*
 * Function: sys_arch_reboot
 * Entry:    00053da4
 * Prototype: void __stdcall sys_arch_reboot(int type)
 */


/* exclude_from_export */

void sys_arch_reboot(int type)

{
  DataSynchronizationBarrier(0xf);
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


