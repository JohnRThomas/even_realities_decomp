/*
 * Function: FUN_01029e52
 * Entry:    01029e52
 * Prototype: bool __stdcall FUN_01029e52(int param_1, int param_2)
 */


bool FUN_01029e52(int param_1,int param_2)

{
  bool bVar1;
  
  if (param_1 == 1) {
    bVar1 = param_2 == 1;
  }
  else if (param_1 == 2) {
    bVar1 = param_2 == 2;
  }
  else {
    if (param_1 != 4) {
      return false;
    }
    bVar1 = param_2 == 4;
  }
  return bVar1;
}


