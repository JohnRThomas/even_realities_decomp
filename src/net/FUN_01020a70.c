/*
 * Function: FUN_01020a70
 * Entry:    01020a70
 * Prototype: ulonglong __stdcall FUN_01020a70(uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


ulonglong FUN_01020a70(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int unaff_r6;
  
  if (param_1 < 0x97) {
    DAT_2100160c = (short)param_1;
    return CONCAT44(param_2,param_1);
  }
  FUN_01009500(0x3e,0x1f5,param_3,param_4);
  return (ulonglong)((byte)(&DAT_0103c490)[unaff_r6 >> 0x17] + 0x960);
}


