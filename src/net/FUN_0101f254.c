/*
 * Function: FUN_0101f254
 * Entry:    0101f254
 * Prototype: undefined4 __stdcall FUN_0101f254(void)
 */


undefined4 FUN_0101f254(void)

{
  short sVar1;
  short sVar2;
  int unaff_r7;
  
  sVar1 = *(short *)(unaff_r7 * 0x10000);
  if (((ushort)(sVar1 - 0x1bU) < 0xe1) &&
     (sVar2 = ((short *)(unaff_r7 * 0x10000))[1], (ushort)(sVar2 - 0x148U) < 0x4149)) {
    DAT_21001208._0_2_ = sVar1;
    DAT_21001208._2_2_ = sVar2;
    return 0;
  }
  return 0x12;
}


