/*
 * Function: get_charge_test_info
 * Entry:    0003258c
 * Prototype: undefined4 __stdcall get_charge_test_info(int param_1, uint param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_charge_test_info(int param_1,uint param_2,undefined4 *param_3,undefined1 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined2 *puVar6;
  
  if ((((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) || (param_1 == 0)) ||
     (param_2 < 4)) {
    printk("%s para is NULL\n","get_charge_test_info",param_3,param_4,param_4);
    uVar2 = 0xffffffff;
  }
  else {
    puVar4 = (undefined1 *)*param_3;
    iVar5 = 0;
    *puVar4 = 0x3d;
    puVar4[1] = 1;
    puVar4[2] = 3;
    puVar4[3] = 0x1a;
    pGVar3 = __get_dashboard_state();
    puVar4[4] = pGVar3->field_0x10a8;
    pGVar3 = __get_dashboard_state();
    puVar4[5] = pGVar3->field_0x10a9;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 6) = pGVar3->field2801_0x10b0;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 10) = pGVar3->field2802_0x10b4;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0xe) = pGVar3->field2803_0x10b8;
    puVar6 = (undefined2 *)(puVar4 + 0x12);
    do {
      pGVar3 = __get_dashboard_state();
      iVar1 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      *puVar6 = *(undefined2 *)(pGVar3->field2762_0x1080 + iVar1 + 0x3c);
      puVar6 = puVar6 + 1;
    } while (iVar5 != 6);
    pGVar3 = __get_dashboard_state();
    puVar4[0x1e] = pGVar3->field_0x10c8;
    pGVar3 = __get_dashboard_state();
    uVar2 = 0;
    puVar4[0x1f] = pGVar3->field_0x10d0;
    *param_4 = 0x20;
  }
  return uVar2;
}


