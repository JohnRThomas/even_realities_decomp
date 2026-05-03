/*
 * Function: get_flash_info
 * Entry:    00033604
 * Prototype: undefined4 __stdcall get_flash_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 get_flash_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  undefined1 uVar4;
  undefined1 *puVar5;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_flash_info para is NULL\n");
    return 0xffffffff;
  }
  puVar5 = (undefined1 *)*param_3;
  *puVar5 = 0x1e;
  uVar4 = *(undefined1 *)(param_1 + 1);
  puVar5[2] = 3;
  puVar5[1] = uVar4;
  puVar5[3] = 4;
  bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
  if (bVar1) {
    pGVar2 = __get_dashboard_state();
    if (*(int *)&pGVar2->field_0x1044 != 0) {
      iVar3 = FUN_0008062a(0x8b3a0);
      if (iVar3 != 0) {
        printk("Flash read failed! %d\n",iVar3);
        *puVar5 = 0x1e;
        uVar4 = *(undefined1 *)(param_1 + 1);
        puVar5[2] = 3;
        puVar5[1] = uVar4;
        puVar5[3] = 1;
        uVar4 = 2;
        goto LAB_0003366a;
      }
      printk("flash read ok\n",0);
    }
    memcpy(puVar5 + 4,&DAT_2001aa7d,0x4e);
    uVar4 = 0x52;
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s():  [%s] device not ready.\n");
      }
      else {
        ble_printk("%s():  [%s] device not ready.\n","get_flash_info","mx25r6435f@0",BLE_DEBUG);
      }
    }
    *puVar5 = 0x1e;
    puVar5[1] = *(undefined1 *)(param_1 + 1);
    puVar5[2] = 3;
    uVar4 = 1;
    puVar5[3] = 1;
LAB_0003366a:
    puVar5[4] = uVar4;
    uVar4 = 5;
  }
  *param_4 = uVar4;
  return 0;
}


