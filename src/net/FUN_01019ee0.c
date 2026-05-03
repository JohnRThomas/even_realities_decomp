/*
 * Function: FUN_01019ee0
 * Entry:    01019ee0
 * Prototype: undefined __stdcall FUN_01019ee0(void)
 */


void FUN_01019ee0(void)

{
  undefined4 *puVar1;
  char cVar2;
  ushort *puVar3;
  int iVar4;
  ushort uStack_1e;
  int local_1c [2];
  
  puVar3 = (ushort *)FUN_0100ada0();
  FUN_0102794a(puVar3,local_1c,&uStack_1e);
  iVar4 = FUN_010278d2(local_1c[0]);
  cVar2 = DAT_2100109e;
  puVar1 = DAT_21001098;
  if (*(char *)(iVar4 + 0x1f) != '\0') {
    if (DAT_21001098 != (undefined4 *)0x0) {
      *(byte *)(DAT_21001098 + 7) = *(byte *)(DAT_21001098 + 7) & 0x9f | 0x40;
      *(undefined1 *)(puVar1 + 2) = 0;
      FUN_0100f788(puVar1,0x1019a9d,6);
      if (cVar2 != '\0') {
        *(undefined1 *)((int)puVar1 + 0x11) = 0;
        FUN_0100f788((undefined4 *)((int)puVar1 + 9),0x1019a9d,6);
      }
      DAT_21001098 = (undefined4 *)0x0;
      DAT_2100109e = '\0';
    }
    FUN_01019e60();
    return;
  }
  return;
}


