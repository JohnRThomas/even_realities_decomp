/*
 * Function: FUN_0100d94c
 * Entry:    0100d94c
 * Prototype: undefined __stdcall FUN_0100d94c(undefined4 * param_1, int param_2)
 */


void FUN_0100d94c(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    FUN_01026284(param_1,0,0x360);
    *(undefined1 *)((int)param_1 + 0x117) = 0x49;
    *(undefined1 *)((int)param_1 + 0xcd) = 1;
    *(undefined1 *)((int)param_1 + 0x119) = 0xc4;
    *(undefined1 *)(param_1 + 0x46) = 4;
    *(undefined1 *)((int)param_1 + 0x11a) = 7;
    *(undefined1 *)((int)param_1 + 0x14e) = 0xfe;
    *(undefined1 *)((int)param_1 + 0x11b) = 0;
    *(undefined1 *)(param_1 + 0x47) = 0;
    *(undefined1 *)((int)param_1 + 0x11d) = 0;
    *(undefined1 *)((int)param_1 + 0x116) = 0x2b;
    *(undefined1 *)((int)param_1 + 0xc1) = 0x7f;
    param_1[0x2c] = &DAT_fffce000;
    *(undefined1 *)((int)param_1 + 0x301) = 0x20;
    return;
  }
  if (param_2 == 1) {
    uVar1 = param_1[5];
    param_1[0x3b] = (uVar1 + 29999999) / uVar1;
    *(short *)((int)param_1 + 0xfa) = (short)((uVar1 * *(ushort *)((int)param_1 + 0xfa)) / uVar1);
    *(undefined2 *)(param_1 + 0x3c) = 3000;
    *(short *)(param_1 + 0x3e) =
         (short)(((uint)*(ushort *)((int)param_1 + 0x1e) * 10000 + (uVar1 - 1)) / uVar1);
    param_1[0x3a] = (uVar1 * param_1[0x3a]) / uVar1;
    *(short *)((int)param_1 + 0xfe) = (short)(40000000 / uVar1) + 1;
    *(undefined2 *)((int)param_1 + 0xf6) = 0;
    FUN_0100e040((int)param_1 + 0xcd,(byte *)((int)param_1 + 0xce));
    return;
  }
  if (param_2 == 2) {
    uVar1 = param_1[0xca];
    *(undefined2 *)((int)param_1 + 0xf6) = 0;
    *(short *)((int)param_1 + 0xfa) =
         (short)((param_1[5] * (uint)*(ushort *)((int)param_1 + 0xfa)) / uVar1);
    *(short *)(param_1 + 0x3e) =
         (short)(((uint)*(ushort *)((int)param_1 + 0x32e) * 10000 + (uVar1 - 1)) / uVar1);
    param_1[0x3a] = (uint)(param_1[0x3a] * param_1[5]) / uVar1;
    *(short *)((int)param_1 + 0xfe) = (short)(40000000 / uVar1) + 1;
    param_1[0x3b] = ((uint)*(ushort *)(param_1 + 0x3c) * 10000 + (uVar1 - 1)) / uVar1;
    return;
  }
  if (param_2 != 3) {
    return;
  }
  FUN_0100e040((int)param_1 + 0xcd,(byte *)((int)param_1 + 0xce));
  return;
}


