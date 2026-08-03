/*
 * Function: strlen
 * Entry:    0000ef12
 * Prototype: size_t __stdcall strlen(char * s)
 */


/* exclude_from_export */

size_t strlen(char *s)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = s;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (size_t)(pcVar2 + (-1 - (int)s));
}


