/*
 * Function: FUN_0006b49e
 * Entry:    0006b49e
 * Prototype: longlong __stdcall FUN_0006b49e(undefined4 param_1, int param_2, int param_3, int param_4)
 */


longlong FUN_0006b49e(undefined4 param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint extraout_r1;
  int unaff_r4;
  char in_OV;
  int iStack00000000;
  
  puVar1 = (undefined4 *)(uint)*(ushort *)(param_3 + unaff_r4);
  if (param_2 < 0 != (bool)in_OV) {
    puVar3 = (undefined4 *)(uint)*(ushort *)(param_4 * 2);
    if ((((char *)*puVar1 == (char *)0x0) || (*(char *)*puVar1 == '\0')) || (1 < (uint)puVar1[2])) {
      uVar2 = 0xffffffea;
    }
    else {
      puVar3 = puVar1 + 0x11;
      puVar1[1] = &DAT_20002c5c;
      puVar1[0x12] = DAT_2000be28;
      puVar1[0x11] = &DAT_2000be24;
      uVar2 = 0;
      puVar1 = puVar3;
      *DAT_2000be28 = puVar3;
      DAT_2000be28 = puVar1;
    }
    return CONCAT44(puVar3,uVar2);
  }
  iStack00000000 = param_4;
  metal_linux_bus_finish();
  return (ulonglong)extraout_r1 << 0x20;
}


