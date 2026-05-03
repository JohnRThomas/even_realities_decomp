/*
 * Function: FUN_0102713a
 * Entry:    0102713a
 * Prototype: undefined __stdcall FUN_0102713a(ushort * param_1, ushort param_2, ushort param_3, byte param_4, short param_5)
 */


void FUN_0102713a(ushort *param_1,ushort param_2,ushort param_3,byte param_4,short param_5)

{
  ushort uVar1;
  uint uVar2;
  uint extraout_r2;
  
  uVar1 = FUN_0102727e(param_3,param_4,param_5);
  uVar2 = (uint)param_2;
  if (uVar2 < uVar1) {
    FUN_01009500(0x14,0x9e,uVar2,(uint)uVar1);
    uVar2 = extraout_r2;
  }
  if (((uint)param_1 & 3) != 0) {
    FUN_01009500(0x14,0x9f,uVar2,(uint)param_1 & 3);
  }
  FUN_01026284((undefined4 *)param_1,0,0x18);
  *(byte *)((int)param_1 + 0x13) = param_4;
  uVar1 = FUN_0102709c(param_3,param_4,param_5);
  param_1[1] = uVar1;
  if (0x8000 < param_1[1]) {
    FUN_01009500(0x14,0xa4,(int)(short)uVar1,(uint)param_1[1]);
  }
  *param_1 = param_3;
  return;
}


