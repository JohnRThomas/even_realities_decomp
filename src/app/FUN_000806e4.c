/*
 * Function: FUN_000806e4
 * Entry:    000806e4
 * Prototype: undefined __stdcall FUN_000806e4(int param_1, int * param_2)
 */


void FUN_000806e4(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 0xff8) + 0x164);
  if (iVar1 != 0) {
    **(int **)(param_1 + 0xff0) = iVar1;
  }
  FUN_0004d494(param_2,0,0);
  if (*(int *)(*(int *)(param_1 + 0xff8) + 0x164) != 0) {
    *(undefined4 *)(*(int *)(param_1 + 0xff8) + 0x164) = **(undefined4 **)(param_1 + 0xff0);
  }
  DAT_2007fc00 = **(undefined4 **)(param_1 + 0xff0);
  return;
}


