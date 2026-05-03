/*
 * Function: FUN_01024ccc
 * Entry:    01024ccc
 * Prototype: undefined __stdcall FUN_01024ccc(uint param_1, int * param_2, char * param_3)
 */


void FUN_01024ccc(uint param_1,int *param_2,char *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = (param_1 >> 0xd) * 0x8637 >> 0x10;
  uVar1 = param_1 + uVar4 * -0x3d09;
  uVar2 = uVar1 * 0x10c6f >> 0x15;
  iVar5 = uVar2 * 0x3d09;
  iVar3 = uVar2 + uVar4 * 0x200;
  if (uVar1 <= (uint)(&DAT_00003d08 + iVar5) >> 9) {
    *param_2 = iVar3;
    *param_3 = (char)uVar1 - (char)(iVar5 + 0x100U >> 9);
    return;
  }
  *param_2 = iVar3 + 1;
  *param_3 = '\0';
  return;
}


