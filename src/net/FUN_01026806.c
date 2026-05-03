/*
 * Function: FUN_01026806
 * Entry:    01026806
 * Prototype: undefined __stdcall FUN_01026806(undefined4 * param_1, ushort * param_2)
 */


void FUN_01026806(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  
  *(ushort *)(param_1 + 1) = (ushort)(((uint)*param_2 << 0x14) >> 0x14);
  uVar1 = param_2[1];
  *(undefined1 *)((int)param_1 + 9) = 0;
  *(ushort *)((int)param_1 + 6) = uVar1;
  uVar3 = (uint)*(byte *)((int)param_2 + 1) << 0x1a;
  uVar4 = uVar3 >> 0x1e;
  bVar2 = (byte)(uVar3 >> 0x1e);
  if ((uVar4 != 1) && (uVar4 != 2)) {
    bVar2 = 0;
  }
  *(byte *)(param_1 + 2) = bVar2;
  *param_1 = param_2 + 2;
  return;
}


