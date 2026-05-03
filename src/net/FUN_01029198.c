/*
 * Function: FUN_01029198
 * Entry:    01029198
 * Prototype: undefined1 __stdcall FUN_01029198(char * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined1 FUN_01029198(char *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  undefined1 uVar2;
  
  bVar1 = FUN_01028cc2((int)param_1,param_2,param_3);
  if (bVar1) {
    uVar2 = 0xc;
  }
  else {
    FUN_0100cf00(*param_1 != '\0');
    uVar2 = 0;
  }
  return uVar2;
}


