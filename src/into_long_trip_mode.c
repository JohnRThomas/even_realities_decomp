/*
 * Function: into_long_trip_mode
 * Entry:    00032268
 * Prototype: undefined4 __stdcall into_long_trip_mode(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
into_long_trip_mode(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 uVar3;
  
  printk("join in into_long_trip_mode\n");
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("into_long_trip_mode para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *puVar2 = 6;
    puVar2[1] = 1;
    if (*(char *)(param_1 + 2) == '\x02') {
      DAT_20019a62 = 1;
      set_box_status(LID_CLOSED,true);
      FUN_0002c6f4(10000);
      uVar3 = 2;
    }
    else {
      uVar3 = 3;
    }
    uVar1 = 0;
    puVar2[3] = 1;
    puVar2[2] = uVar3;
    puVar2[4] = 0;
    *param_4 = 5;
  }
  return uVar1;
}


