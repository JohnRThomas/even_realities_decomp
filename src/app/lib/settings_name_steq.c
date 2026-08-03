/*
 * Function: settings_name_steq
 * Entry:    00082938
 * Prototype: int __stdcall settings_name_steq(char * name, char * key, char * * next)
 */


/* exclude_from_export */

int settings_name_steq(char *name,char *key,char **next)

{
  char cVar1;
  char *pcVar2;
  
  if (next != (char **)0x0) {
    *next = (char *)0x0;
  }
  if (name != (char *)0x0) {
    if (key == (char *)0x0) {
      return 0;
    }
    pcVar2 = key + -1;
    do {
      pcVar2 = pcVar2 + 1;
      cVar1 = *pcVar2;
      if (cVar1 == '\0') {
        cVar1 = *name;
        if (cVar1 == '/') {
          if (next != (char **)0x0) {
            *next = name + 1;
          }
        }
        else if (cVar1 != '=') {
          return (uint)(cVar1 == '\0');
        }
        return 1;
      }
    } while ((cVar1 == *name) && (name = name + 1, cVar1 != '='));
  }
  return 0;
}


