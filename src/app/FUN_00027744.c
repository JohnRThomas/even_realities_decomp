/*
 * Function: FUN_00027744
 * Entry:    00027744
 * Prototype: undefined4 __stdcall FUN_00027744(undefined4 param_1, uint3 param_2, undefined4 param_3)
 */


undefined4 FUN_00027744(undefined4 param_1,uint3 param_2,undefined4 param_3)

{
  char cVar1;
  uint uVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = (uint)param_2;
  uStack_10 = param_3;
  FUN_000336ec();
  if (DAT_200083dc == 0) {
    cVar1 = eeprom_write(1);
    if (cVar1 < '\0') {
      return 0;
    }
    uVar5 = FUN_0007fd5a(global_st25dv_context_ptr,(int)&uStack_14 + 3);
    uVar3 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar4 = extraout_r2;
    if ((int)uVar5 == 0) {
      uVar2 = uStack_14 >> 0x18 & 0xfe;
      uStack_14 = CONCAT13((char)uVar2,(undefined3)uStack_14);
      FUN_0007fd66((int)global_st25dv_context_ptr,uVar2,extraout_r2);
      uVar3 = extraout_r1;
      uVar4 = extraout_r2_00;
    }
    FUN_0002715c(0xff,uVar3,uVar4);
    cVar1 = eeprom_write(0);
    if (cVar1 < '\0') {
      return 0;
    }
    DAT_200083dc = 1;
  }
  if (DAT_20002385 == '\x01') {
    DAT_20002384 = DAT_20002385;
    DAT_20002388 = 0x9010000;
    DAT_2000238c = 0xa031e09;
    DAT_20002386 = 0;
    DAT_20002390 = 0x50100;
    DAT_20002394 = 0;
    DAT_2000239c = 0x200;
    DAT_200023ae = 0x101;
    DAT_200023b0 = 0xa0a;
    DAT_200023b4 = 0xf000000;
    DAT_20002398 = 0;
    DAT_2000239e = 0;
    DAT_200023a5 = 0;
    DAT_200023a7 = 0;
    DAT_200023a8 = 0;
    DAT_200023ac = 0;
    DAT_200023b8 = 0;
    DAT_200023ba = 0;
    DAT_20002380 = 1;
  }
  FUN_000276f4(0x2000840c,(char *)&DAT_20002380);
  FUN_00033d5c();
  FUN_0000fd28(0x20002380);
  return 0;
}


