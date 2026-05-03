/*
 * Function: FUN_0103ba04
 * Entry:    0103ba04
 * Prototype: uint __stdcall FUN_0103ba04(uint * param_1, uint param_2)
 */


uint FUN_0103ba04(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = *param_1;
  *param_1 = uVar1 & ~(1 << (param_2 & 0xff));
  return uVar1 >> (param_2 & 0xff) & 1;
}


