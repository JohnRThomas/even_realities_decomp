/*
 * Function: FUN_0102689e
 * Entry:    0102689e
 * Prototype: undefined __stdcall FUN_0102689e(undefined1 * param_1, undefined4 * param_2)
 */


void FUN_0102689e(undefined1 *param_1,undefined4 *param_2)

{
  char cVar1;
  ushort uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  
  *param_1 = (char)*(undefined2 *)(param_2 + 1);
  bVar3 = param_1[1];
  param_1[1] = bVar3 & 0xf0;
  bVar6 = (byte)(((uint)*(ushort *)(param_2 + 1) << 0x14) >> 0x18);
  bVar5 = bVar6 >> 4;
  param_1[1] = bVar3 & 0xf0 | bVar5;
  param_1[2] = (char)*(undefined2 *)((int)param_2 + 6);
  bVar4 = param_1[3];
  param_1[3] = bVar4 & 0xc0;
  uVar2 = *(ushort *)((int)param_2 + 6);
  param_1[1] = bVar3 & 0xc0 | bVar5;
  bVar5 = (byte)(((uint)uVar2 << 0x12) >> 0x18);
  param_1[3] = bVar4 & 0xc0 | bVar5 >> 2;
  bVar3 = bVar3 & 0x80 | bVar6 >> 4 | (*(byte *)(param_2 + 2) & 3) << 4;
  param_1[1] = bVar3;
  cVar1 = *(char *)((int)param_2 + 9);
  param_1[3] = bVar5 >> 2;
  param_1[1] = (bVar3 | cVar1 << 6) & 0x7f;
  if ((undefined4 *)*param_2 != (undefined4 *)(param_1 + 4)) {
    FUN_01026198((undefined4 *)(param_1 + 4),(undefined4 *)*param_2,
                 (uint)*(ushort *)((int)param_2 + 6));
    return;
  }
  return;
}


