/*
 * Function: FUN_01033928
 * Entry:    01033928
 * Prototype: undefined __stdcall FUN_01033928(void)
 */


void FUN_01033928(void)

{
  int iVar1;
  
  DAT_2100067c = *(int *)(DAT_21000698 + 0x544) + 0x81;
  FUN_01034434();
  iVar1 = FUN_010220c0();
  if (iVar1 == 0) {
    *(undefined4 *)(DAT_21000698 + 0x200) = 0x40004;
  }
  return;
}


