/*
 * Function: FUN_00051160
 * Entry:    00051160
 * Prototype: undefined __stdcall FUN_00051160(char * param_1)
 */


void FUN_00051160(char *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  DAT_2000aac0 = 1;
  for (; " gyroscope full-scale\r\n" < param_1; param_1 = (char *)((uint)param_1 >> 1)) {
    bVar1 = true;
    DAT_2000aac0 = DAT_2000aac0 << 1;
  }
  if (!bVar1) {
    DAT_2000aac0 = 1;
  }
  DAT_2000aac4 = param_1;
  return;
}


