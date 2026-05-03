/*
 * Function: FUN_01019960
 * Entry:    01019960
 * Prototype: undefined __stdcall FUN_01019960(byte * param_1)
 */


void FUN_01019960(byte *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_r4;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)*param_1;
  if ((*param_1 & 1) == 0) {
    uVar4 = 1;
    uVar1 = uVar2 & 1;
  }
  else {
    DAT_21000fe4 = param_1[1];
    uVar4 = 2;
    if (DAT_21000fe4 == 3) {
      unaff_r4 = 0;
    }
    DAT_2100104d = 1;
    uVar1 = 1;
    if (DAT_21000fe4 == 3) {
      DAT_21000fe0 = unaff_r4;
    }
  }
  uVar3 = uVar2 & 1;
  if ((int)(uVar2 << 0x1e) < 0) {
    DAT_21000fe4 = param_1[2];
    if (DAT_21000fe4 == 3) {
      DAT_21000fe0 = 0;
    }
    (&DAT_2100104d)[uVar1] = 2;
    uVar3 = uVar4;
  }
  if ((int)(uVar2 << 0x1d) < 0) {
    DAT_21000fe4 = param_1[3];
    if (DAT_21000fe4 == 3) {
      DAT_21000fe0 = 0;
    }
    (&DAT_2100104d)[uVar3] = 8;
  }
  DAT_21000fd4 = param_1[4];
  DAT_21000fe5 = param_1[5];
  DAT_21000fdd = (param_1[5] & 0xfd) == 0;
  DAT_21000fdc = param_1[6];
  DAT_21000fe7 = param_1[7];
  return;
}


