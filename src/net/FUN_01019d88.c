/*
 * Function: FUN_01019d88
 * Entry:    01019d88
 * Prototype: undefined __stdcall FUN_01019d88(void)
 */


void FUN_01019d88(void)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_e;
  int local_c [2];
  
  puVar1 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar1,local_c,&uStack_e);
  iVar2 = FUN_010278d2(local_c[0]);
  *(undefined4 *)(iVar2 + 0x1a) = 0;
  *(undefined4 *)(iVar2 + 0x12) = 0;
  *(undefined4 *)(iVar2 + 0x1e) = 0;
  *(undefined4 *)(iVar2 + 0x22) = 0;
  *(undefined1 *)(iVar2 + 0x20) = 0xff;
  *(undefined1 *)(iVar2 + 0x13) = 0xff;
  *(undefined1 *)(iVar2 + 0x25) = 0xff;
  *(undefined4 *)(iVar2 + 0x2a) = 0;
  *(undefined4 *)(iVar2 + 0x16) = 0;
  *(undefined1 *)(iVar2 + 0x2c) = 0x7f;
  *(undefined4 *)(iVar2 + 0x26) = 0;
  DAT_21001098 = 0;
  DAT_2100109c = 0;
  DAT_21001058 = 0;
  DAT_2100109e = 0;
  *(byte *)(iVar2 + 0x1c) = *(byte *)(iVar2 + 0x1c) & 0x9f | 0x20;
  return;
}


