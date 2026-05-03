/*
 * Function: FUN_010275ae
 * Entry:    010275ae
 * Prototype: bool __stdcall FUN_010275ae(short * param_1)
 */


bool FUN_010275ae(short *param_1)

{
  bool bVar1;
  ushort local_1e;
  ushort *local_1c;
  ushort local_16;
  ushort local_14;
  short local_12;
  short *local_10;
  short *local_c;
  
  local_10 = param_1 + 0xc;
  local_12 = param_1[3];
  local_14 = param_1[2];
  local_16 = (ushort)(((uint)local_14 << 0x11) >> 0x11);
  local_1c = (ushort *)((uint)local_16 + (int)local_10);
  local_c = param_1;
  bVar1 = FUN_01027112(local_14,local_12);
  if (bVar1) {
    bVar1 = false;
  }
  else if ((uint)(ushort)local_c[7] + (uint)(ushort)local_c[5] < (uint)*local_1c) {
    bVar1 = true;
  }
  else {
    local_1e = local_14;
    FUN_01009d1c(local_c,&local_1e);
    bVar1 = FUN_01027112(local_1e,local_12);
    bVar1 = !bVar1;
  }
  return bVar1;
}


