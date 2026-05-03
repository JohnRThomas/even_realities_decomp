/*
 * Function: FUN_01010f7c
 * Entry:    01010f7c
 * Prototype: ulonglong __stdcall FUN_01010f7c(uint param_1, int param_2, undefined4 param_3, undefined4 param_4)
 */


ulonglong FUN_01010f7c(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  if ((param_1 & 7) == 0) {
    if (param_1 != 0) {
      DAT_21000f1c = (undefined1)param_2;
      DAT_21000f14 = 0;
      DAT_21000f18 = param_1;
    }
    return CONCAT44(param_2,param_2 << 3);
  }
  uVar1 = FUN_01009500(0x48,99,param_1 & 7,param_4);
  DAT_21000f14 = 0;
  return (ulonglong)uVar1;
}


