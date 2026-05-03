/*
 * Function: FUN_0100a518
 * Entry:    0100a518
 * Prototype: int __stdcall FUN_0100a518(ushort param_1, byte param_2)
 */


int FUN_0100a518(ushort param_1,byte param_2)

{
  byte bVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = *(ushort **)(&DAT_21000b7c + (uint)param_2 * 4);
  bVar1 = FUN_01027c70((int)puVar2,param_1);
  if (bVar1 == 0xff) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_01027cea(puVar2,bVar1);
  }
  return iVar3;
}


