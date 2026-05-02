/*
 * Function: FUN_0007fe2e
 * Entry:    0007fe2e
 * Prototype: undefined __stdcall FUN_0007fe2e(int param_1)
 */


void FUN_0007fe2e(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = *(float *)(param_1 + 0x10);
  fVar3 = *(float *)(param_1 + 0x14);
  fVar5 = *(float *)(param_1 + 0x18);
  fVar2 = *(float *)(param_1 + 0xc);
  fVar1 = atan2f(fVar3 * fVar5 + fVar2 * fVar4,(0.5 - fVar4 * fVar4) - fVar3 * fVar3);
  *(float *)(param_1 + 0x2c) = fVar1;
  fVar1 = acosf((fVar4 * fVar5 - fVar2 * fVar3) * -2.0);
  *(float *)(param_1 + 0x30) = fVar1;
  fVar1 = atan2f(fVar2 * fVar5 + fVar4 * fVar3,(0.5 - fVar3 * fVar3) - fVar5 * fVar5);
  *(float *)(param_1 + 0x34) = fVar1;
  *(undefined1 *)(param_1 + 0x28) = 1;
  return;
}


