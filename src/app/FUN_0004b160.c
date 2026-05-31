/*
 * Function: FUN_0004b160
 * Entry:    0004b160
 * Prototype: undefined * __stdcall FUN_0004b160(char * param_1, undefined2 * param_2)
 */


undefined * FUN_0004b160(char *param_1,undefined2 *param_2)

{
  size_t sVar1;
  int iVar2;
  
  memset(&DAT_200100f2,0,0x800);
  sVar1 = strlen(param_1);
  iVar2 = FUN_0004b0cc((int)param_1,sVar1,0x200100f2,0x400);
  *param_2 = (short)iVar2;
  return &DAT_200100f2;
}


