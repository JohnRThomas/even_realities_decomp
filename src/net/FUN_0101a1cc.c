/*
 * Function: FUN_0101a1cc
 * Entry:    0101a1cc
 * Prototype: bool __stdcall FUN_0101a1cc(void)
 */


bool FUN_0101a1cc(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_e;
  int local_c [2];
  
  puVar1 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar1,local_c,&uStack_e);
  iVar2 = FUN_010278d2(local_c[0]);
  return *(char *)(iVar2 + 0x13) != -1;
}


