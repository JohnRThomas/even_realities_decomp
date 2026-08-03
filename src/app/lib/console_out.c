/*
 * Function: console_out
 * Entry:    00063b90
 * Prototype: int __stdcall console_out(int c)
 */


/* exclude_from_export_ai */

int console_out(int c)

{
  if (c == 10) {
    uarte_nrfx_poll_out(&uart_dev,'\r');
  }
  uarte_nrfx_poll_out(&uart_dev,(uchar)c);
  return c;
}


