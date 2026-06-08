/*
 * Function: FUN_000276f4
 * Entry:    000276f4
 * Prototype: undefined __stdcall FUN_000276f4(int param_1, char * param_2)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_000276f4(int param_1,char *param_2)

{
  char cVar1;
  GlassesState *pGVar2;
  int64_t iVar3;
  
  FUN_0007fb98((int *)(param_1 + 8));
  DAT_20008404 = *(undefined4 *)(param_1 + 8);
  pGVar2 = __get_dashboard_state();
  param_2[0x15] = (char)((byte)pGVar2->field_0xfc8 + 200 >> 8);
  pGVar2 = __get_dashboard_state();
  param_2[0x13] = pGVar2->field_0xfc4;
  pGVar2 = __get_dashboard_state();
  param_2[0x34] = pGVar2->field_0xfc4;
  __get_dashboard_state();
  param_2[2] = '\0';
  *(undefined1 *)(param_1 + 2) = 3;
  FUN_0007fbaa(param_1);
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\x02') {
    iVar3 = sys_clock_tick_get();
    if ((int)(uint)((uint)iVar3 - DAT_200083e0 < 0xbb9) <=
        (int)((int)((ulonglong)iVar3 >> 0x20) - (uint)((uint)iVar3 < DAT_200083e0))) {
      if (param_2[5] == '\n') {
        if (*param_2 == '\0') {
          param_2[0xc] = '\x06';
        }
        param_2[1] = '\x01';
      }
      param_2[3] = '\x01';
      iVar3 = sys_clock_tick_get();
      DAT_200083e0 = (uint)iVar3;
    }
  }
  else {
    if (cVar1 == '\x04') {
      if (param_2[5] == '\n') {
        if (*param_2 == '\0') {
          param_2[0xc] = '\x06';
        }
        param_2[1] = '\x01';
      }
      if (param_2[2] == '\0') {
        param_2[2] = '\x01';
      }
    }
    else if (cVar1 == '\x01') {
      param_2[0xc] = '\t';
      param_2[3] = '\0';
      if (*(uint *)(param_1 + 8) < 500) {
        if (DAT_20019933 != '\0') {
          return;
        }
        DAT_20019933 = 1;
        return;
      }
      DAT_20019933 = '\0';
    }
    iVar3 = sys_clock_tick_get();
    DAT_200083e0 = (uint)iVar3;
  }
  return;
}


