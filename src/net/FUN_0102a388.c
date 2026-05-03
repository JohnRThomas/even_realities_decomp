/*
 * Function: FUN_0102a388
 * Entry:    0102a388
 * Prototype: undefined4 __stdcall FUN_0102a388(int param_1)
 */


undefined4 FUN_0102a388(int param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  bVar1 = FUN_0102a338(param_1);
  if (bVar1) {
    FUN_0102a34e(param_1);
    cVar2 = FUN_010236bc((uint)*(byte *)(param_1 + 4));
    if (cVar2 == '\0') {
      FUN_01009500(0xb,0x205,extraout_r2,extraout_r3);
    }
    *(undefined1 *)(param_1 + 0x10) = 0;
  }
  return 0;
}


