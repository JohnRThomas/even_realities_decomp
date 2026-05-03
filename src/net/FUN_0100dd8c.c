/*
 * Function: FUN_0100dd8c
 * Entry:    0100dd8c
 * Prototype: undefined4 __stdcall FUN_0100dd8c(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_0100dd8c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  switch(param_2) {
  case 1:
    break;
  case 2:
    return 0x9c4;
  default:
    uVar2 = FUN_01009500(0x29,0x270,param_3,param_4);
    *(char *)((int)uVar2 + 0x72) = (char)((ulonglong)uVar2 >> 0x20);
    uVar1 = FUN_0101e9e4((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    return uVar1;
  case 4:
  case 8:
    return 0xea6;
  }
  uVar1 = 0x9c4;
  if (param_1 == 0) {
    uVar1 = 0x4e2;
  }
  return uVar1;
}


