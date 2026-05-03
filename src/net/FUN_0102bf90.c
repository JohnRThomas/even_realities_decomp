/*
 * Function: FUN_0102bf90
 * Entry:    0102bf90
 * Prototype: undefined __stdcall FUN_0102bf90(int param_1)
 */


void FUN_0102bf90(int param_1)

{
  if (DAT_21004fa5 == '\0') {
    if (param_1 == 0) {
      if (DAT_21004fa6 != '\0') {
        (*DAT_2100463c)(1);
        DAT_21004fa6 = '\0';
      }
    }
    else if (DAT_21004fa6 == '\0') {
      (*DAT_2100463c)(0);
      DAT_21004fa6 = '\x01';
    }
  }
  return;
}


