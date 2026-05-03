/*
 * Function: FUN_0103a3be
 * Entry:    0103a3be
 * Prototype: int __stdcall FUN_0103a3be(uint * param_1, int param_2)
 */


int FUN_0103a3be(uint *param_1,int param_2)

{
  int iVar1;
  int local_c;
  
  local_c = param_2;
  iVar1 = FUN_0103a398(param_1,&local_c);
  if (iVar1 != 0) {
    local_c = local_c + -1 + param_1[3];
  }
  return (param_1[9] - local_c) + -1;
}


