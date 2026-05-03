/*
 * Function: FUN_0102dea0
 * Entry:    0102dea0
 * Prototype: bool __stdcall FUN_0102dea0(int param_1, int * param_2, byte * param_3)
 */


bool FUN_0102dea0(int param_1,int *param_2,byte *param_3)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = FUN_0103a70c(param_1,param_3);
  bVar1 = iVar2 != 0;
  if (!bVar1) {
    iVar2 = FUN_0103a70c(param_1,(byte *)0x103ce8c);
  }
  *param_2 = iVar2;
  return bVar1;
}


