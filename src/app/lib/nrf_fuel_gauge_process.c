/*
 * Function: nrf_fuel_gauge_process
 * Entry:    0000e340
 * Prototype: float __stdcall nrf_fuel_gauge_process(float param_1, float param_2, float param_3, float param_4, float * param_5)
 */


/* exclude_from_export */

float nrf_fuel_gauge_process(float param_1,float param_2,float param_3,float param_4,float *param_5)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  float local_20;
  float fStack_1c;
  float local_18;
  float local_14;
  float local_c;
  
  if ((int)param_2 < 0) {
    puVar2 = &DAT_20002d2c;
    puVar1 = &DAT_20002d30;
  }
  else {
    puVar2 = &DAT_20002d34;
    puVar1 = &DAT_20002d38;
  }
  DAT_2000bed8 = *puVar2;
  DAT_2000bed4 = *puVar1;
  nrf_fuel_gauge_internal_0
            (param_1,param_2,param_3,param_4,(float *)((int)&_current.tls + 2),&local_20,&fStack_1c,
             &local_18);
  if (param_5 != (float *)0x0) {
    *param_5 = local_18;
    param_5[1] = local_14;
    param_5[2] = local_c;
  }
  return local_20 * 100.0;
}


