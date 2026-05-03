/*
 * Function: FUN_01016590
 * Entry:    01016590
 * Prototype: undefined __stdcall FUN_01016590(ushort param_1, int param_2, undefined4 param_3)
 */


void FUN_01016590(ushort param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r3;
  undefined4 extraout_r3_00;
  
  FUN_0100a848(param_1,param_2,param_3);
  if (*(byte *)(param_2 + 0x364) != 0x20) {
    FUN_0102491c((uint)*(byte *)(param_2 + 0x364),extraout_r1,extraout_r2,extraout_r3);
    cVar1 = FUN_010236bc((uint)*(byte *)(param_2 + 0x364));
    if (cVar1 == '\0') {
      FUN_01009500(0x31,0x963,extraout_r2_00,extraout_r3_00);
      DAT_21000f70 = 0;
      DAT_21000f88 = 0;
      return;
    }
  }
  return;
}


