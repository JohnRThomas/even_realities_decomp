/*
 * Function: FUN_00028d2c
 * Entry:    00028d2c
 * Prototype: bool __stdcall FUN_00028d2c(void)
 */


bool FUN_00028d2c(void)

{
  GlassesState *pGVar1;
  GlassesState *pGVar2;
  uint uVar3;
  GlassesState *pGVar4;
  
  pGVar1 = __get_dashboard_state();
  pGVar2 = __get_dashboard_state();
  uVar3 = FUN_00019cec();
  if ((DAT_20019a5f == '\x0f') && ((uVar3 & 0xff) != 0)) {
    pGVar4 = __get_dashboard_state();
    if (*(char *)pGVar4 == '\x01') {
      if ((int)((uint)(byte)pGVar2->field_0x6de << 0x1f) < 0) {
        pGVar1->field_0xe4 = pGVar1->field_0xe4 | 3;
      }
    }
    else {
      pGVar2->field_0x6de = pGVar2->field_0x6de | 1;
    }
  }
  return (pGVar1->field_0xe4 & 3) == 3;
}


