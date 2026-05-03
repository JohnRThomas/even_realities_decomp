/*
 * Function: FUN_0101ca38
 * Entry:    0101ca38
 * Prototype: uint __stdcall FUN_0101ca38(int param_1, undefined4 param_2, int param_3, int param_4)
 */


uint FUN_0101ca38(int param_1,undefined4 param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  code *UNRECOVERED_JUMPTABLE_00;
  
  if (param_4 == 0) {
    if (param_1 != 1) {
      if ((int)((uint)*(ushort *)(param_3 + 10) << 0x1d) < 0) {
        return (uint)(*(char *)(*(int *)(param_3 + 4) + 199) != '\a');
      }
      return 1;
    }
    iVar2 = *(int *)(param_3 + 4);
    if ((&DAT_00001d4b < *(undefined **)(iVar2 + 0x14)) &&
       (*(ushort *)(iVar2 + 0x54) <= *(ushort *)(iVar2 + 0x38))) {
      uVar1 = FUN_01020af0();
      if (uVar1 <= DAT_21001120) {
                    /* WARNING: Could not recover jumptable at 0x0101c5c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar1 = (*UNRECOVERED_JUMPTABLE_00)(DAT_2100111c ^ 1);
        return uVar1;
      }
                    /* WARNING: Could not recover jumptable at 0x0101c5cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar1 = (*UNRECOVERED_JUMPTABLE_00)(0);
      return uVar1;
    }
  }
  return 0;
}


