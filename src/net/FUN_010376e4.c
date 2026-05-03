/*
 * Function: FUN_010376e4
 * Entry:    010376e4
 * Prototype: undefined __stdcall FUN_010376e4(undefined * param_1)
 */


void FUN_010376e4(undefined *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)DAT_21004b38;
  FUN_01038898((int *)(&DAT_210044d8 + uVar2 * 0x18));
  (&DAT_21006462)[uVar2] = 0;
  iVar1 = FUN_01037650(param_1);
  if (iVar1 != 0) {
    FUN_0103874c((undefined4 *)(&DAT_210044d8 + uVar2 * 0x18),&LAB_0103768c_1,DAT_21004b64 - 1U,
                 (int)(DAT_21004b64 - 1U) >> 0x1f);
    return;
  }
  return;
}


