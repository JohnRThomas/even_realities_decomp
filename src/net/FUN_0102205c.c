/*
 * Function: FUN_0102205c
 * Entry:    0102205c
 * Prototype: undefined __stdcall FUN_0102205c(undefined4 * param_1, undefined2 param_2)
 */


void FUN_0102205c(undefined4 *param_1,undefined2 param_2)

{
  undefined2 uVar1;
  
  uVar1 = DAT_210016c0;
  if ((DAT_210016bc == (undefined4 *)0x0) &&
     (DAT_210016b4 = param_1, DAT_210016bc = FUN_0102824a(param_1), uVar1 = param_2,
     DAT_210016bc == (undefined4 *)0x0)) {
    FUN_01009500(0x84,0x22,&DAT_210016bc,0);
    uVar1 = param_2;
  }
  DAT_210016c0 = uVar1;
  return;
}


