/*
 * Function: FUN_00080dd2
 * Entry:    00080dd2
 * Prototype: undefined __stdcall FUN_00080dd2(ushort param_1, ushort param_2, undefined4 param_3, uint param_4)
 */


void FUN_00080dd2(ushort param_1,ushort param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = (uint)param_2;
  for (; 0xf000 < (int)param_4; param_4 = param_4 - 0xf000) {
    FUN_0004af6c((uint)param_1,uVar1,param_3,0xf000);
    uVar1 = uVar1 + 0xc0 & 0xffff;
  }
  FUN_0004af6c((uint)param_1,uVar1,param_3,param_4);
  FUN_00080ece(0x97);
  busy_wait_seconds(1);
  return;
}


