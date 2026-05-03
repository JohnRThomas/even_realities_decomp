/*
 * Function: busy_wait_seconds
 * Entry:    00080ec4
 * Prototype: undefined __stdcall busy_wait_seconds(int param_1)
 */


void busy_wait_seconds(int param_1)

{
  arch_busy_wait(param_1 * 1000);
  return;
}


