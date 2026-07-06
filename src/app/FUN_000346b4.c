/*
 * Function: FUN_000346b4
 * Entry:    000346b4
 * Prototype: int __stdcall FUN_000346b4(int param_1)
 */


int FUN_000346b4(int param_1)

{
  if (param_1 != 0) {
    if (PTR_20002424 != (undefined *)param_1) {
      PTR_20002424 = (undefined *)param_1;
    }
    __UART_DEV_STATE = 0;
    return 0;
  }
  return -1;
}


