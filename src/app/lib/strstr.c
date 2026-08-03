/*
 * Function: strstr
 * Entry:    0008a86e
 * Prototype: char * __stdcall strstr(char * s, char * find)
 */


/* exclude_from_export_ai */

char * strstr(char *s,char *find)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  if (*find != '\0') {
    for (; *s != '\0'; s = s + 1) {
      pcVar2 = find;
      pcVar3 = s;
      if (*find == *s) {
        do {
          cVar1 = pcVar2[1];
          if (cVar1 == '\0') {
            return s;
          }
          pcVar3 = pcVar3 + 1;
          pcVar2 = pcVar2 + 1;
        } while (*pcVar3 == cVar1);
      }
    }
    s = (char *)0x0;
  }
  return s;
}


