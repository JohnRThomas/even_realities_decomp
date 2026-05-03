/*
 * Function: FUN_01028710
 * Entry:    01028710
 * Prototype: undefined2 __stdcall FUN_01028710(int param_1, char param_2, char param_3)
 */


undefined2 FUN_01028710(int param_1,char param_2,char param_3)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_010282d2(param_2);
  if (param_3 == *(char *)((uVar1 & 0xff) + param_1 + 0x14)) {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xc) * 2);
  }
  else if (param_3 == *(char *)((uVar1 & 0xff) + param_1 + 0x15)) {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xd) * 2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


