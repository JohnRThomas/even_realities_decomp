/*
 * Function: FUN_0100f0f8
 * Entry:    0100f0f8
 * Prototype: undefined __stdcall FUN_0100f0f8(int param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0100f0f8(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 *puVar2;
  
  if (param_2 < 0xfc) {
    *(char *)(param_1 + 1) = (char)param_2;
    return;
  }
  pcVar1 = (char *)FUN_01009500(0x2a,0x6a1,param_3,param_4);
  if ((*pcVar1 != '\0') &&
     (puVar2 = *(undefined4 **)(pcVar1 + 4), *(char *)((int)puVar2 + 0x2ea) != '\0')) {
    *(undefined1 *)((int)puVar2 + 0x2ea) = 0;
    FUN_010145a8(puVar2);
    return;
  }
  return;
}


