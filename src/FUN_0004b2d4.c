/*
 * Function: FUN_0004b2d4
 * Entry:    0004b2d4
 * Prototype: undefined * __stdcall FUN_0004b2d4(int param_1, int param_2)
 */


undefined * FUN_0004b2d4(int param_1,int param_2)

{
  if (param_1 == 4) {
    memcpy(&DAT_2001deb6,&DAT_0008be47,0x120);
  }
  else {
    if (param_2 < 0) {
      param_2 = param_2 + 3;
    }
    FUN_0004b194((int)(&DAT_000dbb84 + (param_2 >> 2) * param_1),param_2 >> 2,0x2001deb6);
  }
  return &DAT_2001deb6;
}


