/*
 * Function: z_sys_poweroff
 * Entry:    0004f770
 * Prototype: void __stdcall z_sys_poweroff(void)
 */


/* exclude_from_export */

void z_sys_poweroff(void)

{
  Peripherals::OSCILLATORS_S._1280_4_ = 1;
  DataSynchronizationBarrier(0xf);
  do {
    WaitForEvent();
  } while( true );
}


