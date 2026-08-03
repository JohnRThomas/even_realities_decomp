/*
 * Function: log_set_timestamp_func
 * Entry:    000506cc
 * Prototype: undefined4 __stdcall log_set_timestamp_func(int param_1, uint32_t param_2)
 */


/* exclude_from_export */

undefined4 log_set_timestamp_func(int param_1,uint32_t param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0xffffffea;
  }
  else {
    DAT_20002818 = param_1;
    log_output_timestamp_freq_set(param_2);
    uVar1 = 0;
  }
  return uVar1;
}


