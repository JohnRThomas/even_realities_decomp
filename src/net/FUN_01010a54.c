/*
 * Function: FUN_01010a54
 * Entry:    01010a54
 * Prototype: undefined __stdcall FUN_01010a54(char * param_1)
 */


void FUN_01010a54(char *param_1)

{
  if (*param_1 != '\0') {
    *(uint *)(*(int *)(param_1 + 4) + 0xb4) = *(uint *)(*(int *)(param_1 + 4) + 0xb4) & 0xfffffffb;
    FUN_0100ffb0((int)param_1);
    return;
  }
  *(undefined1 *)(*(int *)(param_1 + 4) + 0x104) = 0;
  return;
}


