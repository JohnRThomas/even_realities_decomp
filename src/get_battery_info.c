/*
 * Function: get_battery_info
 * Entry:    000337ac
 * Prototype: undefined4 __stdcall get_battery_info(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_battery_info(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  GlassesState *pGVar4;
  int iVar5;
  uint uVar6;
  int extraout_r2;
  uint extraout_r2_00;
  char cVar7;
  undefined1 *puVar8;
  undefined8 uVar9;
  
  puVar8 = (undefined1 *)*param_3;
  uVar9 = FUN_00080638();
  if (param_4 == (undefined1 *)0x0) {
    printk("get_battery_info para is NULL\n",(int)((ulonglong)uVar9 >> 0x20));
    return 0xffffffff;
  }
  if (4 < param_2) {
    DAT_2001abc3 = *(byte *)(param_1 + 4);
    FUN_00016638(DAT_2001abc3 & 0x7f);
    if (param_2 != 5) {
      cVar7 = *(char *)(param_1 + 5);
      if (cVar7 == '\a') {
        set_box_status(LID_CLOSED,false);
        DAT_20019a62 = 0;
      }
      else if (cVar7 == '\b') {
        set_box_status(LID_CLOSED,true);
        FUN_0002c8a4();
      }
      else if (cVar7 == '\x06') {
        DAT_20019a62 = 1;
        set_box_status(LID_CLOSED,true);
      }
    }
  }
  *puVar8 = 0x13;
  puVar8[1] = 1;
  puVar8[2] = 2;
  puVar8[3] = 6;
  puVar8[4] = 0;
  uVar3 = FUN_00026f3c();
  if (((uVar3 < 0x157c) || (pGVar4 = __get_dashboard_state(), (char)pGVar4->field_0xfcc < '\0')) ||
     (DAT_2001abbd != '\0')) {
    DAT_2001abbc = 0;
    DAT_2001abbb = '\0';
  }
  else if (DAT_2001abbc < 5) {
    DAT_2001abbc = DAT_2001abbc + 1;
  }
  pGVar4 = __get_dashboard_state();
  if ((5999 < *(short *)&pGVar4->field_0xfce) ||
     ((pGVar4 = __get_dashboard_state(), 4999 < *(short *)&pGVar4->field_0xfce &&
      (pGVar4 = __get_dashboard_state(), 0xd1 < (byte)pGVar4->field_0xfc8)))) {
    puVar8[4] = 2;
  }
  __get_dashboard_state();
  iVar5 = FUN_00033784();
  if ((int)(uint)*(byte *)(extraout_r2 + 0xfc4) < iVar5 + -1) {
    DAT_2001abbd = '\0';
LAB_000338e0:
    if (((puVar8[4] != '\0') || (DAT_20003054 != '\0')) || (DAT_2001abbd != '\0'))
    goto LAB_000338d0;
    DAT_2001abbb = DAT_2001abbb + 1;
    if (DAT_2001abbb < 0x28) goto LAB_00033900;
LAB_000339b0:
    puVar8[4] = 4;
  }
  else {
    __get_dashboard_state();
    uVar6 = FUN_00033784();
    if (extraout_r2_00 < uVar6) {
      if (DAT_2001abbd == '\0') goto LAB_000338e0;
    }
    else {
      DAT_2001abbd = '\x01';
    }
    puVar8[4] = 1;
    DAT_2001abbc = 0;
LAB_000338d0:
    DAT_2001abbb = 0;
    if (puVar8[4] == '\0') {
LAB_00033900:
      if ((((uVar3 - 1 < 0x1e77) && (DAT_2001abbd == '\0')) && (0x27 < DAT_2001abbc)) &&
         (pGVar4 = __get_dashboard_state(), -1 < (char)pGVar4->field_0xfcc)) goto LAB_000339b0;
    }
  }
  puVar8[5] = (char)(uVar3 >> 8);
  puVar8[6] = (char)uVar3;
  pGVar4 = __get_dashboard_state();
  puVar8[7] = pGVar4->field_0xfc4;
  pGVar4 = __get_dashboard_state();
  if ((char)pGVar4->field_0xfcc < '\0') {
    DAT_2001abbc = 0;
    DAT_2001abbb = 0;
    puVar8[8] = 1;
  }
  else {
    puVar8[8] = 0;
  }
  if (((uVar3 - 1 < 4999) && (pGVar4 = __get_dashboard_state(), -1 < (char)pGVar4->field_0xfcc)) &&
     (DAT_2001abbd == '\0')) {
    if ((0x27 < DAT_2001abbc) && (pGVar4 = __get_dashboard_state(), -1 < (char)pGVar4->field_0xfcc))
    {
      puVar8[9] = 100;
      puVar8[4] = 4;
    }
  }
  else {
    pGVar4 = __get_dashboard_state();
    cVar7 = pGVar4->field_0xfcc;
    if (cVar7 < '\0') {
      cVar7 = -cVar7;
    }
    puVar8[9] = cVar7;
  }
  *param_4 = 10;
  bVar2 = is_box_lid_closed();
  if (!bVar2) {
    DAT_20019a62 = 0;
  }
  bVar1 = puVar8[4];
  if (bVar1 == 0) {
    if (DAT_2001abbd == '\0') {
      bVar2 = true;
      goto LAB_000339ca;
    }
    DAT_2001abbb = bVar1;
    DAT_2001abbc = bVar1;
    puVar8[4] = 1;
  }
  bVar2 = false;
LAB_000339ca:
  set_box_status(CHARGING,bVar2);
  if ((((3 < (DAT_2001abbc | DAT_2001abbb)) &&
       (pGVar4 = __get_dashboard_state(), 2 < (byte)pGVar4->field_0xfc4)) &&
      (pGVar4 = __get_dashboard_state(), (byte)pGVar4->field_0xfc4 < 100)) &&
     (10000 < (uint)((int)uVar9 - DAT_200085b0))) {
    DAT_200085b0 = (int)uVar9;
    puVar8[9] = 0x80;
  }
  return 0;
}


