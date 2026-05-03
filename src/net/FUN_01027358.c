/*
 * Function: FUN_01027358
 * Entry:    01027358
 * Prototype: int __stdcall FUN_01027358(int param_1, ushort * param_2, undefined4 param_3)
 */


int FUN_01027358(int param_1,ushort *param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  
  uVar1 = (ushort)(((uint)*(ushort *)(param_1 + 4) << 0x11) >> 0x11);
  bVar3 = FUN_01027112(*(ushort *)(param_1 + 4),*(short *)(param_1 + 6));
  if (bVar3) {
    *(undefined2 *)(param_1 + 0xe) = 0;
    iVar4 = 0;
  }
  else {
    uVar2 = *(short *)((uint)uVar1 + param_1 + 0x18) - *(short *)(param_1 + 10);
    iVar4 = (uint)uVar1 + (uint)*(byte *)(param_1 + 0x13) + (uint)*(ushort *)(param_1 + 10) + 2 +
            param_1 + 0x18;
    if (uVar2 < *param_2) {
      *param_2 = uVar2;
    }
    *(bool *)param_3 = *(short *)(param_1 + 10) == 0;
    *(ushort *)(param_1 + 0xe) = *param_2;
  }
  return iVar4;
}


