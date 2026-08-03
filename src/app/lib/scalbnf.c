/*
 * Function: scalbnf
 * Entry:    0008a126
 * Prototype: float __stdcall scalbnf(float param_1, int param_2)
 */


/* exclude_from_export_ai */

float scalbnf(float param_1,int param_2)

{
  bool bVar1;
  int *piVar2;
  
  bVar1 = __isfinitef((uint)param_1);
  if ((bVar1) && (param_1 != 0.0)) {
    param_1 = ldexpf(param_1,param_2);
    bVar1 = __isfinitef((uint)param_1);
    if ((!bVar1) || (param_1 == 0.0)) {
      piVar2 = __errno();
      *piVar2 = 0x22;
    }
  }
  return param_1;
}


