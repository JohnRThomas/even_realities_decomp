/*
 * Function: FUN_010386d4
 * Entry:    010386d4
 * Prototype: uint __stdcall FUN_010386d4(void)
 */


uint FUN_010386d4(void)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = DAT_21000750;
  if ((undefined4 **)DAT_21000750 == &DAT_21000750) {
    FUN_010386c0();
  }
  else {
    uVar2 = FUN_010386c0();
    if (puVar1 != (undefined4 *)0x0) {
      uVar4 = puVar1[4] - uVar2;
      iVar3 = (puVar1[5] - ((int)uVar2 >> 0x1f)) - (uint)((uint)puVar1[4] < uVar2);
      if (iVar3 < (int)(uint)(uVar4 < 0x80000000)) {
        if (-1 < iVar3) {
          return uVar4;
        }
        return 0;
      }
    }
  }
  return 0x7fffffff;
}


