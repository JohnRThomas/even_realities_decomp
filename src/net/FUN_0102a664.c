/*
 * Function: FUN_0102a664
 * Entry:    0102a664
 * Prototype: undefined __stdcall FUN_0102a664(byte * param_1, int param_2, uint param_3, uint param_4)
 */


void FUN_0102a664(byte *param_1,int param_2,uint param_3,uint param_4)

{
  bool bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 extraout_r1;
  uint extraout_r2;
  uint extraout_r2_00;
  undefined4 extraout_r2_01;
  uint extraout_r2_02;
  uint extraout_r2_03;
  uint extraout_r2_04;
  uint extraout_r2_05;
  undefined4 extraout_r2_06;
  uint extraout_r2_07;
  uint extraout_r2_08;
  uint extraout_r2_09;
  uint extraout_r2_10;
  undefined1 uVar8;
  uint extraout_r3;
  uint extraout_r3_00;
  uint extraout_r3_01;
  uint extraout_r3_02;
  uint uVar9;
  uint extraout_r3_03;
  code *pcVar10;
  uint extraout_r3_04;
  uint extraout_r3_05;
  uint uVar11;
  undefined8 uVar12;
  longlong lVar13;
  undefined *puVar4;
  
  uVar12 = CONCAT44(param_2,param_1);
  if (param_1 != (byte *)0x0) goto LAB_0102a676;
  uVar6 = 0x196;
LAB_0102a670:
  uVar12 = FUN_01025edc(0x6a,uVar6,param_3,param_4);
  param_3 = extraout_r2;
  param_4 = extraout_r3;
LAB_0102a676:
  iVar7 = (int)((ulonglong)uVar12 >> 0x20);
  iVar3 = (int)uVar12;
  uVar11 = (uint)*(byte *)(iVar3 + 0x28);
  switch(iVar7) {
  case 0:
    param_4 = *(byte *)(iVar3 + 0x26) - 3;
    if (param_4 < 2) goto LAB_0102a698;
    uVar6 = 0x1a1;
    goto LAB_0102a670;
  case 1:
    param_4 = *(byte *)(iVar3 + 0x26) - 3;
    if (1 < param_4) {
      uVar6 = 0x1a5;
      goto LAB_0102a670;
    }
    *(undefined1 *)(iVar3 + 0x26) = 5;
    *(undefined1 *)(iVar3 + 0x29) = 0;
    if (*(char *)(iVar3 + 0x24) != '\0') goto LAB_0102a714;
    FUN_0102a568(iVar3,0,param_3);
    if (*param_1 == 1) {
      lVar13 = FUN_0102370c((uint)param_1[0x27]);
      *(longlong *)(param_1 + 0x18) = lVar13;
    }
    else {
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x14);
    }
    pcVar10 = *(code **)(param_1 + 0x20);
    uVar6 = 0;
    break;
  case 2:
  case 3:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    param_3 = param_4 - 3;
    if (1 < param_3) {
      uVar6 = 0x1c3;
      goto LAB_0102a670;
    }
    if (*(char *)(iVar3 + 0x24) == '\0') {
      if (param_4 == 4) {
        uVar8 = 2;
      }
      else {
        uVar8 = 1;
      }
      *(undefined1 *)(iVar3 + 0x26) = uVar8;
      if (iVar7 == 2) {
        pbVar5 = (byte *)(**(code **)(iVar3 + 0x20))(uVar11,5);
        if (pbVar5 == (byte *)0x0) {
          return;
        }
        param_4 = (uint)*pbVar5;
        if (param_4 == 0) {
          return;
        }
        uVar6 = 0x1d8;
        param_3 = extraout_r2_04;
        goto LAB_0102a670;
      }
      uVar12 = (**(code **)(iVar3 + 0x20))(uVar11,6);
      param_3 = extraout_r2_05;
      uVar9 = extraout_r3_03;
      if ((byte *)uVar12 == (byte *)0x0) goto LAB_0102a73a;
      param_4 = (uint)*(byte *)uVar12;
      uVar9 = 0;
      if (param_4 != 0) {
        uVar6 = 0x1dd;
        goto LAB_0102a670;
      }
    }
    else {
      uVar12 = FUN_0102a534(uVar11,iVar3);
      param_3 = extraout_r2_03;
      uVar9 = extraout_r3_02;
    }
    goto LAB_0102a73a;
  case 4:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    if (param_4 != 5) {
      uVar6 = 0x1e4;
      goto LAB_0102a670;
    }
    pcVar10 = *(code **)(iVar3 + 0x20);
    uVar6 = 2;
    break;
  case 5:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    if (param_4 != 5) {
      uVar6 = 0x1ea;
      goto LAB_0102a670;
    }
    pcVar10 = *(code **)(iVar3 + 0x20);
    uVar6 = 1;
    break;
  case 6:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    if (param_4 == 5) {
LAB_0102a714:
      FUN_0102221c();
      return;
    }
    uVar6 = 0x1f0;
    goto LAB_0102a670;
  case 7:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    if ((param_4 == 5) ||
       ((param_3 = (uint)*(byte *)(iVar3 + 0x25), param_3 != 0 && (param_4 == 3)))) {
      if (param_1[0x24] != 0) {
        FUN_0102a534(uVar11,(int)param_1);
        return;
      }
      if (param_1[0x29] == 0) {
        if (param_1[0x25] == 0) {
          param_1[0x26] = 2;
          pbVar5 = (byte *)(**(code **)(param_1 + 0x20))(uVar11,7);
          if (pbVar5 == (byte *)0x0) {
            return;
          }
          param_4 = (uint)*pbVar5;
          if (param_4 == 0) {
            return;
          }
          uVar6 = 0x214;
          param_3 = extraout_r2_10;
        }
        else {
          param_1[0x25] = 0;
          uVar11 = FUN_010239c8((uint)param_1[0x27],param_1);
          if (uVar11 != 0) {
            return;
          }
          uVar6 = 0x20d;
          param_3 = extraout_r2_09;
          param_4 = extraout_r3_05;
        }
      }
      else {
        param_1[0x29] = 0;
        param_1[0x26] = 2;
        pbVar5 = (byte *)(**(code **)(param_1 + 0x20))(uVar11,8);
        if (pbVar5 == (byte *)0x0) {
          return;
        }
        param_4 = (uint)*pbVar5;
        if (param_4 == 0) {
          return;
        }
        uVar6 = 0x208;
        param_3 = extraout_r2_08;
      }
    }
    else {
      uVar6 = 0x1fc;
    }
    goto LAB_0102a670;
  case 8:
    param_4 = (uint)*(byte *)(iVar3 + 0x26);
    if (param_4 == 5) {
      pbVar5 = (byte *)(**(code **)(iVar3 + 0x20))(uVar11,10);
      FUN_0102a576(param_1,pbVar5,extraout_r2_06);
      uVar6 = 0x1f8;
      param_3 = extraout_r2_07;
      param_4 = extraout_r3_04;
    }
    else {
      uVar6 = 0x1f5;
    }
    goto LAB_0102a670;
  default:
    goto switchD_0102a680_default;
  }
  while( true ) {
    pbVar5 = (byte *)(*pcVar10)(uVar11,uVar6);
    bVar2 = FUN_0102a576(param_1,pbVar5,extraout_r2_01);
    puVar4 = (undefined *)(uint)bVar2;
    uVar12 = CONCAT44(extraout_r1,puVar4);
    param_3 = extraout_r2_02;
    uVar9 = extraout_r3_01;
    if (puVar4 == &LAB_00000002) break;
    if (puVar4 == (undefined *)0x0) {
      pcVar10 = *(code **)(param_1 + 0x20);
      uVar6 = 3;
    }
    else {
      if (puVar4 != &DAT_00000001) {
        uVar6 = 0x22a;
        param_4 = extraout_r3_01;
        goto LAB_0102a670;
      }
      pcVar10 = *(code **)(param_1 + 0x20);
      uVar6 = 4;
    }
  }
LAB_0102a73a:
  param_4 = uVar9;
  if (param_2 != 0) {
    return;
  }
LAB_0102a698:
  bVar1 = FUN_010242c4((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),param_3,param_4);
  if (!bVar1) {
    return;
  }
  uVar6 = 0x233;
  param_3 = extraout_r2_00;
  param_4 = extraout_r3_00;
  goto LAB_0102a670;
switchD_0102a680_default:
  uVar6 = 0x219;
  goto LAB_0102a670;
}


