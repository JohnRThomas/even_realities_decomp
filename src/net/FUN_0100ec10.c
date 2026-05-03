/*
 * Function: FUN_0100ec10
 * Entry:    0100ec10
 * Prototype: uint __stdcall FUN_0100ec10(int param_1, undefined4 * param_2, uint param_3, uint param_4)
 */


uint FUN_0100ec10(int param_1,undefined4 *param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(byte *)(param_1 + 3) & 0x3f;
  uVar1 = ((uint)*(byte *)(param_1 + 1) + ~param_4) - uVar2 & 0xff;
  if (param_3 <= uVar1) {
    uVar1 = param_3;
  }
  if (param_2 != (undefined4 *)0x0) {
    FUN_01026198(param_2,(undefined4 *)(param_1 + uVar2 + 4 + param_4),uVar1);
  }
  return uVar1;
}


