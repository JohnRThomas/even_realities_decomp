/*
 * Function: FUN_01016a50
 * Entry:    01016a50
 * Prototype: undefined4 __stdcall FUN_01016a50(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01016a50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined1 *extraout_r1;
  
  switch(param_1) {
  case 0:
  case 2:
    return 1;
  case 1:
  case 3:
    return 0;
  default:
    FUN_01009500(0x77,0x225,param_3,param_4);
  }
  do {
    *extraout_r1 = 6;
    uVar1 = DAT_21000fc5;
    *(undefined2 *)(extraout_r1 + 3) = DAT_21000fc3;
    extraout_r1[5] = uVar1;
  } while( true );
}


