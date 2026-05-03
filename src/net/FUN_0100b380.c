/*
 * Function: FUN_0100b380
 * Entry:    0100b380
 * Prototype: undefined __stdcall FUN_0100b380(undefined4 param_1, undefined1 * param_2)
 */


void FUN_0100b380(undefined4 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *param_2 = 0x32;
  uVar2 = DAT_21000c5c;
  uVar1 = DAT_21000c58;
  *(undefined4 *)(param_2 + 3) = DAT_21000c54;
  *(undefined4 *)(param_2 + 7) = uVar1;
  *(undefined4 *)(param_2 + 0xb) = uVar2;
  return;
}


