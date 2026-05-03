/*
 * Function: FUN_010287a6
 * Entry:    010287a6
 * Prototype: undefined2 __stdcall FUN_010287a6(int param_1, char param_2)
 */


undefined2 FUN_010287a6(int param_1,char param_2)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_010282d2(param_2);
  if ((*(short *)(param_1 + ((uVar1 & 0xff) + 0xc) * 2) == 0) &&
     (*(short *)(param_1 + ((uVar1 & 0xff) + 0xd) * 2) == 0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


