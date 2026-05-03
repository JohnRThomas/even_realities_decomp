/*
 * Function: ?_st25dv_write
 * Entry:    0002787c
 * Prototype: uint __stdcall ?_st25dv_write(undefined4 * param_1, undefined4 param_2, undefined4 param_3, void * param_4, size_t param_5)
 */


uint __st25dv_write(undefined4 *param_1,undefined4 param_2,undefined4 param_3,void *param_4,
                   size_t param_5)

{
  int iVar1;
  uint cycles_to_wait;
  undefined1 auStack_28 [4];
  undefined1 *local_24;
  int local_20;
  undefined1 local_1c;
  
  iVar1 = -(param_5 + 9 & 0xfffffff8);
  auStack_28[iVar1] = (char)((uint)param_3 >> 8);
  auStack_28[iVar1 + 1] = (char)param_3;
  memcpy(auStack_28 + iVar1 + 2,param_4,param_5);
  local_1c = 2;
  local_24 = auStack_28 + iVar1;
  local_20 = param_5 + 2;
  FUN_0007fbc6((device *)*param_1);
  i2c_delay(cycles_to_wait);
  if ((int)cycles_to_wait < 0) {
    printk("_st25dv_write  ret %d \n",cycles_to_wait);
  }
  return cycles_to_wait;
}


