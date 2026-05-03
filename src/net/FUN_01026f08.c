/*
 * Function: FUN_01026f08
 * Entry:    01026f08
 * Prototype: undefined __stdcall FUN_01026f08(undefined1 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01026f08(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined *puVar2;
  ushort local_18;
  short local_16;
  short local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
  uStack_a = (undefined2)((uint)param_4 >> 0x10);
  local_e = 0;
  uStack_c = 0;
  puVar2 = *(undefined **)(param_1 + 2);
  if (puVar2 < &DAT_00001d4c) {
    sVar1 = (short)((uint)puVar2 / 1000) + 0xd00;
  }
  else {
    sVar1 = (short)((uint)puVar2 / 0x4e2);
  }
  _local_18 = CONCAT22(sVar1,CONCAT11(param_1[1],*param_1));
  _local_14 = CONCAT22(*(undefined2 *)(param_1 + 6),sVar1);
  local_10 = *(undefined2 *)(param_1 + 8);
  FUN_010295a4(&local_18);
  return;
}


