/*
 * Function: FUN_0102a2c0
 * Entry:    0102a2c0
 * Prototype: undefined __stdcall FUN_0102a2c0(undefined4 param_1, int param_2)
 */


void FUN_0102a2c0(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar3;
  
  iVar1 = FUN_0100a518(*(ushort *)(param_2 + 0x2e),9);
  uVar3 = extraout_r3;
  if (iVar1 != 0) {
    uVar3 = 0xff;
    *(undefined1 *)(iVar1 + 0xa6) = 0xff;
  }
  puVar2 = *(undefined1 **)(param_2 + 8);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = (undefined1 *)FUN_01009500(10,0x1d2,extraout_r2,uVar3);
  }
  *puVar2 = 1;
  return;
}


