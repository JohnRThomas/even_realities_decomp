/*
 * Function: FUN_000157c4
 * Entry:    000157c4
 * Prototype: undefined __stdcall FUN_000157c4(void)
 */


void FUN_000157c4(void)

{
  GlassesState *pGVar1;
  char cVar2;
  bool bVar3;
  
  cVar2 = FUN_00033d5c();
  if (cVar2 != '\x01') {
    DAT_2001093a = DAT_2001093a + 1;
    FUN_00081216();
    update_burial_point_day_index();
    cVar2 = FUN_00028acc();
    if ((cVar2 == '\x01') && (bVar3 = is_in_box(), !bVar3)) {
      FUN_00081258(60000,0);
    }
    pGVar1 = GLOBAL_STATE;
    if (9 < DAT_2001093a) {
      DAT_2001093a = 0;
      *(undefined4 *)&GLOBAL_STATE->field_0x1060 = 0x3e;
      k_sem_give(&pGVar1->sem_6);
      return;
    }
  }
  return;
}


