/*
 * Function: FUN_010260cc
 * Entry:    010260cc
 * Prototype: int __stdcall FUN_010260cc(byte * param_1, byte * param_2, int param_3)
 */


int FUN_010260cc(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  if (param_3 == 0) {
    return 0;
  }
  if (param_3 + -1 != 0) {
    pbVar1 = param_1;
    do {
      pbVar3 = pbVar1;
      pbVar2 = param_2;
      if ((uint)*pbVar3 != (uint)*pbVar2) {
        return (uint)*pbVar3 - (uint)*pbVar2;
      }
      param_2 = pbVar2 + 1;
      pbVar1 = pbVar3 + 1;
    } while (param_1 + param_3 + -1 != pbVar3 + 1);
    return (uint)pbVar3[1] - (uint)pbVar2[1];
  }
  return (uint)*param_1 - (uint)*param_2;
}


