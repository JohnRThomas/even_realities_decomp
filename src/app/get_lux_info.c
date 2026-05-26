/*
 * Function: get_lux_info
 * Entry:    00010fd0
 * Prototype: undefined4 __stdcall get_lux_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_lux_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  uint uVar2;
  GlassesState *pGVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  uint extraout_r3;
  undefined1 *puVar4;
  uint in_fpscr;
  uint uVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_lux_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar4 = (undefined1 *)*param_3;
    puVar4[1] = 1;
    *puVar4 = 0x20;
    puVar4[2] = 3;
    puVar4[3] = 0x20;
    uVar2 = __opt3007_read(0,param_2,3);
    *(uint *)(puVar4 + 4) = uVar2;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 8) = *(undefined4 *)&pGVar3->field_0xfa4;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0xc) = *(undefined4 *)&pGVar3->field_0xfa8;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0x10) = *(undefined4 *)&pGVar3->field_0xfac;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0x14) = *(undefined4 *)&(pGVar3->opt3007_context).field_0x14;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0x18) = *(undefined4 *)&pGVar3->field_0xfb4;
    pGVar3 = __get_dashboard_state();
    *(undefined4 *)(puVar4 + 0x1c) = *(undefined4 *)&pGVar3->field_0xfb8;
    pGVar3 = __get_dashboard_state();
    uVar5 = VectorSignedToFloat(*(undefined4 *)&pGVar3->field_0xfb4,(byte)(in_fpscr >> 0x16) & 3);
    uVar6 = __aeabi_f2d(uVar5,extraout_r1,extraout_r2,extraout_r3);
    uVar6 = __divdf3((uint)uVar6,(uint)(uVar6 >> 0x20),0,0x412e8480);
    uVar7 = __floatunsidf(uVar2);
    uVar6 = __muldf3((uint)uVar6,(uint)(uVar6 >> 0x20),(uint)uVar7,(uint)(uVar7 >> 0x20));
    uVar2 = __fixunsdfsi((uint)uVar6,(uint)(uVar6 >> 0x20));
    *(uint *)(puVar4 + 0x20) = uVar2;
    uVar1 = 0;
    *param_4 = 0x24;
  }
  return uVar1;
}


