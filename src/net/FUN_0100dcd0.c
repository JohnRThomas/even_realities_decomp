/*
 * Function: FUN_0100dcd0
 * Entry:    0100dcd0
 * Prototype: uint __stdcall FUN_0100dcd0(char * param_1, uint param_2)
 */


uint FUN_0100dcd0(char *param_1,uint param_2)

{
  char cVar1;
  undefined4 extraout_r2;
  int iVar2;
  int iVar3;
  int extraout_r2_00;
  undefined4 extraout_r3;
  uint uVar4;
  uint extraout_r3_00;
  uint uVar5;
  uint uVar6;
  int iVar7;
  ulonglong uVar8;
  
  uVar6 = *(uint *)(param_1 + 0x10);
  iVar7 = *(int *)(param_1 + 0x14);
  cVar1 = FUN_0102373c(param_1);
  if (cVar1 == '\0') {
    FUN_01009500(0x29,0x1d3,extraout_r2,extraout_r3);
    iVar3 = extraout_r2_00;
    uVar4 = extraout_r3_00;
  }
  else {
    if (param_2 == 0) {
      return 0;
    }
    uVar4 = *(uint *)(param_1 + 0x10) - uVar6;
    iVar2 = (*(int *)(param_1 + 0x14) - iVar7) - (uint)(*(uint *)(param_1 + 0x10) < uVar6);
    if (iVar2 < (int)(uint)(uVar4 == 0)) {
      return 0;
    }
    iVar3 = -(uint)(0xfffffffe < uVar4) - iVar2;
    if (iVar3 < 0 == (SBORROW4(0,iVar2) != SBORROW4(-iVar2,(uint)(0xfffffffe < uVar4)))) {
      uVar4 = (uVar4 + (param_2 - 1)) / param_2;
      uVar5 = uVar4 * param_2;
      *(uint *)(param_1 + 0x10) = uVar5 + uVar6;
      *(uint *)(param_1 + 0x14) = iVar7 + (uint)CARRY4(uVar5,uVar6);
      return uVar4;
    }
  }
  uVar8 = FUN_01009500(0x29,0x1dd,iVar3,uVar4);
  iVar7 = (int)(uVar8 >> 0x20);
  uVar6 = (uint)uVar8;
  if ((uVar8 & 0xc00000000) != 0) {
    if (iVar7 << 0x1d < 0) {
      iVar7 = 0x20e;
      iVar3 = 0x10;
      if (uVar6 < 0x20f) {
        return 0;
      }
    }
    else {
      iVar3 = 0x40;
      iVar7 = 0x3d0;
      if (uVar6 < 0x3d1) {
        return 0;
      }
    }
    return (int)(uVar6 - iVar7) / iVar3 & 0xffff;
  }
  if (iVar7 == 2) {
    if (0x3c < uVar6) {
      return (uVar6 - 0x3c) * 0x4000 >> 0x10;
    }
  }
  else if (0x70 < uVar6) {
    return (uVar6 - 0x70) * 0x2000 >> 0x10;
  }
  return 0;
}


