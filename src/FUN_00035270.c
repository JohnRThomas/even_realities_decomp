/*
 * Function: FUN_00035270
 * Entry:    00035270
 * Prototype: undefined __stdcall FUN_00035270(void)
 */


void FUN_00035270(void)

{
  void *pvVar1;
  GlassesState *pGVar2;
  undefined4 *buf;
  int iVar3;
  
  iVar3 = 0;
  DAT_20019a5c = 1;
  buf = &DAT_2000878c;
  do {
    pvVar1 = memset(buf,0,0x1b4);
    iVar3 = iVar3 + 1;
    buf = (undefined4 *)((int)pvVar1 + 0x1b4);
  } while (iVar3 != 0x14);
  APP_WHITE_LIST_BUF = 10;
  DAT_2001aef9 = 0;
  pGVar2 = __get_dashboard_state();
  pGVar2->field_0xdd = 0;
  __normal_g_arrMsgContent();
  __push_g_arrMsgContent();
  DAT_20019a5c = 0;
  return;
}


