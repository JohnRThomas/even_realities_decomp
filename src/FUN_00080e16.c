/*
 * Function: FUN_00080e16
 * Entry:    00080e16
 * Prototype: undefined __stdcall FUN_00080e16(void)
 */


void FUN_00080e16(void)

{
  busy_wait_seconds(1);
  FUN_00080ece(0x66);
  busy_wait_seconds(1);
  FUN_00080ece(0x99);
  busy_wait_seconds(10);
  return;
}


