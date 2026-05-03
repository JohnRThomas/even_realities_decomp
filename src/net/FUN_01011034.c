/*
 * Function: FUN_01011034
 * Entry:    01011034
 * Prototype: int __stdcall FUN_01011034(int param_1, uint * param_2)
 */


int FUN_01011034(int param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte local_9;
  
  uVar2 = (uint)(ushort)param_2[1];
  if (param_1 == 1) {
    uVar2 = uVar2 | 0x10000;
  }
  iVar1 = FUN_01010edc(*param_2,uVar2,&local_9);
  if (iVar1 != 0) {
    uVar2 = (uint)local_9;
    uVar4 = (uint)DAT_21000f14;
    uVar3 = uVar4 - 1;
    DAT_21000f14 = (byte)uVar3;
    if (uVar2 < (uVar3 & 0xff)) {
      FUN_0102610c((undefined4 *)(DAT_21000f18 + uVar2 * 8),
                   (undefined4 *)(DAT_21000f18 + (uVar2 + 1) * 8),
                   (((uVar4 - 2) - uVar2 & 0xff) + 1) * 8);
    }
  }
  return iVar1;
}


