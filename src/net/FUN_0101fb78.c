/*
 * Function: FUN_0101fb78
 * Entry:    0101fb78
 * Prototype: uint __stdcall FUN_0101fb78(undefined2 * param_1)
 */


uint FUN_0101fb78(undefined2 *param_1)

{
  ushort uVar1;
  uint uVar2;
  ushort local_34 [4];
  byte local_2c;
  ushort local_2b;
  undefined1 local_29;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined1 local_21;
  undefined4 local_20;
  ushort local_1c;
  undefined1 local_1a;
  undefined1 local_19;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  uVar2 = (uint)*(byte *)(param_1 + 2);
  if ((uVar2 < 5) && (uVar1 = param_1[1], uVar1 < 0x4001)) {
    local_2c = 0;
    local_17 = 0;
    local_34[0] = (byte)((&DAT_0103c336)[uVar2] | 0x10 | (&DAT_0103c331)[uVar2] << 1 |
                         (&DAT_0103c33b)[uVar2] << 2 | (&DAT_0103c340)[uVar2] << 3) & 0xff1f;
    local_2b = local_34[0];
    local_26 = (undefined1)uVar1;
    local_29 = (undefined1)*param_1;
    local_27 = 0;
    local_24 = 0;
    local_28 = (undefined1)((ushort)*param_1 >> 8);
    local_25 = (undefined1)(uVar1 >> 8);
    local_23 = *(undefined1 *)((int)param_1 + 0xd);
    local_20 = *(undefined4 *)((int)param_1 + 7);
    local_22 = *(undefined1 *)((int)param_1 + 5);
    local_21 = *(undefined1 *)(param_1 + 3);
    local_1c = *(ushort *)((int)param_1 + 0xb);
    local_1a = *(undefined1 *)(param_1 + 7);
    local_19 = 0x7f;
    local_18 = 1;
    local_16 = 1;
    local_15 = 0;
    local_14 = 0;
    local_13 = 0;
    local_12 = 0;
    uVar2 = FUN_0101f964(&local_2c,(byte *)local_34,(uint)local_1c,1);
  }
  else {
    uVar2 = 0x12;
  }
  return uVar2;
}


