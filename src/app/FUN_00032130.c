/*
 * Function: FUN_00032130
 * Entry:    00032130
 * Prototype: undefined __stdcall FUN_00032130(undefined4 param_1, printbuffer * param_2)
 */


void FUN_00032130(undefined4 param_1,printbuffer *param_2)

{
  cJSON_bool cVar1;
  
  cVar1 = print_number((cJSON *)&DAT_20002408,param_2);
  if (-1 < cVar1) {
    DAT_200085ac = 1;
  }
  return;
}


