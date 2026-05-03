/*
 * Function: FUN_0102a87e
 * Entry:    0102a87e
 * Prototype: undefined __stdcall FUN_0102a87e(void)
 */


void FUN_0102a87e(void)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  bVar1 = FUN_010222b4();
  for (uVar3 = 0; (uVar3 & 0xff) < (uint)bVar1; uVar3 = uVar3 + 1) {
    iVar2 = FUN_010222c0(uVar3 & 0xff);
    *(undefined2 *)(iVar2 + 0x24) = 0;
    *(undefined1 *)(iVar2 + 0x26) = 0;
  }
  return;
}


