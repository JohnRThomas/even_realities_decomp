/*
 * Function: FUN_00080fea
 * Entry:    00080fea
 * Prototype: undefined __stdcall FUN_00080fea(undefined1 * param_1, int param_2, uint param_3)
 */


void FUN_00080fea(undefined1 *param_1,int param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  puVar2 = (undefined4 *)(param_2 + -4);
  puVar3 = param_1;
  while ((uint)((int)puVar3 - (int)param_1) < param_3) {
    puVar1 = puVar2 + 1;
    *puVar3 = (char)*puVar1;
    puVar3[1] = (char)((uint)*puVar1 >> 8);
    puVar3[2] = (char)*(undefined2 *)((int)puVar2 + 6);
    puVar3[3] = *(undefined1 *)((int)puVar2 + 7);
    puVar2 = puVar1;
    puVar3 = puVar3 + 4;
  }
  return;
}


