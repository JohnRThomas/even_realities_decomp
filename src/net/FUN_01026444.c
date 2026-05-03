/*
 * Function: FUN_01026444
 * Entry:    01026444
 * Prototype: undefined __stdcall FUN_01026444(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_01026444(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined1 uVar2;
  undefined4 local_14;
  
  local_14 = param_2;
  if (4 < param_1) {
    FUN_01025edc(0x68,0x13d,param_3,param_4);
  }
  FUN_010263f8();
  DAT_21001c88 = 1;
  if (DAT_21001c89 == '\x02') {
    uVar1 = (*(code *)DAT_21001c90[3])(param_1);
    if ((byte)(&DAT_21001c9d)[param_1 * 2] < uVar1) {
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
      if (DAT_21001ca6 != '\x01') {
        uVar2 = (&DAT_21001c9c)[param_1 * 2];
      }
    }
    local_14._0_2_ = CONCAT11((char)param_1,uVar2);
    (*(code *)*DAT_21001c90)(&local_14);
  }
  return;
}


