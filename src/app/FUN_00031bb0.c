/*
 * Function: FUN_00031bb0
 * Entry:    00031bb0
 * Prototype: void * __stdcall FUN_00031bb0(void)
 */


void * FUN_00031bb0(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 local_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  byte local_1c [4];
  undefined *local_18;
  undefined4 local_14;
  undefined4 uStack_10;
  undefined4 *local_c;
  
  iVar1 = cJSON_GetStringValue();
  if (iVar1 == 0) {
    local_c = &local_2c;
    local_2c = 0x37f8;
    uStack_28 = 0x800;
    uStack_24 = 0x3ff8;
    uStack_20 = 0x3ffc;
    local_1c[0] = 1;
    local_18 = &DAT_000a73a2;
    local_14 = 0x1b9c;
    uStack_10 = 0x2000;
    pvVar2 = print_array(local_1c,(void *)0x800);
  }
  else {
    pvVar2 = (void *)0xffffffff;
  }
  return pvVar2;
}


