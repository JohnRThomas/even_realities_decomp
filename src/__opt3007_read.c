/*
 * Function: ?_opt3007_read
 * Entry:    0002fad0
 * Prototype: int __stdcall ?_opt3007_read(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int __opt3007_read(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if ((DAT_20019a6f == '\0') ||
     (uStack_c = param_2, uStack_8 = param_3,
     iVar1 = opt3007_reg_read(0,(ushort *)((int)&uStack_c + 2)), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = (uStack_c._2_2_ & 0xfff) << (uint)(uStack_c._2_2_ >> 0xc);
  }
  return iVar1;
}


