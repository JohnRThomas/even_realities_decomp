/*
 * Function: FUN_01012b3c
 * Entry:    01012b3c
 * Prototype: undefined4 __stdcall FUN_01012b3c(int param_1)
 */


undefined4 FUN_01012b3c(int param_1)

{
  byte bVar1;
  char cVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  
  bVar1 = *(byte *)(param_1 + 0x12);
  uVar4 = bVar1 - 2 & 0xff;
  if (uVar4 < 2) {
    uVar6 = FUN_0100cf44((uint)*(byte *)(param_1 + 0x67),(byte *)(param_1 + 0x68));
    uVar5 = (undefined1)uVar6;
    if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1a) < 0) goto LAB_01012b7c;
    if (uVar6 == 8) goto LAB_01012b68;
    cVar2 = FUN_0100c404(uVar6);
    if (cVar2 == '\0') goto LAB_01012b7c;
  }
  else {
    if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1a) < 0) {
      uVar5 = 8;
      goto LAB_01012b7c;
    }
LAB_01012b68:
    uVar6 = 8;
  }
  uVar5 = (undefined1)uVar6;
  if ((bVar1 & 0xfd) == 0) {
    cVar2 = FUN_0100b204(bVar1 & 0xfd,(undefined4 *)(param_1 + 0x61));
    if (cVar2 != '\0') goto LAB_01012b7c;
  }
  else if (*(char *)(param_1 + 0x19) != '\0') {
    *(undefined4 *)(param_1 + 0x61) = *(undefined4 *)(param_1 + 0x13);
    *(undefined2 *)(param_1 + 0x65) = *(undefined2 *)(param_1 + 0x17);
LAB_01012b7c:
    *(undefined1 *)(param_1 + 0x1b) = uVar5;
    *(bool *)(param_1 + 0x1a) = uVar4 < 2;
    *(bool *)(param_1 + 0x60) = (bVar1 & 0xfd) != 0;
    uVar3 = FUN_0100cf38();
    uVar4 = (uint)uVar3;
    lVar8 = FUN_01025834();
    *(undefined1 *)(param_1 + 0x6e) = 0;
    iVar7 = (uint)(uVar4 * 0x20 < uVar4) * -0x200 + (uint)CARRY4(uVar4 * 0x3e00,uVar4);
    *(longlong *)(param_1 + 0x58) =
         lVar8 + CONCAT44((((iVar7 * 0x40 | uVar4 * 0x3e01 >> 0x1a) - iVar7) -
                          (uint)(uVar4 * 0xf8040 < uVar4 * 0x3e01)) +
                          (uint)CARRY4(uVar4 * 999999,uVar4),uVar4 * 1000000);
    FUN_01011a4c(param_1,0);
    return 1;
  }
  return 0;
}


