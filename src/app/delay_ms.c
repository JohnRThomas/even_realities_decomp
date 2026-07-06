/*
 * Function: delay_ms
 * Entry:    00080ec4
 * Prototype: undefined __stdcall delay_ms(int param_1)
 */


void delay_ms(int param_1)

{
  arch_busy_wait(param_1 * 1000);
  return;
}


