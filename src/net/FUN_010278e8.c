/*
 * Function: FUN_010278e8
 * Entry:    010278e8
 * Prototype: undefined4 __stdcall FUN_010278e8(short * param_1)
 */


undefined4 FUN_010278e8(short *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  bVar1 = FUN_01027112(param_1[2],param_1[3]);
  if (bVar1) {
    uVar2 = 0;
  }
  else if (param_1[5] == 0) {
    if (param_1[7] == 0) {
      FUN_01009d1c(param_1,(ushort *)(param_1 + 2));
      param_1[7] = 0;
      uVar2 = 1;
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


