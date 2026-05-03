/*
 * Function: FUN_0008027a
 * Entry:    0008027a
 * Prototype: int __stdcall FUN_0008027a(char * param_1, int param_2, int param_3)
 */


int FUN_0008027a(char *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(param_2 + 0xeec) == param_3) {
    iVar1 = -1;
  }
  else {
    *(int *)(param_2 + 0xeec) = param_3;
    if (((*(char *)(param_2 + 0xfee) == '\n') && (param_3 != 0)) &&
       (*(char *)(param_2 + 0xb0c) == '\0')) {
      *(undefined1 *)(param_2 + 0xfed) = 1;
      k_sem_give((k_sem *)(param_2 + 0xaf4));
    }
    iVar1 = 0;
  }
  return iVar1;
}


