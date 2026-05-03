/*
 * Function: FUN_0102dec8
 * Entry:    0102dec8
 * Prototype: int __stdcall FUN_0102dec8(int param_1)
 */


int FUN_0102dec8(int param_1)

{
  uint uVar1;
  int iVar2;
  int extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  int iVar3;
  int extraout_r2;
  int extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r3;
  code *pcVar6;
  int iVar7;
  undefined4 *puVar8;
  int *piVar9;
  
  iVar7 = *(int *)(param_1 + 0x10);
  puVar8 = *(undefined4 **)(param_1 + 4);
  piVar9 = (int *)(iVar7 + 0x37c);
  if (*piVar9 != 0) {
    return -0x78;
  }
  *piVar9 = 1;
  iVar3 = 1;
  iVar4 = puVar8[2];
  iVar2 = puVar8[10];
  while (uVar1 = FUN_0103a816(iVar3,iVar2), uVar1 < iVar4 - 4U) {
    iVar3 = extraout_r2 + 1;
    iVar2 = extraout_r1;
  }
  if (extraout_r2 + -1 == 0) {
    iVar2 = -0xc;
  }
  else {
    uVar1 = 0x80000000 >> LZCOUNT(extraout_r2 + -1);
    *(uint *)(iVar7 + 0x260) = puVar8[1] + 7 & 0xfffffffc;
    iVar2 = FUN_0103a816(uVar1,puVar8[10]);
    *(int *)(iVar7 + 0x264) = iVar2;
    iVar2 = extraout_r2_00 + (uVar1 * puVar8[10] + 3 & 0xfffffffc) * 2;
    *(int *)(iVar7 + 600) = iVar2;
    *(uint *)(iVar7 + 0x254) = iVar2 + (uVar1 * 0x12 + 9 & 0xfffffffc) + uVar1 * 8 + 8;
    uVar5 = puVar8[1];
    *(uint *)(iVar7 + 0x25c) = uVar1;
    *(undefined4 *)(iVar7 + 0x250) = uVar5;
    *(undefined4 **)(iVar7 + 0x2a4) = puVar8;
    *(undefined1 **)(iVar7 + 0x2a8) = &LAB_0103a75e_1;
    iVar2 = FUN_0102e2f0(iVar7 + 0x1c8,*puVar8);
    if (iVar2 == 0) {
      iVar4 = *(int *)(param_1 + 4);
      iVar3 = *(int *)(param_1 + 0x10);
      iVar2 = *(int *)(iVar4 + 0x20);
      if (*(int *)(iVar4 + 0x1c) == 1) {
        iVar2 = iVar2 + -0x10;
      }
      FUN_01037478((undefined1 *)(iVar3 + 0x2c0),extraout_r1_00,extraout_r2_01,
                   *(int *)(iVar4 + 0x1c));
      FUN_010374a4((undefined4 *)(iVar3 + 0x2c0),*(int *)(iVar4 + 0x24) * 0x440 + 0x21007d80,0x400,
                   iVar2,(int *)0x0);
      FUN_010373ac((undefined1 *)(iVar3 + 0x2b0),0x103a745,extraout_r2_02,extraout_r3);
      pcVar6 = *(code **)(*(int *)(*(int *)(iVar4 + 0x14) + 8) + 4);
      if (pcVar6 == (code *)0x0) {
LAB_0102dfc4:
        iVar2 = -0x58;
      }
      else {
        iVar2 = (*pcVar6)(*(int *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18),&LAB_0103a738_1,iVar3
                         );
        if (iVar2 == 0) {
          pcVar6 = *(code **)(*(int *)(*(int *)(iVar4 + 0x14) + 8) + 0x10);
          if (pcVar6 == (code *)0x0) goto LAB_0102dfc4;
          iVar2 = (*pcVar6)(*(int *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18),1);
          if (iVar2 == 0) {
            *(undefined4 *)(iVar7 + 0x1a8) = 0x102e07d;
            *(undefined4 *)(iVar7 + 0x1ac) = 0x103a8ed;
            iVar2 = FUN_0102e280(iVar7,*(int *)(iVar7 + 0x378),puVar8[10],*(int *)(iVar7 + 0x268),
                                 iVar7 + 0x1c8,*(int *)(iVar7 + 0x208),*(int *)(iVar7 + 0x210),
                                 0x103a7a7);
            if (iVar2 == 0) {
              iVar3 = FUN_01035fac(iVar7 + 0xe0,extraout_r1_01);
              *(int *)(iVar7 + 0x380) = iVar3;
              if (-1 < iVar3) {
                uVar5 = 2;
                goto LAB_0102e040;
              }
              iVar2 = -0x16;
            }
          }
        }
      }
    }
  }
  uVar5 = 0;
LAB_0102e040:
  FUN_0103a776(piVar9,uVar5);
  return iVar2;
}


