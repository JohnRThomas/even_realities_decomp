/*
 * Function: FUN_01019d60
 * Entry:    01019d60
 * Prototype: bool __stdcall FUN_01019d60(void)
 */


bool FUN_01019d60(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_e;
  int local_c [2];
  
  puVar1 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar1,local_c,&uStack_e);
  iVar2 = FUN_010278d2(local_c[0]);
  return *(char *)(iVar2 + 0x25) != -1;
}


