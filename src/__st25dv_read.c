/*
 * Function: ?_st25dv_read
 * Entry:    0002794c
 * Prototype: uint __stdcall ?_st25dv_read(device * param_1, undefined4 param_2, uint param_3, undefined4 param_4, undefined4 param_5)
 */


uint __st25dv_read(device *param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                  undefined4 param_5)

{
  uint cycles_to_wait;
  ushort local_24 [2];
  ushort *local_20;
  undefined4 local_1c;
  undefined1 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  
  local_24[0] = (ushort)((param_3 & 0xff) << 8) | (ushort)(param_3 >> 8) & 0xff;
  local_10 = param_5;
  local_20 = local_24;
  local_c = 7;
  local_1c = 2;
  local_18 = 0;
  local_14 = param_4;
  FUN_0007fbc6(param_1);
  i2c_delay(cycles_to_wait);
  if ((int)cycles_to_wait < 0) {
    printk("_st25dv_read  ret %d \n",cycles_to_wait);
  }
  return cycles_to_wait;
}


