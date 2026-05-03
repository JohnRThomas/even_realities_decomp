/*
 * Function: FUN_0100a468
 * Entry:    0100a468
 * Prototype: int __stdcall FUN_0100a468(ushort param_1, byte param_2)
 */


int FUN_0100a468(ushort param_1,byte param_2)

{
  byte bVar1;
  byte bVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar3 = *(ushort **)(&DAT_21000b7c + (uint)param_2 * 4);
  if (puVar3 == (ushort *)0x0) {
    iVar4 = 0;
  }
  else {
    if (0xeff < param_1) {
      FUN_01009500(0x17,0x27e,&DAT_21000b7c,(uint)param_1);
    }
    bVar1 = FUN_01027c70((int)puVar3,param_1);
    if (bVar1 == 0xff) {
      bVar1 = (char)param_1 - (char)(param_1 / (byte)puVar3[1]) * (byte)puVar3[1];
      bVar2 = FUN_01027c1e((int)puVar3,-0x10,bVar1);
      if (bVar2 == 0xff) {
        iVar4 = 0;
      }
      else {
        if (bVar2 != bVar1) {
          *(undefined1 *)((int)puVar3 + 3) = 0;
        }
        iVar4 = FUN_01027d1a(puVar3,param_1,bVar2);
      }
    }
    else {
      iVar4 = FUN_01027cea(puVar3,bVar1);
    }
  }
  return iVar4;
}


