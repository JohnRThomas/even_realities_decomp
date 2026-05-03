/*
 * Function: FUN_01011734
 * Entry:    01011734
 * Prototype: undefined __stdcall FUN_01011734(int param_1, int param_2, ushort param_3)
 */


void FUN_01011734(int param_1,int param_2,ushort param_3)

{
  byte bVar1;
  int iVar2;
  undefined *puVar3;
  uint uVar4;
  int iVar5;
  
  iVar2 = DAT_21000f20;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(DAT_21000f20 + 0xf);
  *(uint *)(param_2 + 0x20) =
       (uint)*(byte *)(iVar2 + 0x15) << 0x10 | (uint)*(byte *)(iVar2 + 0x14) << 8 |
       (uint)*(byte *)(iVar2 + 0x13);
  puVar3 = (undefined *)FUN_0100de00((uint)*(ushort *)(iVar2 + 0x19));
  iVar2 = DAT_21000f20;
  *(undefined **)(param_2 + 0x14) = puVar3;
  uVar4 = FUN_0100de24((uint)*(byte *)(iVar2 + 0x16),puVar3);
  iVar2 = DAT_21000f20;
  *(short *)(param_2 + 0x28) = (short)uVar4;
  iVar5 = FUN_0100de74((uint)*(ushort *)(iVar2 + 0x17),puVar3);
  iVar2 = DAT_21000f20;
  *(int *)(param_2 + 0x24) = iVar5;
  *(undefined2 *)(param_2 + 0x1c) = *(undefined2 *)(iVar2 + 0x1b);
  *(undefined2 *)(param_2 + 0x1e) = *(undefined2 *)(iVar2 + 0x1d);
  *(undefined4 *)(param_2 + 0xce) = *(undefined4 *)(iVar2 + 0x1f);
  *(undefined1 *)(param_2 + 0xd2) = *(undefined1 *)(iVar2 + 0x23);
  bVar1 = *(byte *)(iVar2 + 0x24);
  *(ushort *)(param_2 + 0x6e) = param_3 & 0xff | param_3 << 8;
  *(byte *)(param_2 + 0xd9) = bVar1 & 0x1f;
  *(byte *)(param_2 + 0x2d8) = bVar1 >> 5;
  *(undefined1 *)(param_2 + 0x70) = 0xff;
  FUN_0100f9a8(param_2 + 0x30,(uint)((param_3 & 0xc) != 0));
  FUN_0100ddc8(param_2,(int)*(char *)(param_1 + 0x10));
  return;
}


