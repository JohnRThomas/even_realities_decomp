/*
 * Function: FUN_00080928
 * Entry:    00080928
 * Prototype: undefined __stdcall FUN_00080928(void)
 */


void FUN_00080928(void)

{
  ushort uVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = get_string(0x47);
  iVar4 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw(0,pcVar3,0,iVar4 + 0x24,uVar1 + 0x37,iVar5 + 0x21c,uVar2 + 0x6d,2,0,0,
               (undefined *)0x0,0);
  return;
}


