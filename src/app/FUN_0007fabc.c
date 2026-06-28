/*
 * Function: $_FUN_0007fabc
 * Entry:    0007fabc
 * Prototype: undefined4 __stdcall $_FUN_0007fabc(undefined4 * param_1, int * param_2)
 */


undefined4 __FUN_0007fabc(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == (int *)0x0)) {
    uVar2 = 7;
  }
  else {
    iVar4 = 0;
    iVar5 = 0;
    for (pbVar3 = (byte *)*param_1; pbVar3 != (byte *)0x0; pbVar3 = *(byte **)(pbVar3 + 0x18)) {
      iVar1 = __read_block(pbVar3);
      iVar4 = iVar4 + 1;
      iVar5 = iVar5 + iVar1;
    }
    *param_2 = iVar5;
    param_2[1] = iVar4;
    uVar2 = 0;
  }
  return uVar2;
}


