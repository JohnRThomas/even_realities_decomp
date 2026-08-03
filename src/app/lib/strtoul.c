/*
 * Function: strtoul
 * Entry:    0007aec4
 * Prototype: ulong __stdcall strtoul(char * nptr, char * * endptr, int base)
 */


/* exclude_from_export_ai */

ulong strtoul(char *nptr,char **endptr,int base)

{
  ulong uVar1;
  locale_t in_stack_00000000;
  
  uVar1 = _strtoul_l(_REENT,nptr,endptr,base,in_stack_00000000);
  return uVar1;
}


