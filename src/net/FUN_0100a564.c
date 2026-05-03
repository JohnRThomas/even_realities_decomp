/*
 * Function: FUN_0100a564
 * Entry:    0100a564
 * Prototype: undefined4 __stdcall FUN_0100a564(ushort param_1, byte param_2)
 */


undefined4 FUN_0100a564(ushort param_1,byte param_2)

{
  ushort uVar1;
  ushort uVar2;
  byte bVar3;
  int iVar4;
  ushort *puVar5;
  undefined4 uVar6;
  
  puVar5 = *(ushort **)(&DAT_21000b7c + (uint)param_2 * 4);
  bVar3 = FUN_01027c70((int)puVar5,param_1);
  if (bVar3 == 0xff) {
    uVar6 = 3;
  }
  else {
    uVar1 = puVar5[3];
    uVar2 = puVar5[4];
    iVar4 = FUN_01027cea(puVar5,bVar3);
    (*(code *)CONCAT22(uVar1,uVar2))(param_1,iVar4);
    puVar5[bVar3 + 5] = 0xfff0;
    uVar6 = 0;
  }
  return uVar6;
}


