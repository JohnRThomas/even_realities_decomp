/*
 * Function: FUN_0103a816
 * Entry:    0103a816
 * Prototype: int __stdcall FUN_0103a816(int param_1, int param_2)
 */


int FUN_0103a816(int param_1,int param_2)

{
  return ((param_2 * param_1 + 3U & 0xfffffffc) +
         (param_1 * 0x12 + 9U & 0xfffffffc) + param_1 * 8 + 8) * 2;
}


