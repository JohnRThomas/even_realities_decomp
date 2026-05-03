/*
 * Function: FUN_00025694
 * Entry:    00025694
 * Prototype: undefined __stdcall FUN_00025694(void)
 */


void FUN_00025694(void)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  puVar1 = &DAT_20007f80;
  do {
    iVar2 = 8;
    uVar4 = uVar3;
    do {
      uVar5 = uVar4 & 1;
      uVar4 = uVar4 >> 1;
      if (uVar5 != 0) {
        uVar4 = uVar4 ^ 0xedb88320;
      }
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
    uVar3 = uVar3 + 1;
    *puVar1 = uVar4;
    puVar1 = puVar1 + 1;
  } while (uVar3 != 0x100);
  return;
}


