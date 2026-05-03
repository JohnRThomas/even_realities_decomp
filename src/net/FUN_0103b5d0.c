/*
 * Function: FUN_0103b5d0
 * Entry:    0103b5d0
 * Prototype: byte * __stdcall FUN_0103b5d0(undefined4 * param_1, int param_2, int param_3, int param_4)
 */


byte * FUN_0103b5d0(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  
  puVar2 = (undefined4 *)*param_1;
  do {
    if (param_1 == puVar2) {
      return (byte *)0x0;
    }
    pbVar3 = (byte *)(puVar2 + -0xd);
    if ((param_3 != -1) && (puVar2[-4] == param_3)) {
      return pbVar3;
    }
    while (param_2 != 0) {
      while( true ) {
        iVar1 = FUN_0103bd40(pbVar3,param_2,0x20);
        if (iVar1 != 0) goto LAB_0103b640;
        if ((param_4 != -1) && (*(int *)(pbVar3 + 0x28) == param_4)) {
          return pbVar3;
        }
        if (param_3 == -1) break;
        puVar2 = (undefined4 *)*puVar2;
        if (puVar2 == param_1) {
          return (byte *)0x0;
        }
        pbVar3 = (byte *)(puVar2 + -0xd);
        if (param_3 == puVar2[-4]) {
          return pbVar3;
        }
      }
      if (*(int *)(pbVar3 + 0x28) == -1) {
        return pbVar3;
      }
      puVar2 = (undefined4 *)*puVar2;
      if (puVar2 == param_1) {
        return (byte *)0x0;
      }
      pbVar3 = (byte *)(puVar2 + -0xd);
    }
LAB_0103b640:
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}


