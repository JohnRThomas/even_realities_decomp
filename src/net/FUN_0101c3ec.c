/*
 * Function: FUN_0101c3ec
 * Entry:    0101c3ec
 * Prototype: int __stdcall FUN_0101c3ec(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_0101c3ec(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint *extraout_r2_01;
  undefined4 extraout_r2_02;
  uint uVar6;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 uVar7;
  uint *extraout_r2_05;
  uint *extraout_r2_06;
  uint *puVar8;
  undefined4 extraout_r2_07;
  uint *extraout_r2_08;
  uint uVar9;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar13;
  uint extraout_r3_04;
  uint extraout_r3_05;
  uint extraout_r3_06;
  uint unaff_r4;
  uint unaff_r5;
  uint unaff_r6;
  byte abStack_40 [4];
  undefined4 uStack_3c;
  undefined2 uStack_38;
  undefined1 uStack_36;
  undefined1 uStack_35;
  int iStack_30;
  int iStack_2c;
  uint uStack_24;
  uint uStack_20;
  
  if (param_1 == 0) {
    FUN_01009500(0x35,0x1a2,param_3,param_4);
    param_3 = extraout_r2;
    uVar9 = extraout_r3;
    param_1 = unaff_r4;
LAB_0101c424:
    FUN_01009500(0x35,0x1a4,param_3,uVar9);
    param_3 = extraout_r2_00;
    uVar9 = extraout_r3_00;
  }
  else {
    uVar9 = (uint)*(byte *)(param_1 + 0x300);
    unaff_r5 = uVar9;
    if (uVar9 == 0) {
      uVar9 = (uint)*(byte *)(param_1 + 0x301);
      if (uVar9 == 0x20) {
        uVar9 = FUN_01023634(0x101c259,param_1);
        *(char *)(param_1 + 0x301) = (char)uVar9;
        if (uVar9 == 0x20) {
          iVar4 = 0xd;
        }
        else {
          iVar4 = 0;
        }
        return iVar4;
      }
      goto LAB_0101c424;
    }
  }
  uVar9 = FUN_01009500(0x35,0x1a3,param_3,uVar9);
  *extraout_r2_01 = uVar9;
  extraout_r2_01[1] = extraout_r3_01;
  extraout_r2_01[2] = param_1;
  extraout_r2_01[3] = unaff_r6;
  puVar8 = extraout_r2_01 + 4;
  uStack_24 = param_1;
  uStack_20 = unaff_r5;
  if (uVar9 == 0) {
    FUN_01009500(0x35,0x1b1,puVar8,extraout_r3_01);
    uVar7 = extraout_r2_04;
    uVar13 = extraout_r3_03;
    uVar9 = param_1;
LAB_0101c582:
    FUN_01009500(0x35,0x1b7,uVar7,uVar13);
    puVar8 = extraout_r2_05;
    uVar10 = extraout_r3_04;
LAB_0101c58c:
    FUN_01009500(0x35,0x1b3,puVar8,uVar10);
    puVar8 = extraout_r2_06;
    uVar10 = extraout_r3_05;
  }
  else {
    uVar10 = (uint)*(byte *)(uVar9 + 0x300);
    if (uVar10 == 0) {
      uVar10 = (uint)*(byte *)(uVar9 + 0x301);
      if (uVar10 != 0x20) {
        unaff_r6 = FUN_0101a8e8();
        uVar10 = (uint)*(byte *)(uVar9 + 0x300);
        uVar7 = extraout_r2_02;
        switch(uVar10) {
        case 0:
          bVar1 = *(byte *)(uVar9 + 0x6f);
          uVar2 = *(ushort *)(&DAT_0103c250 + (uint)*(byte *)(uVar9 + 0x6e) * 2);
          *(undefined1 *)(uVar9 + 0x300) = 1;
          iVar4 = FUN_010211f0((uint)bVar1);
          if ((bVar1 & 0xc) == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = 0x28;
          }
          uVar10 = 0;
          FUN_0100fc8c(uVar9,iVar5 + (uVar2 + 0x79d + iVar4) / 1000 + 199);
          cVar3 = FUN_0101e6c4();
          if (cVar3 != '\0') goto LAB_0101c47e;
          goto LAB_0101c51e;
        case 1:
        case 3:
          uVar10 = *(uint *)(uVar9 + 0x14);
          break;
        case 2:
          uVar10 = *(uint *)(uVar9 + 0x308);
          *(undefined1 *)(uVar9 + 0x300) = 3;
          break;
        default:
          goto switchD_0101c46c_default;
        }
        cVar3 = FUN_0101e6c4();
        if (cVar3 == '\0') {
LAB_0101c51e:
          uVar6 = FUN_0100fe9c((int)*(short *)(uVar9 + 0x2fc),2);
          iStack_2c = (int)uVar6 >> 0x1f;
          *(short *)(uVar9 + 0x2fc) = *(short *)(uVar9 + 0x2fc) - (short)uVar6;
        }
        else {
LAB_0101c47e:
          uVar6 = 0;
          iStack_2c = 0;
        }
        uVar11 = *(uint *)(uVar9 + 0x2d8);
        uVar12 = uVar10 + uVar11;
        uStack_38 = (undefined2)unaff_r6;
        unaff_r6 = (uint)*(byte *)(uVar9 + 0xc5);
        iStack_30 = uVar12 + uVar6;
        *(int *)(uVar9 + 0x2d8) = iStack_30;
        iStack_2c = iStack_2c +
                    *(int *)(uVar9 + 0x2dc) + (uint)CARRY4(uVar10,uVar11) +
                    (uint)CARRY4(uVar12,uVar6);
        *(int *)(uVar9 + 0x2dc) = iStack_2c;
        abStack_40[0] = 0;
        if (((unaff_r6 & 0xfd) == 0xc) || (unaff_r6 == 0x26)) {
          FUN_0101e450(uVar9);
LAB_0101c54a:
          uStack_36 = 0;
        }
        else {
          uVar10 = FUN_0101e450(uVar9);
          if (uVar10 == 0) goto LAB_0101c54a;
          if (*(char *)(uVar9 + 0x300) == '\x01') {
            uStack_36 = 1;
          }
          else {
            uStack_36 = 2;
          }
        }
        uStack_35 = 1;
        uStack_3c = FUN_0100f8fc(uVar9 + 0x30);
        uVar10 = FUN_010239c8((uint)*(byte *)(uVar9 + 0x301),abStack_40);
        uVar7 = extraout_r2_03;
        uVar13 = extraout_r3_02;
        if (uVar10 != 0) {
          return uVar10;
        }
        goto LAB_0101c582;
      }
      goto LAB_0101c58c;
    }
  }
  FUN_01009500(0x35,0x1b2,puVar8,uVar10);
  uVar7 = extraout_r2_07;
  uVar10 = extraout_r3_06;
switchD_0101c46c_default:
  FUN_01009500(0x35,0x264,uVar7,uVar10);
  *extraout_r2_08 = uVar9;
  extraout_r2_08[1] = unaff_r6;
  uVar9 = FUN_01020af0();
  if (uVar9 <= DAT_21001120) {
                    /* WARNING: Could not recover jumptable at 0x0101c5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar4 = (*(code *)0x101c5ab)(DAT_2100111c ^ 1);
    return iVar4;
  }
                    /* WARNING: Could not recover jumptable at 0x0101c5cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (*(code *)0x101c5ab)(0);
  return iVar4;
}


