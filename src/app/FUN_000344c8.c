/*
 * Function: FUN_000344c8
 * Entry:    000344c8
 * Prototype: undefined __stdcall FUN_000344c8(void)
 */


void FUN_000344c8(void)

{
  bool is_in_box;
  GlassesState *pGVar1;
  char cVar2;
  
  if (DAT_2001abc0 != '\x01') {
    return;
  }
  if (DAT_2001abc1 != '\x01') {
    return;
  }
  pGVar1 = __get_dashboard_state();
  if (299 < (uint)pGVar1->field3707_0x10b0) {
    return;
  }
  is_in_box = get_box_status_by_type(IN_BOX);
  if (!is_in_box) {
    return;
  }
  pGVar1 = __get_dashboard_state();
  if (0x5e < (byte)pGVar1->field_0xfc4) {
    return;
  }
  pGVar1 = __get_dashboard_state();
  *(int *)&pGVar1->field_0x10cc = *(int *)&pGVar1->field_0x10cc + 1;
  pGVar1 = __get_dashboard_state();
  if ((char)pGVar1->field_0xfcc < '\0') {
    pGVar1 = __get_dashboard_state();
    if (pGVar1->field_0x10d0 != '\x02') {
      pGVar1 = __get_dashboard_state();
      cVar2 = '\0';
      goto LAB_0003453e;
    }
  }
  else {
    pGVar1 = __get_dashboard_state();
    if ((byte)pGVar1->field_0x10d1 < 0x15) {
      pGVar1 = __get_dashboard_state();
      cVar2 = pGVar1->field_0x10d1 + '\x01';
LAB_0003453e:
      pGVar1->field_0x10d1 = cVar2;
    }
  }
  pGVar1 = __get_dashboard_state();
  if ((*(uint *)&pGVar1->field_0x10cc < 0x3d) ||
     (pGVar1 = __get_dashboard_state(), pGVar1->field_0x10d0 != '\0')) {
    pGVar1 = __get_dashboard_state();
    if (((byte)pGVar1->field_0x10d1 < 0x15) ||
       (pGVar1 = __get_dashboard_state(), pGVar1->field_0x10d0 == '\x02')) {
      return;
    }
  }
  else {
    pGVar1 = __get_dashboard_state();
    pGVar1->field_0x10d0 = 1;
    pGVar1 = __get_dashboard_state();
    if (((byte)pGVar1->field_0x10d1 < 0x15) ||
       (pGVar1 = __get_dashboard_state(), pGVar1->field_0x10d0 == '\x02')) goto LAB_000345dc;
  }
  pGVar1 = __get_dashboard_state();
  pGVar1->field_0x10d0 = 2;
LAB_000345dc:
  pGVar1 = __get_dashboard_state();
  FUN_00024abc(pGVar1);
  return;
}


