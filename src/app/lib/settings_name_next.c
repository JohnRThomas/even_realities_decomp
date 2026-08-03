/*
 * Function: settings_name_next
 * Entry:    00082980
 * Prototype: int __stdcall settings_name_next(char * name, char * * next)
 */


/* exclude_from_export_ai */

int settings_name_next(char *name,char **next)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  
  if (next != (char **)0x0) {
    *next = (char *)0x0;
  }
  iVar3 = 0;
  pcVar2 = name;
  if (name != (char *)0x0) {
    do {
      pcVar4 = pcVar2;
      cVar1 = *pcVar4;
      if ((cVar1 == '\0') || (cVar1 == '=')) goto LAB_000829a0;
      pcVar2 = pcVar4 + 1;
    } while (cVar1 != '/');
    if (next != (char **)0x0) {
      *next = pcVar4 + 1;
    }
LAB_000829a0:
    iVar3 = (int)pcVar4 - (int)name;
  }
  return iVar3;
}


