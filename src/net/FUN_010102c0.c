/*
 * Function: FUN_010102c0
 * Entry:    010102c0
 * Prototype: undefined __stdcall FUN_010102c0(byte * param_1)
 */


void FUN_010102c0(byte *param_1)

{
  uint uVar1;
  undefined2 *puVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100dbc0(iVar3 + 0xa8,0,(uint)*(byte *)(iVar3 + 0xc5),(uint)*param_1);
  if (uVar1 != 0) {
    *(undefined1 *)(iVar3 + 0xc5) = 0x1e;
    return;
  }
  iVar3 = FUN_01009500(0x45,0x24,extraout_r2,extraout_r3);
  puVar2 = *(undefined2 **)(iVar3 + 4);
  if (*(char *)(puVar2 + 0x32) == '\x01') {
    *(undefined1 *)(puVar2 + 0x32) = 2;
    return;
  }
  FUN_0100fb00(*puVar2,(int)(puVar2 + 0x18),(undefined4 *)(puVar2 + 0xe7));
  return;
}


