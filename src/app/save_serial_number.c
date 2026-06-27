/*
 * Function: ?_save_serial_number
 * Entry:    00025348
 * Prototype: int __stdcall ?_save_serial_number(char * serial_num)
 */


int __save_serial_number(char *serial_num)

{
  snprintf(SERIAL_NUMBER,16,"%s",serial_num);
  return 0;
}


