/*
 * Function: FUN_01028afc
 * Entry:    01028afc
 * Prototype: undefined __stdcall FUN_01028afc(undefined2 * param_1, int param_2, undefined2 * param_3)
 */


void FUN_01028afc(undefined2 *param_1,int param_2,undefined2 *param_3)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined2 uVar6;
  uint uVar7;
  
  uVar1 = param_1[0x2b];
  uVar2 = param_1[0x2c];
  if (param_2 == 0) {
    uVar3 = FUN_01014590((uint *)(param_1 + 0x18));
  }
  else {
    uVar3 = FUN_0101c3c8((uint *)(param_1 + 0x18));
  }
  uVar4 = FUN_0100dd38(uVar3,2);
  uVar5 = FUN_0100dd38(uVar3,2);
  uVar7 = (uint)uVar1;
  if (uVar4 <= uVar1) {
    uVar7 = uVar4;
  }
  *param_3 = *param_1;
  uVar7 = uVar7 & 0xffff;
  if (uVar7 < 0x1b) {
    uVar7 = 0x1b;
  }
  uVar6 = (undefined2)uVar7;
  if (0xfa < uVar7) {
    uVar6 = 0xfb;
  }
  uVar7 = (uint)uVar2;
  if (uVar5 <= uVar2) {
    uVar7 = uVar5;
  }
  param_3[1] = uVar6;
  uVar7 = uVar7 & 0xffff;
  if (uVar7 < 0x1b) {
    uVar7 = 0x1b;
  }
  uVar6 = (undefined2)uVar7;
  if (0xfa < uVar7) {
    uVar6 = 0xfb;
  }
  if (uVar3 < 0x148) {
    uVar3 = 0x148;
  }
  param_3[3] = uVar6;
  if (0xa8f < uVar3) {
    uVar3 = 0xa90;
  }
  param_3[2] = (short)uVar3;
  param_3[4] = (short)uVar3;
  return;
}


