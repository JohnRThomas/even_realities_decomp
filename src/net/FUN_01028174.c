/*
 * Function: FUN_01028174
 * Entry:    01028174
 * Prototype: int __stdcall FUN_01028174(int param_1, int param_2, short param_3, int param_4)
 */


int FUN_01028174(int param_1,int param_2,short param_3,int param_4)

{
  short local_32;
  int local_30;
  int *local_c;
  
  local_c = (int *)(param_2 + param_1);
  local_32 = param_3;
  while( true ) {
    local_30 = param_4 + param_2;
    local_32 = local_32 + -1;
    if (local_32 == 0) break;
    param_2 = local_30;
    if (param_1 != 0) {
      *local_c = 0;
      local_c[1] = 0;
      *(undefined1 *)(local_c + 2) = 0;
      *local_c = (int)local_c + param_4;
      local_c = (int *)*local_c;
    }
  }
  if (param_1 != 0) {
    *local_c = 0;
    local_c[1] = 0;
    *(undefined1 *)(local_c + 2) = 0;
  }
  return local_30;
}


