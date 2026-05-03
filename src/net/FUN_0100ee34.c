/*
 * Function: FUN_0100ee34
 * Entry:    0100ee34
 * Prototype: uint __stdcall FUN_0100ee34(uint param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_0100ee34(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint extraout_r2;
  undefined4 unaff_r4;
  undefined4 unaff_r6;
  undefined8 uVar4;
  
  *(char *)(param_1 + 3) = (char)param_2;
  if (param_2 < 0x2b) {
    *(undefined *)(param_1 + 1) = (&DAT_0103c150)[param_2];
    return param_1;
  }
  if (param_2 == 0xff) {
    *(undefined1 *)(param_1 + 1) = 1;
    return param_1;
  }
  uVar4 = FUN_01009500(0x2a,0x474,param_3,param_4);
  puVar3 = (undefined4 *)((ulonglong)uVar4 >> 0x20);
  iVar2 = (int)uVar4;
  *puVar3 = unaff_r4;
  puVar3[1] = unaff_r6;
  if (extraout_r2 < 0x1c) {
    *(char *)(iVar2 + 1) = (char)extraout_r2;
    uVar1 = FUN_01026198((undefined4 *)(iVar2 + 3),puVar3 + 2,extraout_r2);
    return uVar1;
  }
  iVar2 = FUN_01009500(0x2a,0x47e,extraout_r2,iVar2 << 4);
  return (uint)*(ushort *)(iVar2 + 7);
}


