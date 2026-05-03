/*
 * Function: FUN_0002c6f4
 * Entry:    0002c6f4
 * Prototype: undefined __stdcall FUN_0002c6f4(uint param_1)
 */


void FUN_0002c6f4(uint param_1)

{
  longlong lVar1;
  
  lVar1 = FUN_0007fea6();
  DAT_20004268 = (int)(lVar1 + (ulonglong)param_1);
  DAT_2000426c = (int)(lVar1 + (ulonglong)param_1 >> 0x20);
  return;
}


