/*
 * Function: FUN_01029ef8
 * Entry:    01029ef8
 * Prototype: undefined __stdcall FUN_01029ef8(byte * param_1)
 */


void FUN_01029ef8(byte *param_1)

{
  uint uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = FUN_0100dbc0(iVar2 + 0xa8,0,(uint)*(byte *)(iVar2 + 0xc5),(uint)*param_1);
  if (uVar1 == 0) {
    FUN_01009500(0x7e,0x86,extraout_r2,extraout_r3);
  }
  *(undefined1 *)(iVar2 + 0xc5) = 0x21;
  return;
}


