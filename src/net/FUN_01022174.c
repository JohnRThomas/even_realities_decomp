/*
 * Function: FUN_01022174
 * Entry:    01022174
 * Prototype: uint __stdcall FUN_01022174(int param_1, int param_2)
 */


uint FUN_01022174(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  
  if (2 < param_1) {
    return 0xf;
  }
  if (param_1 < -0x27) {
    uVar2 = 0;
  }
  else {
    bVar1 = (&DAT_0103c6fc)[(char)((char)param_1 + '(')];
    uVar2 = (uint)bVar1;
    if ((char)(&DAT_0103c728)[uVar2] != param_1) {
      if (param_2 != 0) {
        bVar1 = bVar1 + 1;
      }
      return (uint)bVar1;
    }
  }
  return uVar2;
}


