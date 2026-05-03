/*
 * Function: FUN_000506cc
 * Entry:    000506cc
 * Prototype: undefined4 __stdcall FUN_000506cc(int param_1, char * param_2)
 */


undefined4 FUN_000506cc(int param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    DAT_20002818 = param_1;
    FUN_00051160(param_2);
    uVar1 = 0;
  }
  return uVar1;
}


