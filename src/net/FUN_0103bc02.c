/*
 * Function: FUN_0103bc02
 * Entry:    0103bc02
 * Prototype: undefined4 __stdcall FUN_0103bc02(int param_1, uint param_2)
 */


undefined4 FUN_0103bc02(int param_1,uint param_2)

{
  undefined4 extraout_r2;
  byte bVar1;
  undefined4 uVar2;
  undefined4 extraout_r3;
  byte *pbVar3;
  int iVar4;
  
  pbVar3 = *(byte **)(param_1 + 8);
  if (pbVar3 == (byte *)0x0) goto LAB_0103bc20;
  if (pbVar3[1] == 1) {
    bVar1 = pbVar3[-0x53] & 2;
    if ((pbVar3[-0x53] & 2) != 0) {
      if (*(int *)(pbVar3 + -0x34) == -1 && *(int *)(pbVar3 + -0x38) == -2) {
        *pbVar3 = 0;
        return 0xfffffff5;
      }
      FUN_01038010((int *)(pbVar3 + -0x60));
      if (param_2 == 8) {
        uVar2 = 0xfffffffc;
      }
      else {
        uVar2 = 0;
      }
      *(undefined4 *)(pbVar3 + 0x30) = uVar2;
      if (((pbVar3[-0x53] & 0x1f) != 0) || (*(int *)(pbVar3 + -0x48) != 0)) goto LAB_0103bc76;
      FUN_0103781c((undefined4 *)(pbVar3 + -0x60));
LAB_0103bc6e:
      *pbVar3 = 0;
      goto LAB_0103bc20;
    }
  }
  else {
    if (pbVar3[1] == 2) {
      if (*pbVar3 == 0) goto LAB_0103bc20;
      iVar4 = *(int *)(pbVar3 + -4);
      if (iVar4 != 0) {
        FUN_01038898((int *)(pbVar3 + 0x14));
        pbVar3[0x2c] = 0;
        pbVar3[0x2d] = 0;
        pbVar3[0x2e] = 0;
        pbVar3[0x2f] = 0;
        FUN_010373ec(iVar4,(undefined4 *)(pbVar3 + -0x14),extraout_r2,extraout_r3);
        *pbVar3 = 0;
        goto LAB_0103bc20;
      }
      goto LAB_0103bc6e;
    }
LAB_0103bc76:
    bVar1 = 0;
  }
  *pbVar3 = bVar1;
LAB_0103bc20:
  *(undefined4 *)(param_1 + 8) = 0;
  *(uint *)(param_1 + 0xc) =
       *(uint *)(param_1 + 0xc) & 0xffe03fff |
       (param_2 & 0x7f | (*(uint *)(param_1 + 0xc) << 0xb) >> 0x19) << 0xe;
  return 0;
}


