/*
 * Function: opt3007_get_max_lux
 * Entry:    00010a70
 * Prototype: uint __stdcall opt3007_get_max_lux(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


uint opt3007_get_max_lux(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  longlong lVar1;
  uint uVar2;
  GlassesState *pGVar3;
  ulonglong uVar4;
  
  if (DAT_20019a6f == '\0') {
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = __opt3007_read(0,param_2,param_3);
    if (1 < uVar2 + 1) {
      pGVar3 = __get_dashboard_state();
      lVar1 = (longlong)(int)uVar2 * (longlong)*(int *)&pGVar3->field_0xfb4;
      uVar4 = __aeabi_l2d((uint)lVar1,(uint)((ulonglong)lVar1 >> 0x20));
      uVar4 = __divdf3((uint)uVar4,(uint)(uVar4 >> 0x20),0,0x412e8480);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          printk("%s(): opt3007_get_max_lux %d %f luminance_curve_a0 %d\n","opt3007_get_max_lux",
                 uVar2,*(undefined4 *)&pGVar3->field_0xfb4,uVar4,*(undefined4 *)&pGVar3->field_0xfb4
                );
        }
        else {
          pGVar3 = __get_dashboard_state();
          ble_printk("%s(): opt3007_get_max_lux %d %f luminance_curve_a0 %d\n","opt3007_get_max_lux"
                     ,uVar2,*(undefined4 *)&pGVar3->field_0xfb4,uVar4,
                     *(undefined4 *)&pGVar3->field_0xfb4);
        }
      }
      uVar2 = _cast_double_to_int((uint)uVar4,(uint)(uVar4 >> 0x20));
    }
  }
  return uVar2;
}


