/*
 * Function: FUN_01010edc
 * Entry:    01010edc
 * Prototype: undefined4 __stdcall FUN_01010edc(uint param_1, uint param_2, undefined1 * param_3)
 */


undefined4 FUN_01010edc(uint param_1,uint param_2,undefined1 *param_3)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  cVar1 = DAT_21000f14;
  *param_3 = 0;
  if (cVar1 == '\0') {
    return 0;
  }
  uVar3 = (uint)(byte)(cVar1 - 1);
  uVar6 = 0;
  while( true ) {
    uVar7 = uVar3;
    iVar5 = (int)(uVar6 + uVar7) >> 1;
    uVar2 = (uVar6 + uVar7) * 0x800000 >> 0x18;
    if ((int)(uVar7 - uVar6) < 2) break;
    uVar4 = *(uint *)(DAT_21000f18 + iVar5 * 8 + 4);
    uVar3 = uVar2;
    if (uVar4 <= param_2 &&
        (uint)(param_1 <= *(uint *)(DAT_21000f18 + iVar5 * 8)) <= uVar4 - param_2) {
      uVar3 = uVar7;
      uVar6 = uVar2;
    }
  }
  uVar2 = *(uint *)(DAT_21000f18 + uVar6 * 8);
  uVar3 = *(uint *)(DAT_21000f18 + uVar6 * 8 + 4);
  if (uVar3 == param_2 && uVar2 == param_1) {
    *param_3 = (char)uVar6;
    return 1;
  }
  if (param_2 <= uVar3 && (uint)(uVar2 <= param_1) <= param_2 - uVar3) {
    *param_3 = (char)uVar6;
    return 0;
  }
  uVar6 = *(uint *)(DAT_21000f18 + uVar7 * 8);
  uVar3 = *(uint *)(DAT_21000f18 + uVar7 * 8 + 4);
  if (uVar3 == param_2 && uVar6 == param_1) {
    *param_3 = (char)uVar7;
    return 1;
  }
  if (uVar3 < param_2 || param_2 - uVar3 < (uint)(uVar6 <= param_1)) {
    uVar7 = uVar7 + 1;
  }
  *param_3 = (char)uVar7;
  return 0;
}


