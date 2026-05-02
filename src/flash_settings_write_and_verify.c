/*
 * Function: flash_settings_write_and_verify
 * Entry:    00024614
 * Prototype: int __stdcall flash_settings_write_and_verify(undefined4 param_1, void * param_2, size_t param_3)
 */


int flash_settings_write_and_verify(undefined4 param_1,void *param_2,size_t param_3)

{
  bool bVar1;
  void *buf;
  GlassesState *pGVar2;
  int iVar3;
  int iVar4;
  char *fmt;
  code *pcVar5;
  
  buf = malloc(0x1000);
  if (buf == (void *)0x0) {
    if (BLE_DEBUG == 0) {
      printk("[%s-%d]error, have no memory ! \n");
    }
    else {
      ble_printk("[%s-%d]error, have no memory ! \n","flash_settings_write_and_verify",0xd2,
                 BLE_DEBUG);
    }
    return -1;
  }
  bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
  if (bVar1) {
    memset(buf,0,0x1000);
    pGVar2 = __get_dashboard_state();
    pcVar5 = *(code **)&pGVar2->field_0x1044;
    pGVar2 = __get_dashboard_state();
    iVar3 = (*pcVar5)(pGVar2,param_1,buf,0x1000);
    if (iVar3 == 0) {
      iVar4 = memcmp(param_2,buf,param_3);
      if (iVar4 == 0) {
        fmt = "write data and read data is same, exit\n";
      }
      else {
        pGVar2 = __get_dashboard_state();
        pcVar5 = *(code **)&pGVar2->field_0x104c;
        pGVar2 = __get_dashboard_state();
        iVar4 = (*pcVar5)(pGVar2,param_1,0x1000);
        if (iVar4 != 0) {
          printk("Flash erase failed! %d\n",iVar4);
          goto LAB_00024660;
        }
        memset(buf,0,0x1000);
        memcpy(buf,param_2,param_3);
        pGVar2 = __get_dashboard_state();
        pcVar5 = *(code **)&pGVar2->field_0x1048;
        pGVar2 = __get_dashboard_state();
        iVar4 = (*pcVar5)(pGVar2,param_1,buf,0x1000);
        if (iVar4 != 0) {
          printk("Flash write failed! %d addr %08X size %d\n",iVar4,param_1,param_3);
          goto LAB_00024660;
        }
        pGVar2 = __get_dashboard_state();
        pcVar5 = *(code **)&pGVar2->field_0x1044;
        pGVar2 = __get_dashboard_state();
        iVar4 = (*pcVar5)(pGVar2,param_1,buf,0x1000);
        if (iVar4 != 0) {
          printk("Flash read failed! %d\n",iVar4);
          goto LAB_00024660;
        }
        iVar4 = memcmp(param_2,buf,param_3);
        if (iVar4 != 0) {
          printk("flash verify failed\n");
          iVar4 = 1;
          goto LAB_00024660;
        }
        fmt = "flash verify success!\n";
      }
      printk(fmt);
      iVar4 = iVar3;
    }
    else {
      printk("Flash read failed! %d\n",iVar3);
      iVar4 = iVar3;
    }
  }
  else {
    printk(" [%s] device not ready.\n","mx25r6435f@0");
    iVar4 = -1;
  }
LAB_00024660:
  free(buf);
  return iVar4;
}


