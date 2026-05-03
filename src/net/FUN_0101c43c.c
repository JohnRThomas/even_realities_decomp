/*
 * Function: FUN_0101c43c
 * Entry:    0101c43c
 * Prototype: undefined __stdcall FUN_0101c43c(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0101c43c(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  ushort uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_r2;
  uint uVar6;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar7;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  uint *extraout_r2_05;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 uVar11;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint extraout_r3_03;
  uint unaff_r4;
  uint unaff_r6;
  byte local_30 [4];
  undefined4 local_2c;
  undefined2 local_28;
  undefined1 local_26;
  undefined1 local_25;
  int local_20;
  int local_1c;
  
  if (param_1 == 0) {
    FUN_01009500(0x35,0x1b1,param_3,param_4);
    uVar7 = extraout_r2_01;
    uVar11 = extraout_r3_00;
    param_1 = unaff_r4;
LAB_0101c582:
    FUN_01009500(0x35,0x1b7,uVar7,uVar11);
    param_3 = extraout_r2_02;
    uVar8 = extraout_r3_01;
LAB_0101c58c:
    FUN_01009500(0x35,0x1b3,param_3,uVar8);
    param_3 = extraout_r2_03;
    uVar8 = extraout_r3_02;
  }
  else {
    uVar8 = (uint)*(byte *)(param_1 + 0x300);
    if (uVar8 == 0) {
      uVar8 = (uint)*(byte *)(param_1 + 0x301);
      if (uVar8 != 0x20) {
        unaff_r6 = FUN_0101a8e8();
        uVar8 = (uint)*(byte *)(param_1 + 0x300);
        uVar7 = extraout_r2;
        switch(uVar8) {
        case 0:
          bVar1 = *(byte *)(param_1 + 0x6f);
          uVar2 = *(ushort *)(&DAT_0103c250 + (uint)*(byte *)(param_1 + 0x6e) * 2);
          *(undefined1 *)(param_1 + 0x300) = 1;
          iVar4 = FUN_010211f0((uint)bVar1);
          if ((bVar1 & 0xc) == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = 0x28;
          }
          uVar8 = 0;
          FUN_0100fc8c(param_1,iVar5 + (uVar2 + 0x79d + iVar4) / 1000 + 199);
          cVar3 = FUN_0101e6c4();
          if (cVar3 != '\0') goto LAB_0101c47e;
          goto LAB_0101c51e;
        case 1:
        case 3:
          uVar8 = *(uint *)(param_1 + 0x14);
          break;
        case 2:
          uVar8 = *(uint *)(param_1 + 0x308);
          *(undefined1 *)(param_1 + 0x300) = 3;
          break;
        default:
          goto switchD_0101c46c_default;
        }
        cVar3 = FUN_0101e6c4();
        if (cVar3 == '\0') {
LAB_0101c51e:
          uVar6 = FUN_0100fe9c((int)*(short *)(param_1 + 0x2fc),2);
          local_1c = (int)uVar6 >> 0x1f;
          *(short *)(param_1 + 0x2fc) = *(short *)(param_1 + 0x2fc) - (short)uVar6;
        }
        else {
LAB_0101c47e:
          uVar6 = 0;
          local_1c = 0;
        }
        uVar9 = *(uint *)(param_1 + 0x2d8);
        uVar10 = uVar8 + uVar9;
        local_28 = (undefined2)unaff_r6;
        unaff_r6 = (uint)*(byte *)(param_1 + 0xc5);
        local_20 = uVar10 + uVar6;
        *(int *)(param_1 + 0x2d8) = local_20;
        local_1c = local_1c +
                   *(int *)(param_1 + 0x2dc) + (uint)CARRY4(uVar8,uVar9) +
                   (uint)CARRY4(uVar10,uVar6);
        *(int *)(param_1 + 0x2dc) = local_1c;
        local_30[0] = 0;
        if (((unaff_r6 & 0xfd) == 0xc) || (unaff_r6 == 0x26)) {
          FUN_0101e450(param_1);
LAB_0101c54a:
          local_26 = 0;
        }
        else {
          uVar8 = FUN_0101e450(param_1);
          if (uVar8 == 0) goto LAB_0101c54a;
          if (*(char *)(param_1 + 0x300) == '\x01') {
            local_26 = 1;
          }
          else {
            local_26 = 2;
          }
        }
        local_25 = 1;
        local_2c = FUN_0100f8fc(param_1 + 0x30);
        uVar8 = FUN_010239c8((uint)*(byte *)(param_1 + 0x301),local_30);
        uVar7 = extraout_r2_00;
        uVar11 = extraout_r3;
        if (uVar8 != 0) {
          return;
        }
        goto LAB_0101c582;
      }
      goto LAB_0101c58c;
    }
  }
  FUN_01009500(0x35,0x1b2,param_3,uVar8);
  uVar7 = extraout_r2_04;
  uVar8 = extraout_r3_03;
switchD_0101c46c_default:
  FUN_01009500(0x35,0x264,uVar7,uVar8);
  *extraout_r2_05 = param_1;
  extraout_r2_05[1] = unaff_r6;
  uVar8 = FUN_01020af0();
  if (uVar8 <= DAT_21001120) {
                    /* WARNING: Could not recover jumptable at 0x0101c5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)0x101c5ab)(DAT_2100111c ^ 1);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0101c5cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)0x101c5ab)(0);
  return;
}


