/*
 * Function: FUN_0102f068
 * Entry:    0102f068
 * Prototype: undefined __stdcall FUN_0102f068(undefined1 * param_1)
 */


void FUN_0102f068(undefined1 *param_1)

{
  bool bVar1;
  
  bVar1 = false;
  DAT_21004670 = 1;
  for (; &DAT_000f4240 < param_1; param_1 = (undefined1 *)((uint)param_1 >> 1)) {
    bVar1 = true;
    DAT_21004670 = DAT_21004670 << 1;
  }
  if (!bVar1) {
    DAT_21004670 = 1;
  }
  DAT_21004674 = param_1;
  return;
}


