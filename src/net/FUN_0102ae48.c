/*
 * Function: FUN_0102ae48
 * Entry:    0102ae48
 * Prototype: int __stdcall FUN_0102ae48(void)
 */


int FUN_0102ae48(void)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_r3;
  
  iVar1 = FUN_0103b94c(0x210045b0,0xfb,4,in_r3);
  if ((iVar1 != 0) && (0 < DAT_21000580)) {
    FUN_01039ee2((byte *)"k_msgq alloc failed\n",extraout_r1,extraout_r2,DAT_21000580);
  }
  return iVar1;
}


