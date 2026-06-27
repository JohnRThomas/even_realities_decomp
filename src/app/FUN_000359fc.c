/*
 * Function: FUN_000359fc
 * Entry:    000359fc
 * Prototype: undefined __stdcall FUN_000359fc(void)
 */


void FUN_000359fc(void)

{
  byte bVar1;
  GlassesState *pGVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (((&DAT_2000878c)[(uint)DAT_2001aef9 * 0x6d] != 0) &&
     (-1 < (int)((uint)(byte)(&DAT_2000879b)[(uint)DAT_2001aef9 * 0x1b4] << 0x1f))) {
    pGVar2 = __get_dashboard_state();
    uVar3 = FUN_00035310();
    pGVar2->field_0xdd = (char)uVar3;
    pGVar2 = __get_dashboard_state();
    uVar3 = 0;
    if (pGVar2->field_0xdd != '\0') {
      pGVar2 = __get_dashboard_state();
      uVar3 = (byte)pGVar2->field_0xdd - 1 & 0xff;
    }
    DAT_2001aef9 = (byte)uVar3;
    uVar4 = FUN_00080732();
    uVar5 = (uint)DAT_2001aef9;
    bVar1 = (&DAT_2000879b)[uVar5 * 0x1b4];
    (&DAT_20008790)[uVar3 * 0x6d] = uVar4;
    (&DAT_2000879b)[uVar5 * 0x1b4] = bVar1 | 1;
    pGVar2 = __get_dashboard_state();
    uVar3 = FUN_00035310();
    pGVar2->field_0xdd = (char)uVar3;
  }
  __normal_g_arrMsgContent();
  return;
}


