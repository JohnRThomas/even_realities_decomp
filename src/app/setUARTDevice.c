/*
 * Function: setUARTDevice
 * Entry:    00034694
 * Prototype: int __stdcall setUARTDevice(device * param_1)
 */


int setUARTDevice(device *param_1)

{
  if (param_1 != (device *)0x0) {
    if (UART_DEV_PTR != param_1) {
      UART_DEV_PTR = param_1;
    }
    __UART_DEV_STATE = 1;
    return 0;
  }
  return -1;
}


