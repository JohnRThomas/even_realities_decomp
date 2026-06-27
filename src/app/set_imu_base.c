/*
 * Function: set_imu_base
 * Entry:    00033058
 * Prototype: undefined4 __stdcall set_imu_base(undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4
set_imu_base(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 uVar5;
  char cVar6;
  int iVar7;
  char local_c4 [20];
  undefined4 auStack_b0 [3];
  int local_a4;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_imu_base para is NULL\n");
    uVar1 = 0xffffffff;
  }
  else if (DAT_2001abc2 == '\x01') {
    puVar4 = (undefined1 *)*param_3;
    *puVar4 = 0x2d;
    puVar4[2] = 3;
    puVar4[3] = 5;
    puVar4[1] = 1;
    local_c4[0] = '\0';
    local_c4[1] = '\0';
    local_c4[2] = '\0';
    local_c4[3] = '\0';
    memset(local_c4 + 4,0,0x10);
    if (((((DAT_20008488 != 0 || DAT_2000848c != 0) || DAT_20008484 != 0) ||
         (pGVar2 = __get_dashboard_state(), *(int *)&pGVar2->field_0x1094 != 0)) ||
        (pGVar2 = __get_dashboard_state(), *(int *)&pGVar2->field_0x1098 != 0)) ||
       (pGVar2 = __get_dashboard_state(), uVar5 = 1, *(int *)&pGVar2->field_0x109c != 0)) {
      pGVar2 = __get_dashboard_state();
      uVar5 = 0;
      *(int *)&(pGVar2->imu_fusion_context).field_0x80 = DAT_2000848c;
    }
    iVar7 = DAT_2000848c;
    puVar4[4] = uVar5;
    __sprintf_chk(local_c4,0,0x14,"base: %d",iVar7);
    pGVar2 = __get_dashboard_state();
    cVar6 = '\0';
    *(undefined4 *)(puVar4 + 5) = *(undefined4 *)&(pGVar2->imu_fusion_context).field_0x80;
    pGVar2 = __get_dashboard_state();
    __save_sys_settings(pGVar2);
    pGVar2 = __get_dashboard_state();
    iVar7 = *(int *)&(pGVar2->imu_fusion_context).field_0x80;
    do {
      iVar3 = read_sys_settting_from_flash(auStack_b0);
      if ((iVar3 == 0) && (local_a4 == iVar7)) goto LAB_0003313c;
      cVar6 = cVar6 + '\x01';
      sleep(100);
    } while (cVar6 != '\x05');
    puVar4[4] = 2;
LAB_0003313c:
    uVar1 = 0;
    *param_4 = 9;
  }
  else {
    printk("warning: not test mode,disable setting\n");
    uVar1 = 0xfffffffe;
  }
  return uVar1;
}


