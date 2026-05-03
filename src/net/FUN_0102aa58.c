/*
 * Function: FUN_0102aa58
 * Entry:    0102aa58
 * Prototype: undefined __stdcall FUN_0102aa58(char * param_1, char * param_2)
 */


void FUN_0102aa58(char *param_1,char *param_2)

{
  char cVar1;
  
  do {
    cVar1 = *param_2;
    *param_1 = cVar1;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return;
}


