/*
 * Function: FUN_000809b6
 * Entry:    000809b6
 * Prototype: undefined8 __stdcall FUN_000809b6(uint param_1, int param_2, uint param_3, int param_4)
 */


undefined8 FUN_000809b6(uint param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((int)((param_2 - param_4) - (uint)(param_1 < param_3)) < 0 ==
      (SBORROW4(param_2,param_4) != SBORROW4(param_2 - param_4,(uint)(param_1 < param_3)))) {
    iVar1 = param_1 - param_3;
    iVar2 = (param_2 - param_4) - (uint)(param_1 < param_3);
  }
  else {
    iVar1 = param_3 - param_1;
    iVar2 = (param_4 - param_2) - (uint)(param_3 < param_1);
  }
  return CONCAT44(iVar2,iVar1);
}


