/*
 * Function: FUN_0103bd84
 * Entry:    0103bd84
 * Prototype: int __stdcall FUN_0103bd84(char * param_1, int param_2)
 */


int FUN_0103bd84(char *param_1,int param_2)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar1 = param_1;
  do {
    pcVar2 = pcVar1;
    if (pcVar2 == param_1 + param_2) break;
    pcVar1 = pcVar2 + 1;
  } while (*pcVar2 != '\0');
  return (int)pcVar2 - (int)param_1;
}


