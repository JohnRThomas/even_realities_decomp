/*
 * Function: FUN_01022238
 * Entry:    01022238
 * Prototype: undefined4 __stdcall FUN_01022238(int param_1, byte * param_2)
 */


undefined4 FUN_01022238(int param_1,byte *param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  byte bVar6;
  
  if (param_1 == 0) {
    uVar4 = 0xffffffea;
  }
  else {
    bVar2 = FUN_010222b4();
    bVar1 = 0;
    do {
      bVar6 = bVar1;
      uVar5 = (uint)bVar6;
      if (bVar2 <= uVar5) goto LAB_0102226a;
      iVar3 = FUN_010222c0(uVar5);
      bVar1 = bVar6 + 1;
    } while (*(char *)(iVar3 + 0x26) != '\0');
    if (uVar5 == 0xff) {
LAB_0102226a:
      uVar4 = 0xfffffff4;
    }
    else {
      iVar3 = FUN_010222c0(uVar5);
      *(undefined2 *)(iVar3 + 0x24) = 0;
      *(undefined1 *)(iVar3 + 0x26) = 0;
      *(byte *)(iVar3 + 0x28) = bVar6;
      uVar5 = FUN_01023634(0x102a665,iVar3);
      *(char *)(iVar3 + 0x27) = (char)uVar5;
      if (uVar5 == 0x20) {
        uVar4 = 0xffffffdd;
      }
      else {
        *(int *)(iVar3 + 0x20) = param_1;
        *(undefined1 *)(iVar3 + 0x26) = 1;
        *param_2 = bVar6;
        uVar4 = 0;
      }
    }
  }
  return uVar4;
}


