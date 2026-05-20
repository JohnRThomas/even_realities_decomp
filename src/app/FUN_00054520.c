/*
 * Function: FUN_00054520
 * Entry:    00054520
 * Prototype: undefined __stdcall FUN_00054520(void)
 */


void FUN_00054520(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  
  iVar1 = 5;
  puVar3 = &DAT_200058c0;
  do {
    puVar2 = (undefined4 *)(puVar3 + 0xd8);
    iVar1 = iVar1 + -1;
    *(undefined **)(puVar3 + 0xd8) = &DAT_20002890;
    *(undefined4 **)(puVar3 + 0xdc) = DAT_20002894;
    *DAT_20002894 = puVar2;
    puVar3 = puVar3 + 0xf8;
    DAT_20002894 = puVar2;
  } while (iVar1 != 0);
  return;
}


