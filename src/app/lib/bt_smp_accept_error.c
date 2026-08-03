/*
 * Function: bt_smp_accept_error
 * Entry:    0005fe8c
 * Prototype: undefined4 __stdcall bt_smp_accept_error(undefined4 param_1)
 */


/* exclude_from_export */

undefined4 bt_smp_accept_error(undefined4 param_1)

{
  char local_18 [4];
  char *local_14;
  undefined4 uStack_10;
  
  local_14 = "No available SMP context for conn %p";
  local_18[0] = '\x03';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  uStack_10 = param_1;
  LOG_ERR(&PTR_s_bt_smp_0008b930,0x1840,local_18);
  return 0xfffffff4;
}


