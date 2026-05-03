/*
 * Function: FUN_01013350
 * Entry:    01013350
 * Prototype: undefined8 __stdcall FUN_01013350(int param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


undefined8 FUN_01013350(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_r7;
  undefined8 uVar3;
  
  uVar1 = param_1 - 1;
  if (uVar1 < 3) {
    if (param_2 < 0x14) {
      if (0x11 < param_2) {
        return CONCAT44(param_2,(uint)*(ushort *)(&DAT_0103c1a4 + uVar1 * 2));
      }
      if (param_2 == 0x10) {
        return CONCAT44(0x10,(uint)*(ushort *)(&DAT_0103c194 + uVar1 * 2));
      }
    }
    else if (param_2 == 0x15) {
      return CONCAT44(0x15,(uint)*(ushort *)(&DAT_0103c19c + uVar1 * 2));
    }
    FUN_01009500(0x2f,0xd8,param_3,param_4);
    param_3 = extraout_r2;
    param_4 = extraout_r3;
  }
  uVar3 = FUN_01009500(0x2f,0xca,param_3,param_4);
  puVar2 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
  *puVar2 = extraout_r2_00;
  puVar2[1] = unaff_r4;
  puVar2[2] = unaff_r7;
  return CONCAT44(puVar2 + 3,(int)uVar3 * 0x35a);
}


