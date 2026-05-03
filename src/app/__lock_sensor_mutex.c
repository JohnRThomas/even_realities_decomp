/*
 * Function: ?_lock_sensor_mutex
 * Entry:    000346d0
 * Prototype: undefined4 __stdcall ?_lock_sensor_mutex(undefined4 param_1, undefined4 param_2)
 */


undefined4 __lock_sensor_mutex(undefined4 param_1,undefined4 param_2)

{
  if (DAT_20002424 != 0) {
    FUN_0007fc18(DAT_20002424,param_2);
  }
  return 0;
}


