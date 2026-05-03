/*
 * Function: FUN_0100dbc0
 * Entry:    0100dbc0
 * Prototype: uint __stdcall FUN_0100dbc0(int param_1, undefined4 param_2, uint param_3, int param_4)
 */


uint FUN_0100dbc0(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  
  switch(param_2) {
  case 0:
    return (uint)(param_3 == 0);
  case 1:
    return (uint)(param_3 - 7 < 2);
  case 2:
    return (uint)(param_3 - 0xb < 3);
  case 3:
    return (uint)(param_3 - 0xe < 2);
  case 4:
    return (uint)(param_3 - 0x11 < 0xd);
  case 5:
    if (param_4 != 0) {
      return (uint)(param_3 - 0x12 < 0xc);
    }
    if (1 < param_3 - 0x13) {
      if (*(char *)(param_1 + 0x5e) == '\0') {
        return (uint)(param_3 - 0x18 < 5);
      }
      return (uint)(param_3 - 0x14 < 9);
    }
    break;
  case 6:
    if (3 < param_3 - 0x11) {
      if (param_3 < 0x1e) {
        uVar1 = *(byte *)(param_1 + 0x5e) & 1;
      }
      else {
        uVar1 = 0;
      }
      return uVar1;
    }
    break;
  case 7:
    return (uint)(param_3 == 4);
  case 8:
    return (uint)(param_3 == 1);
  case 9:
    if (param_4 != 0) {
      return (uint)(param_3 == 0x10);
    }
    return (uint)(param_3 == 5);
  case 10:
    return (uint)(param_3 - 0x1e < 3);
  case 0xb:
    uVar1 = param_3 - 0x21;
    bVar4 = 0x2e < param_3;
    bVar2 = param_3 == 0x2f;
    if (!bVar2) {
      bVar4 = 5 < uVar1;
    }
    bVar3 = uVar1 == 6;
    if (!bVar4 || (bVar2 || bVar3)) {
      uVar1 = 1;
    }
    if (bVar4 && (!bVar2 && !bVar3)) {
      uVar1 = 0;
    }
    return uVar1;
  case 0xc:
    return (uint)(param_3 == 0x29);
  case 0xd:
    return (uint)(param_3 - 0x2a < 5);
  default:
    return 0;
  }
  return 1;
}


