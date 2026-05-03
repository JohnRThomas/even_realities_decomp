/*
 * Function: FUN_01033020
 * Entry:    01033020
 * Prototype: undefined __stdcall FUN_01033020(int param_1)
 */


void FUN_01033020(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x40000;
  }
  else {
    uVar2 = 0x40004;
  }
  iVar1 = FUN_010220c0();
  if (iVar1 == 0) {
    FUN_01034434();
  }
  else {
    *(undefined4 *)(DAT_21000698 + 0x548) = 0x81;
  }
  *(undefined4 *)(DAT_21000698 + 0x200) = uVar2;
  return;
}


