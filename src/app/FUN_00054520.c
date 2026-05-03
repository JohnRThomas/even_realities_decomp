/*
 * Function: FUN_00054520
 * Entry:    00054520
 * Prototype: undefined __stdcall FUN_00054520(void)
 */


void FUN_00054520(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 5;
  iVar3 = 0x200058c0;
  do {
    piVar2 = (int *)(iVar3 + 0xd8);
    iVar1 = iVar1 + -1;
    *(undefined **)(iVar3 + 0xd8) = &DAT_20002890;
    *(int **)(iVar3 + 0xdc) = DAT_20002894;
    *DAT_20002894 = (int)piVar2;
    iVar3 = iVar3 + 0xf8;
    DAT_20002894 = piVar2;
  } while (iVar1 != 0);
  return;
}


