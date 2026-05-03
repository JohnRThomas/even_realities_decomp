/*
 * Function: FUN_0101c9dc
 * Entry:    0101c9dc
 * Prototype: uint __stdcall FUN_0101c9dc(int param_1)
 */


uint FUN_0101c9dc(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  
  uVar1 = FUN_0100dbc0(*(int *)(param_1 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(param_1 + 4) + 0xc5),
                       0);
  if (uVar1 != 0) {
    *(undefined1 *)(*(int *)(param_1 + 4) + 0xc5) = 0xe;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4dc,extraout_r2,extraout_r3);
  uVar1 = FUN_0100dbc0(*(int *)(iVar2 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(iVar2 + 4) + 0xc5),0);
  if (uVar1 != 0) {
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0xc5) = 0xc;
    return uVar1;
  }
  iVar2 = FUN_01009500(0x36,0x4d6,extraout_r2_00,extraout_r3_00);
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


