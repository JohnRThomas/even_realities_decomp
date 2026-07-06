/*
 * Function: metal_device_close
 * Entry:    0006b550
 * Prototype: undefined4 __stdcall metal_device_close(void)
 */


undefined4 metal_device_close(void)

{
  *(int **)((int)DAT_20002c80 + 4) = DAT_20002c84;
  *DAT_20002c84 = (int)DAT_20002c80;
  DAT_20002c80 = &DAT_20002c80;
  DAT_20002c84 = (int *)&DAT_20002c80;
  if (DAT_20002c60 != (code *)0x0) {
    (*DAT_20002c60)();
  }
  if ((6 < DAT_2000be0c) && (DAT_2000be10 != (code *)0x0)) {
    (*DAT_2000be10)(7,"unregistered %s bus\n",DAT_20002c5c);
  }
  return 0;
}


