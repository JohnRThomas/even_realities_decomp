/*
 * Function: FUN_00035acc
 * Entry:    00035acc
 * Prototype: byte __stdcall FUN_00035acc(void)
 */


byte FUN_00035acc(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  pGVar2 = __get_dashboard_state();
  if ((pGVar2->field_0x10d6 != '\0') &&
     (pGVar2 = __get_dashboard_state(), *(char *)pGVar2 == '\x01')) {
    pGVar2 = __get_dashboard_state();
    __set_date(*(undefined4 *)pGVar2->glasses_state_struct_0FF0);
  }
  bVar1 = (&DAT_2000879b)[(uint)DAT_2001aef9 * 0x1b4] & 1;
  if ((((&DAT_2000879b)[(uint)DAT_2001aef9 * 0x1b4] & 1) != 0) &&
     (bVar1 = 0, (&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d] != 0)) {
    uVar3 = FUN_00080732();
    iVar5 = (&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d];
    pGVar2 = __get_dashboard_state();
    if ((uint)(byte)pGVar2->field_0x10d7 + iVar5 < uVar3) {
      bVar1 = 2;
    }
    else {
      bVar1 = 1;
    }
  }
  uVar4 = (&DAT_20008790)[(uint)DAT_2001aef9 * 0x6d];
  uVar3 = FUN_00080732();
  if (uVar3 < uVar4) {
    bVar1 = 3;
  }
  return bVar1;
}


