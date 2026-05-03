/*
 * Function: FUN_01035ab4
 * Entry:    01035ab4
 * Prototype: undefined4 __stdcall FUN_01035ab4(void)
 */


undefined4 FUN_01035ab4(void)

{
  *(int **)((int)DAT_21000748 + 4) = DAT_2100074c;
  *DAT_2100074c = (int)DAT_21000748;
  DAT_21000748 = &DAT_21000748;
  DAT_2100074c = (int *)&DAT_21000748;
  if (DAT_21000728 != (code *)0x0) {
    (*DAT_21000728)();
  }
  if ((6 < DAT_21004b04) && (DAT_21004b08 != (code *)0x0)) {
    (*DAT_21004b08)(7,"unregistered %s bus\n",DAT_21000724);
  }
  return 0;
}


