/*
 * Function: FUN_01035b74
 * Entry:    01035b74
 * Prototype: undefined __stdcall FUN_01035b74(int param_1)
 */


void FUN_01035b74(int param_1)

{
  if (param_1 != 0) {
    if (((*(short *)(param_1 + 0x24) != *(short *)(param_1 + 10)) && (3 < DAT_21004b04)) &&
       (DAT_21004b08 != (code *)0x0)) {
      (*DAT_21004b08)(4,"%s: freeing non-empty virtqueue\r\n",*(undefined4 *)(param_1 + 4));
    }
    FUN_0103bce2(param_1);
    return;
  }
  return;
}


