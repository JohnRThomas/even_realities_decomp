/*
 * Function: ?_dump_serial_number
 * Entry:    00025364
 * Prototype: undefined4 __stdcall ?_dump_serial_number(char * param_1)
 */


undefined4 __dump_serial_number(char *param_1)

{
  snprintf((char *)&DAT_20003006,0x10,"%s",param_1);
  return 0;
}


