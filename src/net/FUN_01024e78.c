/*
 * Function: FUN_01024e78
 * Entry:    01024e78
 * Prototype: int __stdcall FUN_01024e78(uint param_1, uint param_2)
 */


int FUN_01024e78(uint param_1,uint param_2)

{
  ulonglong uVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_r2;
  uint uVar4;
  undefined4 extraout_r3;
  
  if (param_2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if (param_1 != 0) {
      uVar1 = (ulonglong)param_1 * (ulonglong)param_2 - 1;
      if (0xf423fffffffff < uVar1) {
        FUN_01025edc(0x6d,0x71,(int)(uVar1 >> 0x20),(int)uVar1);
        uVar1 = CONCAT44(extraout_r2,extraout_r3);
      }
      uVar2 = (uint)((uVar1 << 0xc) >> 0x20);
      uVar4 = uVar2 / 0xf424;
      iVar3 = ((((uint)(uVar1 << 0xc) >> 0x10) + uVar2 * 0x10000 + uVar4 * 0xbdc0000) / 0xf424 |
              uVar4 << 0x10) + 1;
    }
  }
  return iVar3;
}


