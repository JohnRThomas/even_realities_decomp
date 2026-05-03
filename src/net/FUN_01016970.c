/*
 * Function: FUN_01016970
 * Entry:    01016970
 * Prototype: undefined * * * * * * __stdcall FUN_01016970(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined ******
FUN_01016970(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined ******ppppppuVar1;
  
  *(undefined2 *)((int)param_1 + 0xc5) = 0;
  *(undefined1 *)((int)param_1 + 0xc9) = 0;
  if (*(char *)((int)param_1 + 0x2eb) != '\0') {
    ppppppuVar1 = (undefined ******)FUN_01014698(param_1,2,0,param_4);
    return ppppppuVar1;
  }
  ppppppuVar1 = (undefined ******)FUN_01014698(param_1,3,0,param_4);
  return ppppppuVar1;
}


