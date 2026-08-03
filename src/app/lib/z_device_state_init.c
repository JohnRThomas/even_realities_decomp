/*
 * Function: z_device_state_init
 * Entry:    000748dc
 * Prototype: void __stdcall z_device_state_init(void)
 */


/* exclude_from_export */

void z_device_state_init(void)

{
  char *test;
  char *file;
  undefined **ppuVar1;
  int line;
  
  ppuVar1 = &PTR_s_clock_5000_0008b2e0;
  while( true ) {
    if (&PTR_0008b550 < ppuVar1) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","dev <= _device_list_end",
              "WEST_TOPDIR/zephyr/kernel/device.c",0x17);
      _ASSERT("\tunexpected list end location\n",test,file,line);
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((undefined **)((int)&PTR_0008b54c + 3U) < ppuVar1) break;
    ppuVar1 = ppuVar1 + 6;
  }
  return;
}


