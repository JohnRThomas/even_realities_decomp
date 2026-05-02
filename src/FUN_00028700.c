/*
 * Function: FUN_00028700
 * Entry:    00028700
 * Prototype: undefined __stdcall FUN_00028700(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6, float param_7, int param_8)
 */


void FUN_00028700(float param_1,float param_2,float param_3,float param_4,float param_5,
                 float param_6,float param_7,int param_8)

{
  int extraout_r0;
  int extraout_r0_00;
  float extraout_s1;
  float extraout_s1_00;
  float extraout_s2;
  float extraout_s3;
  float extraout_s4;
  float extraout_s5;
  float extraout_s6;
  float fVar1;
  float extraout_s7;
  float fVar2;
  float extraout_s8;
  float fVar3;
  float extraout_s9;
  float extraout_s9_00;
  float fVar4;
  float extraout_s10;
  float extraout_s11;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar1 = *(float *)(param_8 + 0x18);
  fVar10 = *(float *)(param_8 + 0x10);
  fVar9 = *(float *)(param_8 + 0xc);
  fVar8 = *(float *)(param_8 + 0x14);
  fVar3 = 0.5;
  if (((param_4 != 0.0) || (param_5 != 0.0)) || (param_6 != 0.0)) {
    fVar1 = FUN_000286c4(param_5 * param_5 + param_4 * param_4 + param_6 * param_6);
    fVar3 = extraout_s7 * fVar8 + fVar10 * fVar9;
    fVar6 = fVar10 * extraout_s7 - fVar9 * fVar8;
    fVar7 = (fVar9 * fVar9 - extraout_s9) + extraout_s7 * extraout_s7;
    fVar5 = extraout_s4 * fVar1 * fVar7 - extraout_s5 * fVar1 * fVar3;
    fVar3 = extraout_s3 * fVar1 * fVar3 - extraout_s4 * fVar1 * fVar6;
    fVar7 = extraout_s5 * fVar1 * fVar6 - extraout_s3 * fVar1 * fVar7;
    fVar6 = 0.0;
    fVar1 = *(float *)(extraout_r0 + 8);
    if (fVar1 <= 0.0) {
      *(undefined4 *)(extraout_r0 + 0x1c) = 0;
      *(undefined4 *)(extraout_r0 + 0x20) = 0;
      fVar4 = extraout_s1;
      fVar1 = extraout_s2;
      fVar2 = extraout_s11;
    }
    else {
      fVar2 = *(float *)(extraout_r0 + 0x1c) + fVar1 * fVar5 * extraout_s6;
      fVar4 = *(float *)(extraout_r0 + 0x20) + fVar1 * fVar7 * extraout_s6;
      fVar6 = *(float *)(extraout_r0 + 0x24) + fVar1 * fVar3 * extraout_s6;
      *(float *)(extraout_r0 + 0x1c) = fVar2;
      *(float *)(extraout_r0 + 0x20) = fVar4;
      fVar2 = extraout_s11 + fVar2;
      fVar4 = extraout_s1 + fVar4;
      fVar1 = extraout_s2 + fVar6;
    }
    *(float *)(extraout_r0 + 0x24) = fVar6;
    fVar6 = *(float *)(extraout_r0 + 4);
    param_1 = fVar2 + fVar6 * fVar5;
    param_2 = fVar4 + fVar6 * fVar7;
    param_3 = fVar1 + fVar6 * fVar3;
    param_7 = extraout_s6;
    fVar1 = extraout_s7;
    fVar3 = extraout_s9;
  }
  fVar3 = param_7 * fVar3;
  fVar5 = fVar3 * param_3;
  fVar2 = fVar3 * param_1;
  fVar3 = fVar3 * param_2;
  fVar7 = ((fVar5 * fVar8 + fVar2 * fVar9) - fVar1 * fVar3) + fVar10;
  fVar6 = ((-(fVar3 * fVar8) + -(fVar10 * fVar2)) - fVar1 * fVar5) + fVar9;
  fVar4 = (fVar3 * fVar9 - fVar5 * fVar10) + fVar1 * fVar2 + fVar8;
  fVar1 = ((fVar3 * fVar10 + fVar5 * fVar9) - fVar2 * fVar8) + fVar1;
  fVar1 = FUN_000286c4(fVar7 * fVar7 + fVar6 * fVar6 + fVar4 * fVar4 + fVar1 * fVar1);
  *(float *)(extraout_r0_00 + 0xc) = extraout_s8 * fVar1;
  *(float *)(extraout_r0_00 + 0x10) = extraout_s9_00 * fVar1;
  *(float *)(extraout_r0_00 + 0x14) = extraout_s10 * fVar1;
  *(float *)(extraout_r0_00 + 0x18) = extraout_s1_00 * fVar1;
  *(undefined1 *)(extraout_r0_00 + 0x28) = 0;
  return;
}


