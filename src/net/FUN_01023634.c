/*
 * Function: FUN_01023634
 * Entry:    01023634
 * Prototype: uint __stdcall FUN_01023634(undefined4 param_1, undefined4 param_2)
 */


uint FUN_01023634(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_010250d0();
  uVar2 = (uint)DAT_21001739;
  uVar1 = 0;
  do {
    if ((&DAT_21001740)[uVar1 * 2 + (uint)DAT_21001739 * 0x40] == '\0') {
      (&DAT_210017c0)[uVar1 * 8] = param_1;
      (&DAT_210017c4)[uVar1 * 8] = param_2;
      (&DAT_21001740)[(uVar1 + uVar2 * 0x20) * 2] = 1;
      return uVar1 & 0xff;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0x20);
  return 0x20;
}


