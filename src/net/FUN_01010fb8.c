/*
 * Function: FUN_01010fb8
 * Entry:    01010fb8
 * Prototype: int __stdcall FUN_01010fb8(int param_1, uint * param_2)
 */


int FUN_01010fb8(int param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 *puVar4;
  uint uVar5;
  byte local_21 [5];
  
  uVar5 = *param_2;
  uVar3 = (uint)(ushort)param_2[1];
  if (param_1 == 1) {
    uVar3 = uVar3 | 0x10000;
  }
  iVar2 = FUN_01010edc(uVar5,uVar3,local_21);
  iVar1 = DAT_21000f18;
  if ((iVar2 == 0) && (uVar3 = (uint)DAT_21000f14, DAT_21000f1c != uVar3)) {
    if (local_21[0] < uVar3) {
      do {
        puVar4 = (undefined4 *)(iVar1 + (uVar3 + 0x1fffffff) * 8);
        uVar3 = uVar3 - 1 & 0xff;
        puVar4[2] = *puVar4;
        puVar4[3] = puVar4[1];
      } while (local_21[0] < uVar3);
    }
    *(uint *)(iVar1 + (uint)local_21[0] * 8) = uVar5;
    DAT_21000f14 = DAT_21000f14 + 1;
    iVar2 = 1;
    *(undefined4 *)(iVar1 + (uint)local_21[0] * 8 + 4) = extraout_r1;
  }
  return iVar2;
}


