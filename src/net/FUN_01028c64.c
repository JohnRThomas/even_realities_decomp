/*
 * Function: FUN_01028c64
 * Entry:    01028c64
 * Prototype: int __stdcall FUN_01028c64(int param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_01028c64(int param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_1) {
  case 1:
  case 2:
    return param_1;
  default:
    FUN_01009500(6,0x294,param_3,param_1 + -1);
    break;
  case 4:
  case 8:
    break;
  }
  return 3;
}


