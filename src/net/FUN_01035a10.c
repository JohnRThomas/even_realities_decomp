/*
 * Function: FUN_01035a10
 * Entry:    01035a10
 * Prototype: undefined4 __stdcall FUN_01035a10(undefined4 * param_1)
 */


undefined4 FUN_01035a10(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((((char *)*param_1 == (char *)0x0) || (*(char *)*param_1 == '\0')) || (1 < (uint)param_1[2]))
  {
    uVar2 = 0xffffffea;
  }
  else {
    param_1[1] = &DAT_21000724;
    param_1[0x12] = DAT_21004b20;
    param_1[0x11] = &DAT_21004b1c;
    uVar2 = 0;
    puVar1 = param_1 + 0x11;
    *DAT_21004b20 = param_1 + 0x11;
    DAT_21004b20 = puVar1;
  }
  return uVar2;
}


