/*
 * Function: FUN_0100a3c4
 * Entry:    0100a3c4
 * Prototype: int __stdcall FUN_0100a3c4(ushort * param_1, byte param_2)
 */


int FUN_0100a3c4(ushort *param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort *puVar4;
  int iVar5;
  uint uVar6;
  
  *param_1 = 0xffff;
  puVar4 = *(ushort **)(&DAT_21000b7c + (uint)param_2 * 4);
  if (puVar4 == (ushort *)0x0) {
    iVar5 = 0;
  }
  else {
    bVar1 = (byte)puVar4[1];
    bVar2 = (byte)puVar4[2] - bVar1 * ((byte)puVar4[2] / bVar1);
    bVar3 = FUN_01027c1e((int)puVar4,-0x10,bVar2);
    if (bVar3 == 0xff) {
      iVar5 = 0;
    }
    else {
      uVar6 = (uint)bVar3 + ((uint)bVar1 - (uint)bVar2);
      *param_1 = ((short)uVar6 - (ushort)bVar1 * (short)(uVar6 / bVar1)) + (ushort)(byte)puVar4[2];
      iVar5 = FUN_01027d1a(puVar4,*param_1,bVar3);
    }
  }
  return iVar5;
}


