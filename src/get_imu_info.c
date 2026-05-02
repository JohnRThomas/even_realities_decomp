/*
 * Function: get_imu_info
 * Entry:    00032404
 * Prototype: undefined4 __stdcall get_imu_info(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
get_imu_info(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  undefined1 *puVar3;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_imu_info para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else {
    puVar3 = (undefined1 *)*param_3;
    *puVar3 = 0x17;
    puVar3[1] = 1;
    puVar3[2] = 3;
    puVar3[3] = 0x1c;
    *(undefined4 *)(puVar3 + 4) = DAT_20008488;
    *(undefined4 *)(puVar3 + 8) = DAT_2000848c;
    *(undefined4 *)(puVar3 + 0xc) = DAT_20008484;
    pGVar2 = __get_dashboard_state();
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)&pGVar2->field_0x1094;
    pGVar2 = __get_dashboard_state();
    *(undefined4 *)(puVar3 + 0x14) = *(undefined4 *)&pGVar2->field_0x1098;
    pGVar2 = __get_dashboard_state();
    *(undefined4 *)(puVar3 + 0x18) = *(undefined4 *)&pGVar2->field_0x109c;
    pGVar2 = __get_dashboard_state();
    uVar1 = 0;
    *(undefined4 *)(puVar3 + 0x1c) = *(undefined4 *)&(pGVar2->imu_fusion_context).field_0x80;
    *param_4 = 0x20;
  }
  return uVar1;
}


