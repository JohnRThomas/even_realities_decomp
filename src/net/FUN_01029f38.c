/*
 * Function: FUN_01029f38
 * Entry:    01029f38
 * Prototype: uint __stdcall FUN_01029f38(uint param_1, uint param_2)
 */


uint FUN_01029f38(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint extraout_r2;
  uint extraout_r2_00;
  uint uVar3;
  uint extraout_r3;
  uint extraout_r3_00;
  uint uVar4;
  uint uVar5;
  undefined2 uStack_1a;
  
  uVar4 = param_2 & 0xff;
  uVar5 = param_1 & 0xff;
  bVar1 = FUN_01029e52(uVar4,(param_2 << 0x10) >> 0x18);
  uVar2 = extraout_r2;
  uVar3 = extraout_r3;
  if ((bVar1) ||
     (bVar1 = FUN_01029e52(uVar5,extraout_r3), uVar2 = extraout_r2_00, uVar3 = extraout_r3_00, bVar1
     )) {
    uVar2 = uVar2 & uVar3 & uVar5 & uVar4;
    uVar4 = uVar2;
  }
  else {
    uVar2 = uVar5 & extraout_r2_00;
    uVar4 = extraout_r3_00 & uVar4;
  }
  if ((int)(uVar2 << 0x1e) < 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = uVar2 & 1;
    if ((uVar3 == 0) && (uVar3 = 0, (uVar2 & 4) != 0)) {
      uVar3 = 8;
    }
  }
  if ((int)(uVar4 << 0x1e) < 0) {
    uVar2 = 2;
  }
  else {
    uVar2 = uVar4 & 1;
    if ((uVar2 == 0) && (uVar2 = 0, (uVar4 & 4) != 0)) {
      uVar2 = 8;
    }
  }
  if ((uVar3 == 8) && (uStack_1a = (short)(param_1 >> 0x10), uStack_1a == 1)) {
    uVar3 = 4;
  }
  return uVar3 | uVar2 << 8;
}


