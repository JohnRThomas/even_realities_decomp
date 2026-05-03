/*
 * Function: FUN_0101205c
 * Entry:    0101205c
 * Prototype: undefined __stdcall FUN_0101205c(int param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_0101205c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  byte *pbVar8;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  undefined4 uVar12;
  byte bVar13;
  undefined4 uVar14;
  char local_19 [5];
  
  if ((DAT_21000f24 == 2) || (DAT_21000f24 == 3)) {
    uVar11 = 0;
    if (*(int *)(DAT_21000f4c + 0x1c) != 0) {
      uVar11 = (uint)*(byte *)(*(int *)(DAT_21000f4c + 0x1c) + 0x73);
    }
    if (param_1 != 0) {
      bVar13 = *DAT_21000f20;
      bVar3 = FUN_0100b23c((uint)(bVar13 >> 7),DAT_21000f20 + 9,(uint)(byte)DAT_21000f4c[0x60],
                           DAT_21000f4c + 0x61);
      puVar1 = DAT_21000f4c;
      if (bVar3) {
        bVar13 = bVar13 & 0xf;
        if (((bVar13 == 5) && (0x10 < (DAT_21000f20[0x24] & 0x1f))) && (DAT_21000f4c[0xf] != '\0'))
        {
          local_19[0] = -1;
          uVar11 = FUN_01011d40((uint)DAT_21000f4c,5,local_19);
          if ((uVar11 != 0) && (puVar1[0xd9] == '\0')) {
            pbVar8 = DAT_21000f20 + 0x23;
            puVar6 = (undefined4 *)(puVar1 + 0xda);
            pbVar9 = DAT_21000f20 + 3;
            do {
              pbVar10 = pbVar9 + 0x10;
              uVar14 = *(undefined4 *)(pbVar9 + 4);
              puVar7 = puVar6 + 4;
              uVar12 = *(undefined4 *)(pbVar9 + 8);
              uVar5 = *(undefined4 *)(pbVar9 + 0xc);
              *puVar6 = *(undefined4 *)pbVar9;
              puVar6[1] = uVar14;
              puVar6[2] = uVar12;
              puVar6[3] = uVar5;
              puVar6 = puVar7;
              pbVar9 = pbVar10;
            } while (pbVar10 != pbVar8);
            *(undefined2 *)puVar7 = *(undefined2 *)pbVar10;
            FUN_0100f788((undefined4 *)(puVar1 + 0xd1),0x1011155,2);
          }
        }
        else {
          bVar3 = FUN_0100e8ac(DAT_21000f20,uVar11);
          if (bVar3) {
            if ((DAT_21000f24 != 2) && (DAT_21000f24 != 3)) {
              FUN_01009500(0x2d,0xcc8,extraout_r2_00,(uint)DAT_21000f24);
              uVar5 = extraout_r1_00;
              uVar12 = extraout_r2_01;
              uVar14 = extraout_r3_00;
              goto LAB_010120e4;
            }
            iVar4 = (**(code **)(*(int *)(DAT_21000f48 + 0x14) + (DAT_21000f24 + 0x3ffffffe) * 4))
                              (DAT_21000f4c,bVar13);
            if (DAT_21000f32 != '\0') goto LAB_01012190;
            goto LAB_01012108;
          }
        }
      }
    }
    if (DAT_21000f32 != '\0') {
      FUN_010210b0();
      FUN_010204a8();
    }
  }
  else {
    iVar4 = FUN_01009500(0x2d,0xcef,param_3,(uint)DAT_21000f24);
LAB_01012190:
    FUN_010210b0();
    FUN_010204a8();
LAB_01012108:
    if (iVar4 == 0) {
      return;
    }
  }
  cVar2 = FUN_01014534(DAT_21000f4c);
  uVar5 = extraout_r1;
  uVar12 = extraout_r2;
  uVar14 = extraout_r3;
  if (cVar2 != '\0') {
    FUN_01020d00();
                    /* WARNING: Could not recover jumptable at 0x0101209e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(DAT_21000f48 + 8))();
    return;
  }
LAB_010120e4:
  FUN_01011e64(DAT_21000f4c,uVar5,uVar12,uVar14);
  return;
}


