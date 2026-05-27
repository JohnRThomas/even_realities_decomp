/*
 * Function: $_?_FUN_0008a766
 * Entry:    0008a766
 * Prototype: undefined __stdcall $_?_FUN_0008a766(int * param_1, int param_2)
 */


void ____FUN_0008a766(int *param_1,int param_2)

{
  int iVar1;
  
  DAT_2000d60c = 0;
  iVar1 = console_getchar((int)*(short *)(param_2 + 0xe));
  if ((iVar1 == -1) && (DAT_2000d60c != 0)) {
    *param_1 = DAT_2000d60c;
  }
  return;
}


