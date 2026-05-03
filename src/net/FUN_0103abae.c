/*
 * Function: FUN_0103abae
 * Entry:    0103abae
 * Prototype: undefined __stdcall FUN_0103abae(uint param_1, uint * param_2)
 */


void FUN_0103abae(uint param_1,uint *param_2)

{
  uint local_20 [2];
  byte local_18;
  uint local_14;
  
  local_20[0] = *param_2;
  local_18 = (byte)(short)param_2[2] & 0x1f | (byte)(*(short *)((int)param_2 + 10) << 5);
  local_14 = (local_20[0] & 0xffffffe0) + (param_2[1] - 1) & 0xffffffe0;
  if (7 < param_1) {
    FUN_0102fdfc(param_1);
    return;
  }
  FUN_0102fdc8(param_1,local_20);
  return;
}


