/*
 * Function: FUN_0102f2cc
 * Entry:    0102f2cc
 * Prototype: undefined __stdcall FUN_0102f2cc(void)
 */


void FUN_0102f2cc(void)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1f;
  }
  uVar2 = uVar2 - 0x10;
  if (uVar2 < 0x1e) {
                    /* WARNING: Could not emulate address calculation at 0x0102f2dc */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(&DAT_21000770 + uVar2 * 8))(*(undefined4 *)(&DAT_2100076c + uVar2 * 8));
    return;
  }
  return;
}


