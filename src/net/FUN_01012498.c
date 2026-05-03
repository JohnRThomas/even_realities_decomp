/*
 * Function: FUN_01012498
 * Entry:    01012498
 * Prototype: undefined __stdcall FUN_01012498(void)
 */


void FUN_01012498(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  char cVar3;
  uint uVar4;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r1_01;
  undefined4 extraout_r1_02;
  undefined4 uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar6;
  undefined4 in_r3;
  
  puVar1 = DAT_21000f4c;
  if (DAT_21000f24 == '\0') {
    return;
  }
  if (((DAT_21000f24 == '\x02') || (DAT_21000f24 == '\x03')) && (DAT_21000f32 != '\0')) {
    FUN_010210b0();
    FUN_010204a8();
    FUN_010264c8();
    uVar5 = extraout_r1_02;
    uVar6 = extraout_r2_02;
  }
  else {
    FUN_010264c8();
    uVar5 = extraout_r1;
    uVar6 = extraout_r2;
  }
  if ((DAT_21000f50 != '\0') &&
     (cVar3 = FUN_01014534(puVar1), puVar2 = DAT_21000f4c, uVar5 = extraout_r1_00,
     uVar6 = extraout_r2_00, cVar3 != '\0')) {
    uVar5 = extraout_r2_00;
    if ((-1 < (int)((uint)*(ushort *)(DAT_21000f4c + 2) << 0x1c)) &&
       (uVar4 = FUN_010132d4(DAT_21000f4c + 0x28), uVar5 = extraout_r2_01, uVar4 == 0)) {
      FUN_01011e64(puVar2,extraout_r1_01,extraout_r2_01,in_r3);
      return;
    }
    FUN_010121ac(puVar2,1,uVar5);
    return;
  }
  FUN_01011e64(puVar1,uVar5,uVar6,in_r3);
  return;
}


