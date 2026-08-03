/*
 * Function: strtod
 * Entry:    0007acb8
 * Prototype: int __stdcall strtod(void)
 */


/* exclude_from_export_ai */

int strtod(void)

{
  char **in_r0;
  int extraout_r0;
  __locale_t in_r1;
  
  _strtod_l(_REENT,in_r0,in_r1);
  return extraout_r0;
}


