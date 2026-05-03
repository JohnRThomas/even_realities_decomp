/*
 * Function: FUN_01028f8a
 * Entry:    01028f8a
 * Prototype: int __stdcall FUN_01028f8a(ushort * param_1, int param_2)
 */


int FUN_01028f8a(ushort *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int extraout_r3;
  uint uVar6;
  undefined1 local_2c;
  undefined1 local_2b;
  ushort local_2a;
  undefined1 auStack_28 [4];
  int local_24;
  
  iVar2 = FUN_0100d7c0(*param_1,auStack_28);
  if (iVar2 != 0) {
    return iVar2;
  }
  FUN_01028aa6((int)auStack_28);
  iVar3 = FUN_01028aa2((int)auStack_28);
  iVar2 = 0;
  if ((*(char *)(local_24 + 0x1fd) != '\0') && (iVar2 = 0, param_2 != 2)) {
    iVar2 = 1;
  }
  if (*(char *)(extraout_r3 + 0x1e) == '#') {
    iVar5 = 1 - iVar2;
  }
  else {
    iVar5 = 0;
  }
  if (((*(byte *)(extraout_r3 + 0x6f) | *(byte *)(extraout_r3 + 0x6f) >> 3) & 1) == 0 && iVar5 == 0)
  {
    return 0x1a;
  }
  uVar6 = (uint)(byte)param_1[1];
  if (uVar6 == 0) {
    uVar6 = FUN_010200d8();
  }
  uVar4 = (uint)*(byte *)((int)param_1 + 3);
  uVar1 = uVar6;
  if (((uVar4 == 0) && (uVar4 = FUN_010200d8(), uVar1 = uVar4, uVar6 == 0)) || (uVar1 == 0)) {
LAB_01028ff0:
    iVar2 = 9;
  }
  else {
    local_2b = (undefined1)uVar4;
    if (*(char *)(iVar3 + 0x73) != '\0') {
      uVar6 = uVar6 & 2;
      local_2b = (undefined1)(uVar4 & 2);
      if ((uVar6 == 0) || ((uVar4 & 2) == 0)) goto LAB_01028ff0;
    }
    *(undefined1 *)(local_24 + 0x16d) = 0xff;
    if ((iVar2 == 0) && (*(char *)(local_24 + 0x16c) == '\0')) {
      *(undefined1 *)(local_24 + 0x16f) = local_2b;
      *(char *)(local_24 + 0x16c) = (char)param_2;
      local_2c = (undefined1)uVar6;
      *(undefined1 *)(local_24 + 0x16e) = local_2c;
      local_2a = param_1[2];
      *(ushort *)(local_24 + 0x170) = local_2a;
      FUN_0100dd84(iVar3,(undefined4 *)&local_2c);
      iVar2 = 0;
    }
    else {
      iVar2 = 0x3a;
    }
    *(undefined1 *)(local_24 + 0x16d) = 0;
  }
  return iVar2;
}


