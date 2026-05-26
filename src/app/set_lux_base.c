/*
 * Function: set_lux_base
 * Entry:    00011098
 * Prototype: undefined4 __stdcall set_lux_base(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_lux_base(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  char cVar1;
  undefined4 uVar2;
  undefined *puVar3;
  GlassesState *pGVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  undefined *puVar8;
  undefined1 *puVar9;
  undefined1 uVar10;
  float fVar11;
  float fVar12;
  ulonglong uVar13;
  undefined4 auStack_c0 [4];
  undefined *local_b0;
  undefined *local_5c;
  undefined *local_58;
  undefined *local_54;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_lux_base para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar9 = (undefined1 *)*param_3;
    *puVar9 = 0x2e;
    puVar9[2] = 3;
    puVar9[1] = 1;
    puVar9[3] = 6;
    puVar3 = (undefined *)__opt3007_read(0,param_2,param_3);
    cVar1 = *(char *)(param_1 + 4);
    switch(cVar1) {
    case '\x01':
      if (puVar3 + -0x32 < &DAT_00000096) {
        cVar7 = '\0';
      }
      else {
        cVar7 = cVar1;
        if ((int)puVar3 < 1) {
          puVar3 = (undefined *)0x13880;
          cVar7 = '\x02';
        }
      }
      puVar9[4] = cVar7;
      pGVar4 = __get_dashboard_state();
      *(undefined **)&pGVar4->field_0xfa4 = puVar3;
      DAT_200100d6 = DAT_200100d6 | 1;
      break;
    case '\x02':
      if (puVar3 + -200 < &DAT_00000320) {
        cVar7 = '\0';
      }
      else {
        cVar7 = '\x01';
        if ((int)puVar3 < 1) {
          puVar3 = (undefined *)0x13880;
          cVar7 = cVar1;
        }
      }
      puVar9[4] = cVar7;
      pGVar4 = __get_dashboard_state();
      *(undefined **)&pGVar4->field_0xfa8 = puVar3;
      DAT_200100d6 = DAT_200100d6 | 2;
      break;
    case '\x03':
      if (puVar3 + -1000 < (undefined *)0x2328) {
        uVar10 = 0;
      }
      else {
        uVar10 = 1;
        if ((int)puVar3 < 1) {
          uVar10 = 2;
          puVar3 = (undefined *)0x13880;
        }
      }
      puVar9[4] = uVar10;
      pGVar4 = __get_dashboard_state();
      *(undefined **)&pGVar4->field_0xfac = puVar3;
      DAT_200100d6 = DAT_200100d6 | 4;
      break;
    case '\x04':
      if ((int)puVar3 < 80000) {
        uVar10 = 1;
        if ((int)puVar3 < 1) {
          uVar10 = 2;
          puVar3 = (undefined *)0x13880;
        }
      }
      else {
        uVar10 = 0;
      }
      puVar9[4] = uVar10;
      pGVar4 = __get_dashboard_state();
      *(undefined **)&(pGVar4->opt3007_context).field_0x14 = puVar3;
      DAT_200100d6 = ~((ushort)~(ushort)(((uint)DAT_200100d6 << 0x11) >> 0x10) >> 1);
    }
    if (0x8000 < DAT_200100d6) {
      pGVar4 = __get_dashboard_state();
      uVar13 = __floatunsidf(*(uint *)&(pGVar4->opt3007_context).field_0x14);
      uVar13 = __divdf3(0,0x40d5a300,(uint)uVar13,(uint)(uVar13 >> 0x20));
      pGVar4 = __get_dashboard_state();
      uVar5 = __truncdfsf2((uint)uVar13,(uint)(uVar13 >> 0x20));
      *(uint *)&pGVar4->field_0xfc0 = uVar5;
      pGVar4 = __get_dashboard_state();
      uVar13 = __floatunsidf(*(uint *)&pGVar4->field_0xfa4);
      uVar13 = __divdf3(0x33333333,0x40b072b3,(uint)uVar13,(uint)(uVar13 >> 0x20));
      pGVar4 = __get_dashboard_state();
      uVar5 = __truncdfsf2((uint)uVar13,(uint)(uVar13 >> 0x20));
      *(uint *)&pGVar4->field_0xfbc = uVar5;
      pGVar4 = __get_dashboard_state();
      fVar12 = *(float *)&pGVar4->field_0xfc0;
      pGVar4 = __get_dashboard_state();
      fVar11 = *(float *)&pGVar4->field_0xfbc;
      pGVar4 = __get_dashboard_state();
      *(int *)&pGVar4->field_0xfb4 = (int)((fVar12 + fVar11) * 0.5 * 1e+06);
    }
    pGVar4 = __get_dashboard_state();
    FUN_00024abc(pGVar4);
    cVar7 = '\0';
    do {
      iVar6 = read_sys_settting_from_flash(auStack_c0);
      if (((iVar6 == 0) &&
          ((((puVar8 = local_58, cVar1 == '\x01' || (puVar8 = local_5c, cVar1 == '\x02')) ||
            (puVar8 = local_54, cVar1 == '\x03')) || (puVar8 = local_b0, cVar1 == '\x04')))) &&
         (puVar3 == puVar8)) goto LAB_00011210;
      cVar7 = cVar7 + '\x01';
      sleep(100);
    } while (cVar7 != '\x05');
    puVar9[4] = 3;
LAB_00011210:
    puVar9[5] = cVar1;
    *(undefined **)(puVar9 + 6) = puVar3;
    uVar2 = 0;
    *param_4 = 10;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar2 = 0xfffffffe;
  }
  return uVar2;
}


