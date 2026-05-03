/*
 * Function: FUN_0007f556
 * Entry:    0007f556
 * Prototype: undefined4 __stdcall FUN_0007f556(int param_1)
 */


undefined4 FUN_0007f556(int param_1)

{
  undefined1 local_3c;
  undefined1 local_3b;
  undefined1 local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 local_33;
  undefined1 local_32;
  undefined1 local_31;
  undefined4 local_30;
  undefined2 local_2c;
  undefined1 local_2a;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined4 local_20;
  undefined1 local_1c;
  ushort local_1a;
  undefined2 local_18;
  
  memset(&local_25,0,0x15);
  local_3c = *(undefined1 *)(param_1 + 0xfee);
  local_3a = *(undefined1 *)(param_1 + 0xef8);
  local_2c = *(undefined2 *)(param_1 + 0x1085);
  local_3b = *(undefined1 *)(param_1 + 0xed5);
  local_30 = *(undefined4 *)(param_1 + 0x1081);
  local_39 = *(undefined1 *)(param_1 + 0xf64);
  local_38 = *(undefined4 *)(param_1 + 0xf70);
  local_34 = *(undefined1 *)(param_1 + 0xf9c);
  local_33 = *(undefined1 *)(param_1 + 0x1088);
  local_32 = *(undefined1 *)(param_1 + 0x10d4);
  local_31 = *(undefined1 *)(param_1 + 0xec0);
  local_2a = *(undefined1 *)(param_1 + 0x1087);
  local_29 = *(undefined1 *)(param_1 + 0xef9);
  local_28 = *(undefined1 *)(param_1 + 0x10d6);
  local_27 = *(undefined1 *)(param_1 + 0x10d8);
  local_26 = *(undefined1 *)(param_1 + 0x10d9);
  local_25 = FUN_00033d5c();
  local_24 = *(undefined1 *)(param_1 + 0xec1);
  local_20 = *(undefined4 *)(param_1 + 0xf6c);
  local_23 = *(undefined1 *)(param_1 + 0x10d7);
  local_22 = *(undefined1 *)(param_1 + 0x1244);
  local_1c = *(undefined1 *)(*(int *)(param_1 + 0xff0) + 0x5f);
  local_1a = (ushort)*(byte *)(param_1 + 0xee0);
  local_18 = *(undefined2 *)(param_1 + 0x1246);
  flash_settings_write_and_verify(0x134000,&local_3c,0x2c);
  return 0;
}


