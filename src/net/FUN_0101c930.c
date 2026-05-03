/*
 * Function: FUN_0101c930
 * Entry:    0101c930
 * Prototype: uint __stdcall FUN_0101c930(uint param_1)
 */


uint FUN_0101c930(uint param_1)

{
  uint uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  int iVar2;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  
  iVar2 = *(int *)(param_1 + 4);
  if (*(byte *)(iVar2 + 0xc5) == 0x1a) {
    *(undefined1 *)(iVar2 + 0xc5) = 0x1c;
    return param_1;
  }
  uVar1 = FUN_01009500(0x36,0x4fa,(uint)*(byte *)(iVar2 + 0xc5),iVar2);
  iVar2 = *(int *)(uVar1 + 4);
  if (*(byte *)(iVar2 + 0xc5) == 0x14) {
    *(undefined1 *)(iVar2 + 0x106) = 1;
    *(undefined1 *)(iVar2 + 0xc5) = 0x13;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4ea,(uint)*(byte *)(iVar2 + 0xc5),iVar2);
  uVar1 = FUN_0100dbc0(*(int *)(iVar2 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar2 + 4) + 0xc5),0);
  iVar2 = *(int *)(iVar2 + 4);
  if ((uVar1 != 0) || (*(char *)(iVar2 + 0x106) != '\0')) {
    *(undefined1 *)(iVar2 + 0x105) = 1;
    *(undefined1 *)(iVar2 + 0xc5) = 0x15;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4f1,0,iVar2);
  uVar1 = FUN_0100dbc0(*(int *)(iVar2 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar2 + 4) + 0xc5),0);
  if (uVar1 != 0) {
    iVar2 = *(int *)(iVar2 + 4);
    *(undefined1 *)(iVar2 + 0x105) = 1;
    *(undefined1 *)(iVar2 + 0xc5) = 0x11;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4e2,extraout_r2,extraout_r3);
  uVar1 = FUN_0100dbc0(*(int *)(iVar2 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar2 + 4) + 0xc5),0);
  if (uVar1 != 0) {
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0xc5) = 0xe;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4dc,extraout_r2_00,extraout_r3_00);
  uVar1 = FUN_0100dbc0(*(int *)(iVar2 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar2 + 4) + 0xc5),0);
  if (uVar1 != 0) {
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0xc5) = 0xc;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4d6,extraout_r2_01,extraout_r3_01);
  if (DAT_2100112c == '\0') {
    if (iVar2 != 1) {
      if ((int)((uint)DAT_2100112e << 0x1d) < 0) {
        return (uint)(*(char *)(DAT_21001128 + 199) != '\a');
      }
      return 1;
    }
    if ((&DAT_00001d4b < *(undefined **)(DAT_21001128 + 0x14)) &&
       (*(ushort *)(DAT_21001128 + 0x54) <= *(ushort *)(DAT_21001128 + 0x38))) {
      uVar1 = FUN_01020af0();
      if (uVar1 <= DAT_21001120) {
                    /* WARNING: Could not recover jumptable at 0x0101c5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*(code *)0x101ca33)(DAT_2100111c ^ 1);
        return uVar1;
      }
                    /* WARNING: Could not recover jumptable at 0x0101c5cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*(code *)0x101ca33)(0);
      return uVar1;
    }
  }
  return 0;
}


