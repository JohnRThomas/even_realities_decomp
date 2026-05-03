/*
 * Function: FUN_0103b0e4
 * Entry:    0103b0e4
 * Prototype: undefined __stdcall FUN_0103b0e4(uint param_1, byte * param_2, byte * param_3, byte * param_4, byte * param_5, byte * param_6)
 */


void FUN_0103b0e4(uint param_1,byte *param_2,byte *param_3,byte *param_4,byte *param_5,byte *param_6
                 )

{
  P1_NS *pPVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_1c;
  
  local_1c = param_1;
  pPVar1 = FUN_01034db4(&local_1c);
  if (param_4 == (byte *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0xc;
  }
  if (param_5 == (byte *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xf00;
  }
  if (param_6 == (byte *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = 0x30000;
  }
  uVar6 = 0;
  if (param_2 != (byte *)0x0) {
    uVar6 = (uint)*param_2;
  }
  uVar8 = 0;
  if (param_3 != (byte *)0x0) {
    uVar8 = (uint)*param_3 << 1;
  }
  uVar7 = 0;
  if (param_4 != (byte *)0x0) {
    uVar7 = (uint)*param_4 << 2;
  }
  if (param_5 == (byte *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (uint)*param_5 << 8;
  }
  uVar9 = 0;
  if (param_6 != (byte *)0x0) {
    uVar9 = (uint)*param_6 << 0x10;
  }
  (&pPVar1->PIN_CNF_0_)[local_1c] =
       uVar5 | uVar6 | (&pPVar1->PIN_CNF_0_)[local_1c] &
                       ~((uint)(param_2 != (byte *)0x0) | (uint)(param_3 != (byte *)0x0) << 1 |
                         uVar2 | uVar3 | uVar4) | uVar8 | uVar7 | uVar9;
  return;
}


