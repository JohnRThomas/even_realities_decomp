/*
 * Function: FUN_0102f108
 * Entry:    0102f108
 * Prototype: undefined __stdcall FUN_0102f108(void)
 */


void FUN_0102f108(void)

{
  bool bVar1;
  undefined4 extraout_r3;
  
  bVar1 = FUN_0103b8b0(0x103bf44);
  if (!bVar1) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/zephyr/subsys/logging/backends/log_backend_uart.c",0x7f,extraout_r3);
    FUN_0103a370();
  }
  return;
}


