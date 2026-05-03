/*
 * Function: FUN_0100dba0
 * Entry:    0100dba0
 * Prototype: undefined __stdcall FUN_0100dba0(int param_1, int param_2, int param_3)
 */


void FUN_0100dba0(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  if (param_3 != 0) {
    puVar1 = (undefined1 *)(param_3 + param_2);
    puVar2 = (undefined1 *)(param_1 + -1);
    do {
      puVar1 = puVar1 + -1;
      puVar2 = puVar2 + 1;
      *puVar2 = *puVar1;
    } while ((undefined1 *)(param_1 + (param_3 - 1U & 0xff)) != puVar2);
  }
  return;
}


