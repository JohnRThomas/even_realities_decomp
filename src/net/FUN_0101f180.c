/*
 * Function: FUN_0101f180
 * Entry:    0101f180
 * Prototype: undefined1 __stdcall FUN_0101f180(ushort * param_1, int param_2, undefined4 param_3, int param_4)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_0101f180(ushort *param_1,int param_2,undefined4 param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_r2;
  uint uVar5;
  undefined4 extraout_r3;
  ushort *puStack_20;
  int local_1c;
  undefined4 uStack_18;
  int local_14;
  
  uVar5 = (uint)(byte)param_1[1];
  if (uVar5 < 0x1b) {
    if (uVar5 < 5) {
      return 0x12;
    }
    if ((1 << uVar5 & _FUN_0101f254) == 0) {
      return 0x12;
    }
  }
  else if ((uVar5 != 0x29) && (uVar5 != 0x3b)) {
    return 0x12;
  }
  if (0xeff < *param_1) {
    return 0x12;
  }
  puStack_20 = param_1;
  local_1c = param_2;
  uStack_18 = param_3;
  local_14 = param_4;
  iVar2 = FUN_0100d7c0(*param_1,(undefined1 *)&puStack_20);
  if (iVar2 == 0) {
    if (*(char *)(local_1c + 0x160) == '\0') {
      *(char *)(local_1c + 0x161) = (char)param_1[1];
      *(undefined1 *)(local_1c + 0x160) = 0xff;
      FUN_0100f10c((char *)&puStack_20);
      return 0;
    }
  }
  else {
    iVar2 = FUN_0100a518(*param_1,8);
    if (iVar2 == 0) {
      return 2;
    }
    iVar3 = FUN_0100d7c0(*(ushort *)(iVar2 + 0x17c),(undefined1 *)&uStack_18);
    if (iVar3 == 0) {
      pcVar4 = (char *)FUN_0100a518(*(ushort *)(iVar2 + 0x17e),7);
      if (pcVar4 == (char *)0x0) {
        pcVar4 = (char *)FUN_01009500(0x39,0x8c1,extraout_r2,extraout_r3);
      }
      if ((((*pcVar4 != '\0') || (*(char *)(iVar2 + 0x198) == '\x03')) &&
          (*(char *)(local_14 + 0x1aa) == '\0')) && (*(char *)(iVar2 + 0x1c0) == '\0')) {
        *(undefined2 *)(local_14 + 0x1ac) = *(undefined2 *)(iVar2 + 0x180);
        *(undefined1 *)(local_14 + 0x1ae) = *(undefined1 *)(iVar2 + 0x184);
        *(char *)(local_14 + 0x1af) = pcVar4[0x14];
        uVar1 = param_1[1];
        *(char *)(local_14 + 0x1b0) = (char)uVar1;
        *(char *)(iVar2 + 0x1c0) = (char)uVar1;
        *(undefined1 *)(local_14 + 0x1aa) = 0xff;
        return 0;
      }
    }
  }
  return 0xc;
}


