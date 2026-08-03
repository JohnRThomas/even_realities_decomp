/*
 * Function: atoi
 * Entry:    0008a1b6
 * Prototype: int __stdcall atoi(char * s)
 */


/* exclude_from_export */

int atoi(char *s)

{
  long lVar1;
  
  lVar1 = strtol(s,(char **)0x0,10);
  return lVar1;
}


