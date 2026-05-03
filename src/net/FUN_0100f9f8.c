/*
 * Function: FUN_0100f9f8
 * Entry:    0100f9f8
 * Prototype: bool __stdcall FUN_0100f9f8(int param_1)
 */


bool FUN_0100f9f8(int param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  ushort uVar8;
  
  uVar6 = *(ushort *)(param_1 + 0x48);
  uVar3 = *(ushort *)(param_1 + 0x50);
  if (*(ushort *)(param_1 + 0x44) <= *(ushort *)(param_1 + 0x50)) {
    uVar3 = *(ushort *)(param_1 + 0x44);
  }
  uVar1 = *(ushort *)(param_1 + 0x3a);
  uVar2 = *(ushort *)(param_1 + 0x3e);
  uVar4 = *(ushort *)(param_1 + 0x52);
  if ((*(byte *)(param_1 + 0x6f) & 0xc) == 0) {
    uVar7 = *(ushort *)(param_1 + 0x40);
    uVar8 = *(ushort *)(param_1 + 0x42);
    uVar5 = uVar6;
    if (uVar4 <= uVar6) {
      uVar6 = uVar4;
      uVar5 = uVar4;
    }
  }
  else {
    uVar7 = *(ushort *)(param_1 + 0x40);
    if (uVar4 <= uVar6) {
      uVar6 = uVar4;
    }
    uVar8 = 0xa90;
    uVar5 = uVar8;
  }
  *(ushort *)(param_1 + 0x3e) = uVar5;
  *(ushort *)(param_1 + 0x3a) = uVar3;
  if (uVar6 < uVar8) {
    uVar6 = uVar8;
  }
  uVar4 = *(ushort *)(param_1 + 0x38);
  if (uVar7 < uVar3) {
    uVar7 = uVar3;
  }
  *(ushort *)(param_1 + 0x40) = uVar7;
  uVar7 = *(ushort *)(param_1 + 0x3c);
  *(ushort *)(param_1 + 0x42) = uVar6;
  uVar6 = *(ushort *)(param_1 + 0x46);
  if (*(ushort *)(param_1 + 0x4c) <= *(ushort *)(param_1 + 0x46)) {
    uVar6 = *(ushort *)(param_1 + 0x4c);
  }
  if ((*(byte *)(param_1 + 0x6e) & 0xc) == 0) {
    uVar8 = *(ushort *)(param_1 + 0x4a);
    if (*(ushort *)(param_1 + 0x4e) <= *(ushort *)(param_1 + 0x4a)) {
      uVar8 = *(ushort *)(param_1 + 0x4e);
    }
  }
  else {
    uVar8 = 0xa90;
  }
  if (*(char *)(param_1 + 100) == '\x02') {
    if (uVar4 <= uVar6) {
      uVar6 = uVar4;
    }
    *(undefined1 *)(param_1 + 100) = 0;
    if (uVar7 <= uVar8) {
      uVar8 = uVar7;
    }
  }
  *(ushort *)(param_1 + 0x38) = uVar6;
  *(ushort *)(param_1 + 0x3c) = uVar8;
  return uVar7 != uVar8 || (uVar4 != uVar6 || (uVar1 != uVar3 || uVar2 != uVar5));
}


