/*
 * Function: FUN_0101f8a0
 * Entry:    0101f8a0
 * Prototype: uint __stdcall FUN_0101f8a0(ushort * param_1)
 */


uint FUN_0101f8a0(ushort *param_1)

{
  uint uVar1;
  byte local_58;
  undefined1 local_57;
  byte local_56;
  undefined4 local_55;
  ushort local_51;
  undefined1 local_4f;
  int local_4c;
  int local_40;
  undefined2 local_34;
  undefined2 local_2e;
  undefined2 local_28;
  undefined2 local_22;
  undefined2 local_1c;
  undefined2 local_16;
  undefined1 local_10;
  undefined2 local_e;
  undefined2 local_c;
  
  if (*(byte *)((int)param_1 + 5) < 4) {
    local_56 = *(byte *)((int)param_1 + 5) & 0xfd;
    local_58 = (byte)param_1[2];
    local_55 = *(undefined4 *)(param_1 + 3);
    local_51 = param_1[5];
    local_57 = (undefined1)param_1[6];
    local_4f = 1;
    local_4c = (uint)*param_1 * 0x271;
    local_40 = (uint)param_1[1] * 0x271;
    local_34 = *(undefined2 *)((int)param_1 + 0xd);
    local_2e = *(undefined2 *)((int)param_1 + 0xf);
    local_28 = *(undefined2 *)((int)param_1 + 0x11);
    local_22 = *(undefined2 *)((int)param_1 + 0x13);
    local_1c = *(undefined2 *)((int)param_1 + 0x15);
    local_16 = *(undefined2 *)((int)param_1 + 0x17);
    local_10 = 0;
    local_e = 0;
    local_c = 7;
    if ((local_40 - 0x9c4U < 0x9c363d) && (local_4c - 0x9c4U < 0x9c363d)) {
      uVar1 = FUN_0101f568(&local_58);
    }
    else {
      uVar1 = 0x30;
    }
  }
  else {
    uVar1 = 0x12;
  }
  return uVar1;
}


