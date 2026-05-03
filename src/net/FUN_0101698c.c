/*
 * Function: FUN_0101698c
 * Entry:    0101698c
 * Prototype: undefined __stdcall FUN_0101698c(undefined4 * param_1)
 */


void FUN_0101698c(undefined4 *param_1)

{
  uint uVar1;
  
  if ((param_1[0xf1] != param_1[5]) || (param_1[0xf2] != param_1[7])) {
    *(undefined2 *)((int)param_1 + 0x22e) = *(undefined2 *)param_1;
    uVar1 = FUN_0100ddd0(param_1[0xf1]);
    *(short *)(param_1 + 0x8c) = (short)uVar1;
    *(undefined2 *)((int)param_1 + 0x232) = *(undefined2 *)(param_1 + 0xf2);
    *(undefined2 *)(param_1 + 0x8d) = *(undefined2 *)((int)param_1 + 0x3ca);
    FUN_0100f7c8(param_1 + 0x89,&LAB_010101cc_1,2);
  }
  FUN_0100d7f4(param_1,2);
  *(undefined1 *)((int)param_1 + 0xc6) = 0;
  *(undefined1 *)((int)param_1 + 0xc9) = 3;
  return;
}


