/*
 * Function: __hexdig_fun
 * Entry:    0008aaf0
 * Prototype: char __stdcall __hexdig_fun(int param_1)
 */


/* exclude_from_export_ai */

char __hexdig_fun(int param_1)

{
  char cVar1;
  
  cVar1 = (char)param_1;
  if (param_1 - 0x30U < 10) {
    cVar1 = cVar1 + -0x20;
  }
  else if (param_1 - 0x61U < 6) {
    cVar1 = cVar1 + -0x47;
  }
  else {
    if (5 < param_1 - 0x41U) {
      return '\0';
    }
    cVar1 = cVar1 + -0x27;
  }
  return cVar1;
}


