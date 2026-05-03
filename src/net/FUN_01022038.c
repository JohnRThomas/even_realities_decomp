/*
 * Function: FUN_01022038
 * Entry:    01022038
 * Prototype: undefined __stdcall FUN_01022038(int param_1)
 */


void FUN_01022038(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_01022000(param_1);
  *(undefined1 *)(param_1 + 0x80) = 0;
  DAT_2100167b = DAT_2100167a - 1;
  DAT_2100167a = DAT_2100167b;
  uVar1 = (uint)DAT_2100167b;
  if (uVar1 != 0) {
    uVar2 = (uint)DAT_2100167c;
    uVar3 = uVar2 / uVar1;
    DAT_2100167b = (byte)uVar3;
    if (uVar3 == 0) {
      DAT_2100167b = 1;
    }
    if ((uVar1 < uVar2) && ((uVar2 - uVar1 * uVar3 & 0xff) != 0)) {
      DAT_2100167b = DAT_2100167b + 1;
    }
  }
  return;
}


