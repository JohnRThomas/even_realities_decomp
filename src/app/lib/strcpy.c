/*
 * Function: strcpy
 * Entry:    0008a80a
 * Prototype: char * __stdcall strcpy(char * d, char * s)
 */


/* exclude_from_export */

char * strcpy(char *d,char *s)

{
  char cVar1;
  char *pcVar2;
  int in_r2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar2 = s + -1;
  pcVar3 = d;
  do {
    pcVar4 = pcVar3;
    if (in_r2 == 0) break;
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
    in_r2 = in_r2 + -1;
    pcVar4 = pcVar3 + 1;
    *pcVar3 = cVar1;
    pcVar3 = pcVar4;
  } while (cVar1 != '\0');
  pcVar2 = pcVar4 + in_r2;
  for (; pcVar4 != pcVar2; pcVar4 = pcVar4 + 1) {
    *pcVar4 = '\0';
  }
  return d;
}


