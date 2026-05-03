/*
 * Function: FUN_0103bd64
 * Entry:    0103bd64
 * Prototype: char * __stdcall FUN_0103bd64(char * param_1, int param_2, int param_3)
 */


char * FUN_0103bd64(char *param_1,int param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar4 = (char *)(param_2 + -1);
  pcVar2 = param_1;
  do {
    pcVar3 = pcVar2;
    if (param_3 == 0) break;
    pcVar4 = pcVar4 + 1;
    cVar1 = *pcVar4;
    param_3 = param_3 + -1;
    pcVar3 = pcVar2 + 1;
    *pcVar2 = cVar1;
    pcVar2 = pcVar3;
  } while (cVar1 != '\0');
  FUN_0103bdee(pcVar3,0,param_3);
  return param_1;
}


