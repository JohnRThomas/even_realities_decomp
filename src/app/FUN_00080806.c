/*
 * Function: FUN_00080806
 * Entry:    00080806
 * Prototype: int __stdcall FUN_00080806(void)
 */


int FUN_00080806(void)

{
  GlassesState *pGVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined1 local_9;
  
  pGVar1 = __get_dashboard_state();
  if (*(char *)(*(int *)&pGVar1->field_0x1018 + 1) != '\0') {
    iVar2 = not_disturb_sync_data(&local_9,1,extraout_r2);
    if (iVar2 != 0) {
      return iVar2;
    }
    pGVar1 = __get_dashboard_state();
    *(undefined1 *)(*(int *)&pGVar1->field_0x1018 + 1) = 0;
    pGVar1 = __get_dashboard_state();
    if (*(char *)pGVar1 == '\x01') {
      FUN_0003f1bc();
    }
  }
  return 0;
}


