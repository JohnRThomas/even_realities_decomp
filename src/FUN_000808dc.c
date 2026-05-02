/*
 * Function: FUN_000808dc
 * Entry:    000808dc
 * Prototype: undefined __stdcall FUN_000808dc(void)
 */


void FUN_000808dc(void)

{
  ushort uVar1;
  ushort uVar2;
  char *pcVar3;
  int iVar4;
  int iVar5;
  
  pcVar3 = get_string(0x49);
  iVar4 = FUN_000809e2();
  uVar1 = FUN_00080a3a();
  iVar5 = FUN_000809e2();
  uVar2 = FUN_00080a3a();
  gui_utf_draw_middle(0,pcVar3,0,iVar4,uVar1 + 0x37,iVar5 + 0x240,uVar2 + 0x88,1,0,0,
                      (undefined *)0x0,0);
  return;
}


