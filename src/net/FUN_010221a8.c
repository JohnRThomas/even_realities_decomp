/*
 * Function: FUN_010221a8
 * Entry:    010221a8
 * Prototype: int __stdcall FUN_010221a8(int param_1, int param_2)
 */


int FUN_010221a8(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 < 3) {
    uVar1 = FUN_01022174(param_1,param_2);
    iVar2 = (int)(char)(&DAT_0103c728)[uVar1];
  }
  else {
    iVar2 = 3;
  }
  return iVar2;
}


