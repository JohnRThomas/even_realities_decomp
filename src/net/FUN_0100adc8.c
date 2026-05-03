/*
 * Function: FUN_0100adc8
 * Entry:    0100adc8
 * Prototype: int __stdcall FUN_0100adc8(uint param_1, byte param_2, byte param_3)
 */


int FUN_0100adc8(uint param_1,byte param_2,byte param_3)

{
  ushort uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined2 local_a;
  
  iVar2 = FUN_01027f42(0xf7,5,(ushort)param_3);
  uVar1 = (short)iVar2 + 3U & 0xfffc;
  if (param_1 != 0) {
    if ((param_1 & 3) != 0) {
      FUN_01009500(0x19,0x95,extraout_r2,param_1 & 3);
    }
    DAT_21000be4 = param_1;
    DAT_21000be8 = uVar1;
    for (local_a = 0; local_a < param_2; local_a = local_a + 1) {
      FUN_01027ee6((ushort *)(DAT_21000be4 + (uint)DAT_21000be8 * (uint)local_a),uVar1,0xf7,5,
                   (ushort)param_3);
    }
  }
  return (uint)uVar1 * (uint)param_2;
}


