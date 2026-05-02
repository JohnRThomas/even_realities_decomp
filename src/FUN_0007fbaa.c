/*
 * Function: FUN_0007fbaa
 * Entry:    0007fbaa
 * Prototype: undefined __stdcall FUN_0007fbaa(int param_1)
 */


void FUN_0007fbaa(int param_1)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = FUN_00027580();
  if (iVar1 == 1) {
    uVar2 = 4;
  }
  else if (iVar1 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = 2;
  }
  *(undefined1 *)(param_1 + 2) = uVar2;
  return;
}


