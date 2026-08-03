/*
 * Function: nrf_fuel_gauge_init
 * Entry:    0000e2b4
 * Prototype: undefined4 __stdcall nrf_fuel_gauge_init(float * param_1, undefined4 * param_2)
 */


/* exclude_from_export */

undefined4 nrf_fuel_gauge_init(float *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int in_stack_ffffffa0;
  bool *in_stack_ffffffa4;
  undefined *local_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 local_48;
  undefined *puStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined *puStack_30;
  undefined4 uStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined *puStack_1c;
  
  if (param_1 != (float *)0x0) {
    if (param_1[3] == 0.0) {
      uVar1 = 0xffffffea;
    }
    else {
      memset((void *)((int)&_current.tls + 2),0,0x1778);
      local_58 = &DAT_358637bd;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      local_48 = 0;
      puStack_44 = &DAT_358637bd;
      uStack_40 = 0;
      uStack_3c = 0;
      local_38 = 0;
      uStack_34 = 0;
      puStack_30 = &DAT_322bcc77;
      uStack_2c = 0;
      local_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      puStack_1c = &DAT_3951b717;
      nrf_fuel_gauge_internal_9
                ((lc3_dt)&local_58,(lc3_srate)param_1[3],(float *)((int)&_current.tls + 2),
                 (int)&stack0xffffffa4,*param_1,in_stack_ffffffa0,in_stack_ffffffa4);
      if (param_2 != (undefined4 *)0x0) {
        *param_2 = in_stack_ffffffa4;
      }
      uVar1 = 0;
    }
    return uVar1;
  }
  return 0xffffffea;
}


