/*
 * Function: FUN_0103bd20
 * Entry:    0103bd20
 * Prototype: int __stdcall FUN_0103bd20(byte * param_1, int param_2, int param_3)
 */


int FUN_0103bd20(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  
  pbVar1 = (byte *)(param_2 + -1);
  pbVar2 = param_1 + param_3;
  while( true ) {
    if (param_1 == pbVar2) {
      return 0;
    }
    pbVar1 = pbVar1 + 1;
    if ((uint)*param_1 != (uint)*pbVar1) break;
    param_1 = param_1 + 1;
  }
  return (uint)*param_1 - (uint)*pbVar1;
}


