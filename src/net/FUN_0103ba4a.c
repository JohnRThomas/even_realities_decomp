/*
 * Function: FUN_0103ba4a
 * Entry:    0103ba4a
 * Prototype: int __stdcall FUN_0103ba4a(int param_1, int param_2)
 */


int FUN_0103ba4a(int param_1,int param_2)

{
  int iVar1;
  
  if ((int)*(char *)(param_1 + 0xe) == (int)*(char *)(param_2 + 0xe)) {
    iVar1 = 0;
  }
  else {
    iVar1 = (int)*(char *)(param_2 + 0xe) - (int)*(char *)(param_1 + 0xe);
  }
  return iVar1;
}


