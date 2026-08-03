/*
 * Function: strtol
 * Entry:    0007adcc
 * Prototype: long __stdcall strtol(char * s, char * * ptr, int base)
 */


/* exclude_from_export */

long strtol(char *s,char **ptr,int base)

{
  long lVar1;
  locale_t in_stack_00000000;
  
  lVar1 = _strtol_l(_REENT,s,ptr,base,in_stack_00000000);
  return lVar1;
}


