/*
 * Function: FUN_0101b6e0
 * Entry:    0101b6e0
 * Prototype: uint __stdcall FUN_0101b6e0(int param_1, uint * param_2)
 */


/* WARNING: Removing unreachable block (ram,0x0101b91a) */
/* WARNING: Removing unreachable block (ram,0x0101b7a6) */
/* WARNING: Removing unreachable block (ram,0x0101b87a) */
/* WARNING: Removing unreachable block (ram,0x0101b884) */
/* WARNING: Removing unreachable block (ram,0x0101b892) */
/* WARNING: Removing unreachable block (ram,0x0101b8a0) */
/* WARNING: Removing unreachable block (ram,0x0101b8c8) */
/* WARNING: Removing unreachable block (ram,0x0101b8de) */
/* WARNING: Removing unreachable block (ram,0x0101b8f0) */
/* WARNING: Removing unreachable block (ram,0x0101b8fe) */
/* WARNING: Removing unreachable block (ram,0x0101b908) */
/* WARNING: Removing unreachable block (ram,0x0101b924) */
/* WARNING: Removing unreachable block (ram,0x0101b92e) */
/* WARNING: Removing unreachable block (ram,0x0101b938) */
/* WARNING: Removing unreachable block (ram,0x0101b994) */
/* WARNING: Removing unreachable block (ram,0x0101b9a2) */
/* WARNING: Removing unreachable block (ram,0x0101b9a4) */
/* WARNING: Removing unreachable block (ram,0x0101b9a6) */
/* WARNING: Removing unreachable block (ram,0x0101b9a8) */
/* WARNING: Removing unreachable block (ram,0x0101b9b0) */
/* WARNING: Removing unreachable block (ram,0x0101b9ba) */
/* WARNING: Removing unreachable block (ram,0x0101b9bc) */
/* WARNING: Removing unreachable block (ram,0x0101b9be) */
/* WARNING: Removing unreachable block (ram,0x0101b982) */
/* WARNING: Removing unreachable block (ram,0x0101b910) */
/* WARNING: Removing unreachable block (ram,0x0101b7b4) */
/* WARNING: Removing unreachable block (ram,0x0101b846) */
/* WARNING: Removing unreachable block (ram,0x0101b7c6) */
/* WARNING: Removing unreachable block (ram,0x0101b7d8) */
/* WARNING: Removing unreachable block (ram,0x0101b85e) */
/* WARNING: Removing unreachable block (ram,0x0101b864) */
/* WARNING: Removing unreachable block (ram,0x0101b7ec) */
/* WARNING: Removing unreachable block (ram,0x0101b94a) */

uint FUN_0101b6e0(int param_1,uint *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 extraout_r2;
  int iVar5;
  uint uVar6;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 uVar7;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined1 extraout_r3;
  uint uVar8;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar9;
  undefined4 extraout_r3_04;
  uint extraout_r3_05;
  uint uVar10;
  byte abStack_30 [4];
  int aiStack_2c [5];
  
  if (DAT_210010a0 != '\0') {
    return 0xc;
  }
  pbVar2 = FUN_01019a04();
  bVar1 = *(byte *)(param_1 + 0x300);
  uVar8 = (uint)bVar1;
  uVar7 = extraout_r2;
  uVar6 = uVar8;
  DAT_210010c8 = param_1;
  if (uVar8 == 0) {
    DAT_210010a0 = '\x05';
    DAT_21001114 = (ushort)bVar1;
    DAT_210010a1 = bVar1;
    DAT_210010cc = bVar1;
    DAT_210010ce = bVar1;
    iVar3 = FUN_0101a930();
    DAT_210010f8 = 0;
    uVar6 = 0;
    uVar10 = 0;
    do {
      iVar5 = uVar6 + 2;
      uVar10 = uVar10 + 1;
      uVar6 = uVar10 & 0xff;
      DAT_210010f8 = DAT_210010f8 + iVar3 + *(int *)(&DAT_210010a0 + iVar5 * 4);
    } while (uVar6 <= DAT_210010cf);
    uVar6 = FUN_01023634(0x101b321,0);
    *pbVar2 = (byte)uVar6;
    uVar7 = extraout_r2_00;
    uVar9 = extraout_r3_00;
    if (uVar6 != 0x20) {
      pbVar4 = FUN_0101ab8c(abStack_30,1,(uint *)0x0,param_2);
      uVar7 = extraout_r2_01;
      uVar9 = extraout_r3_01;
      if (pbVar4 != (byte *)0x0) {
        uVar6 = FUN_010239c8((uint)*pbVar2,abStack_30);
        if (uVar6 != 0) {
          return 0;
        }
        FUN_01009500(0x21,0x312,extraout_r2_02,extraout_r3_02);
        uVar7 = extraout_r2_03;
        uVar9 = extraout_r3_03;
      }
      FUN_01009500(0x21,0x311,uVar7,uVar9);
      uVar7 = extraout_r2_04;
      uVar9 = extraout_r3_04;
    }
    FUN_01009500(0x21,0x30e,uVar7,uVar9);
    uVar7 = extraout_r2_05;
    uVar6 = extraout_r3_05;
  }
  FUN_01009500(0x21,0x300,uVar7,uVar6);
  *(undefined1 *)((int)param_2 + 0x2f) = extraout_r3;
  param_2[1] = 0;
  param_2[0x18] = 0;
  *(undefined2 *)(param_2 + 0x19) = 0x271;
  iVar3 = FUN_0101a930();
  uVar6 = uVar8 & 1;
  if ((bVar1 & 1) != 0) {
    param_2[2] = aiStack_2c[0] - iVar3;
  }
  uVar10 = uVar6;
  if ((int)(uVar8 << 0x1e) < 0) {
    uVar10 = uVar6 + 1;
    param_2[uVar6 + 2] = aiStack_2c[uVar6] - iVar3;
  }
  if ((int)(uVar8 << 0x1c) < 0) {
    param_2[uVar10 + 2] = aiStack_2c[uVar10] - iVar3;
  }
  return 0;
}


