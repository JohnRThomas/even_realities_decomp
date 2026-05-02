/*
 * Function: FUN_000286c4
 * Entry:    000286c4
 * Prototype: float __stdcall FUN_000286c4(float param_1)
 */


float FUN_000286c4(float param_1)

{
  float fVar1;
  
  fVar1 = (float)(0x5f3759df - ((int)param_1 >> 1));
  fVar1 = (1.5 - fVar1 * param_1 * 0.5 * fVar1) * fVar1;
  return (1.5 - fVar1 * param_1 * 0.5 * fVar1) * fVar1;
}


