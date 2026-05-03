/*
 * Function: FUN_0103bd40
 * Entry:    0103bd40
 * Prototype: int __stdcall FUN_0103bd40(byte * param_1, int param_2, int param_3)
 */


int FUN_0103bd40(byte *param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    pbVar3 = (byte *)(param_2 + -1);
    pbVar1 = param_1;
    do {
      uVar4 = (uint)*pbVar1;
      pbVar3 = pbVar3 + 1;
      if ((uVar4 != *pbVar3) || (pbVar1 + 1 == param_1 + param_3)) break;
      pbVar1 = pbVar1 + 1;
    } while (uVar4 != 0);
    iVar2 = uVar4 - *pbVar3;
  }
  return iVar2;
}


