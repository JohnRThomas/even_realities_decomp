/*
 * Function: FUN_0101fe24
 * Entry:    0101fe24
 * Prototype: undefined4 __stdcall FUN_0101fe24(char * param_1)
 */


undefined4 FUN_0101fe24(char *param_1)

{
  if ((((*param_1 != '\0') && (param_1[1] != '\0')) && (0x1a < *(ushort *)(param_1 + 2))) &&
     (0x1a < *(ushort *)(param_1 + 4))) {
    DAT_21000eac = *(undefined4 *)param_1;
    DAT_21000eb0 = *(undefined2 *)(param_1 + 4);
    return 0;
  }
  return 0x12;
}


