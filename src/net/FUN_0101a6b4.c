/*
 * Function: FUN_0101a6b4
 * Entry:    0101a6b4
 * Prototype: uint __stdcall FUN_0101a6b4(ushort * param_1, int param_2)
 */


uint FUN_0101a6b4(ushort *param_1,int param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_16;
  int local_14 [2];
  
  puVar1 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar1,local_14,&uStack_16);
  iVar2 = FUN_010278d2(local_14[0]);
  if (param_2 == 0) {
    return (uint)((*param_1 & 0x10ff) == 0);
  }
  if (param_2 != 3) {
    return 0;
  }
  return ((uint)*(byte *)(iVar2 + 0x1c) << 0x1c) >> 0x1f;
}


