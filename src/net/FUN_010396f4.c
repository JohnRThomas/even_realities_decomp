/*
 * Function: FUN_010396f4
 * Entry:    010396f4
 * Prototype: undefined __stdcall FUN_010396f4(int * param_1, uint * param_2, int param_3)
 */


void FUN_010396f4(int *param_1,uint *param_2,int param_3)

{
  uint local_30 [8];
  
  FUN_0103bdee((undefined1 *)local_30,0,0x20);
  local_30[0] = 0;
  FUN_0103bdd4((int)param_1,(undefined1 *)param_2,0x20);
  FUN_010090e8((int *)local_30,local_30,param_2);
  FUN_01008ba8(param_1,(int *)local_30,param_3);
  return;
}


