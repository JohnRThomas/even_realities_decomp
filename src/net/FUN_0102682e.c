/*
 * Function: FUN_0102682e
 * Entry:    0102682e
 * Prototype: char __stdcall FUN_0102682e(undefined1 * param_1, undefined4 * param_2)
 */


char FUN_0102682e(undefined1 *param_1,undefined4 *param_2)

{
  undefined2 uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  uint uVar5;
  byte bVar6;
  
  *param_1 = (char)*(undefined2 *)(param_2 + 1);
  bVar2 = param_1[1];
  bVar6 = bVar2 & 0xf0;
  param_1[1] = bVar6;
  bVar4 = (byte)(((uint)*(ushort *)(param_2 + 1) << 0x14) >> 0x18);
  bVar3 = bVar4 >> 4;
  param_1[1] = bVar6 | bVar3;
  param_1[2] = (char)*(undefined2 *)((int)param_2 + 6);
  uVar1 = *(undefined2 *)((int)param_2 + 6);
  param_1[1] = bVar2 & 0xc0 | bVar3;
  param_1[3] = (char)((ushort)uVar1 >> 8);
  bVar2 = bVar4 >> 4 | (*(byte *)(param_2 + 2) & 3) << 4;
  param_1[1] = bVar2;
  param_1[1] = bVar2 | *(char *)((int)param_2 + 9) << 6;
  if ((undefined4 *)*param_2 != (undefined4 *)(param_1 + 4)) {
    uVar5 = (uint)*(ushort *)((int)param_2 + 6);
    if (0xfa < uVar5) {
      uVar5 = 0xfb;
    }
    FUN_01026198((undefined4 *)(param_1 + 4),(undefined4 *)*param_2,uVar5);
  }
  return (char)*(undefined2 *)((int)param_2 + 6) + '\x04';
}


