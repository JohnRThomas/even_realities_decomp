/*
 * Function: opt3001_channel_get
 * Entry:    00087f5a
 * Prototype: undefined4 __stdcall opt3001_channel_get(int param_1, int param_2, uint * param_3)
 */


/* exclude_from_export_ai */

undefined4 opt3001_channel_get(int param_1,int param_2,uint *param_3)

{
  uint uVar1;
  
  if (param_2 == 0x11) {
    uVar1 = (**(ushort **)(param_1 + 0x10) & 0xfff) << (uint)(**(ushort **)(param_1 + 0x10) >> 0xc);
    *param_3 = uVar1 / 100;
    param_3[1] = (uVar1 % 100) * 10000;
    return 0;
  }
  return 0xffffff7a;
}


