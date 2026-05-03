/*
 * Function: FUN_000542f0
 * Entry:    000542f0
 * Prototype: int __stdcall FUN_000542f0(int param_1, int param_2)
 */


int FUN_000542f0(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)(param_1 + -1);
  while ((int)(puVar1 + (1 - param_1)) < param_2) {
    if (puVar1[1] == '\n') {
      (*DAT_2000288c)(0xd);
    }
    puVar1 = puVar1 + 1;
    (*DAT_2000288c)(*puVar1);
  }
  return param_2;
}


