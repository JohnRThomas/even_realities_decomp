/*
 * Function: FUN_0101a6f8
 * Entry:    0101a6f8
 * Prototype: bool __stdcall FUN_0101a6f8(uint param_1, uint param_2)
 */


bool FUN_0101a6f8(uint param_1,uint param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_16;
  int local_14 [2];
  
  puVar1 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar1,local_14,&uStack_16);
  iVar2 = FUN_010278d2(local_14[0]);
  if (*(byte *)(iVar2 + 0x20) != param_1) {
    return false;
  }
  return *(ushort *)(iVar2 + 0x21) == param_2;
}


