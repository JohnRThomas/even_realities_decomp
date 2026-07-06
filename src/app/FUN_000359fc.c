/*
 * Function: FUN_000359fc
 * Entry:    000359fc
 * Prototype: undefined __stdcall FUN_000359fc(uint param_1, undefined4 param_2)
 */


void FUN_000359fc(uint param_1,undefined4 param_2)

{
  byte bVar1;
  GlassesState *pGVar2;
  undefined4 uVar3;
  undefined4 extraout_r1;
  uint uVar4;
  undefined4 *extraout_r2;
  undefined4 *puVar5;
  uint uVar6;
  
  uVar6 = (uint)DAT_2001aef9;
  puVar5 = &DAT_2000878c + uVar6 * 0x6d;
  if (((&DAT_2000878c)[uVar6 * 0x6d] != 0) &&
     (-1 < (int)((uint)(byte)(&DAT_2000879b)[uVar6 * 0x1b4] << 0x1f))) {
    pGVar2 = __get_dashboard_state();
    uVar6 = FUN_00035310();
    pGVar2->field20_0xc8[0x15] = (char)uVar6;
    pGVar2 = __get_dashboard_state();
    uVar6 = 0;
    if (pGVar2->field20_0xc8[0x15] != '\0') {
      pGVar2 = __get_dashboard_state();
      uVar6 = (byte)pGVar2->field20_0xc8[0x15] - 1 & 0xff;
    }
    DAT_2001aef9 = (byte)uVar6;
    uVar3 = FUN_00080732();
    uVar4 = (uint)DAT_2001aef9;
    bVar1 = (&DAT_2000879b)[uVar4 * 0x1b4];
    (&DAT_20008790)[uVar6 * 0x6d] = uVar3;
    (&DAT_2000879b)[uVar4 * 0x1b4] = bVar1 | 1;
    pGVar2 = __get_dashboard_state();
    param_1 = FUN_00035310();
    pGVar2->field20_0xc8[0x15] = (char)param_1;
    param_2 = extraout_r1;
    puVar5 = extraout_r2;
  }
  __normal_g_arrMsgContent(param_1,param_2,puVar5);
  return;
}


