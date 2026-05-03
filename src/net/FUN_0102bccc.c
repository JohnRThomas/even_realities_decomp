/*
 * Function: FUN_0102bccc
 * Entry:    0102bccc
 * Prototype: undefined __stdcall FUN_0102bccc(char * param_1)
 */


void FUN_0102bccc(char *param_1)

{
  char cVar1;
  char cVar2;
  int iVar3;
  
  cVar1 = *param_1;
  if (cVar1 == '\x01') {
    FUN_0102bbb0(0);
    if ((DAT_21004fa1 != '\0') && (cVar2 = FUN_0102c3a0(), cVar2 != '\0')) {
LAB_0102bce0:
      DAT_21004618 = cVar1;
                    /* WARNING: Could not recover jumptable at 0x0102bcec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*DAT_21004628)();
      return;
    }
  }
  else if (cVar1 == '\x02') {
    DAT_21004fa3 = 0;
    if (DAT_21004fa2 == '\x01') {
      FUN_0102bbb0(1);
    }
    while (iVar3 = FUN_01033f6c(&DAT_21004da1), iVar3 == 0) {
      if ((DAT_21004fa2 == '\0') && (DAT_21004da6 == '\x11')) {
        DAT_21004fa3 = 1;
        FUN_0102bc5c();
      }
      else {
        DAT_21004c9c = 2;
        DAT_21004618 = 2;
        DAT_2100461c = &DAT_21004da6;
        DAT_21004620 = (uint)DAT_21004da1;
        DAT_21004624 = DAT_21004da3;
        (*DAT_21004628)(&DAT_21004618);
      }
    }
  }
  else if (cVar1 == '\0') {
    DAT_21004fa3 = 0;
    goto LAB_0102bce0;
  }
  return;
}


