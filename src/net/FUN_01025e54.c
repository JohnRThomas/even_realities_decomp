/*
 * Function: FUN_01025e54
 * Entry:    01025e54
 * Prototype: int __stdcall FUN_01025e54(undefined4 param_1, uint param_2, undefined4 param_3)
 */


int FUN_01025e54(int param_1,uint param_2,undefined4 param_3)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (DAT_21001c18 == '\0') {
    FUN_0102a532();
    DAT_21001c20 = (undefined1)param_2;
    DAT_21001c1c = param_3;
    FUN_01025df8();
    pbVar1 = (byte *)FUN_01025dc8();
    iVar2 = FUN_010250e8(pbVar1);
    if (iVar2 == 0) {
      FUN_010231a8();
      FUN_010250d0();
      FUN_01024fdc();
      FUN_0102a87e();
      if (-1 < (int)param_2) {
        iVar4 = (param_2 >> 5) * 4;
        iVar3 = 1 << (param_2 & 0x1f);
        *(int *)(&DAT_e000e280 + iVar4) = iVar3;
        *(int *)(&DAT_e000e100 + iVar4) = iVar3;
      }
      DAT_21001c18 = '\x01';
    }
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


