/*
 * Function: FUN_0103b9a2
 * Entry:    0103b9a2
 * Prototype: uint * __stdcall FUN_0103b9a2(uint * param_1, int param_2)
 */


uint * FUN_0103b9a2(uint *param_1,int param_2)

{
  uint *puVar1;
  
  puVar1 = param_1;
  if (((param_1 != (uint *)0x0) && ((*param_1 & 3) != 0)) &&
     (puVar1 = (uint *)param_1[1], param_2 != 0)) {
    FUN_0103bce2((int)param_1);
  }
  return puVar1;
}


