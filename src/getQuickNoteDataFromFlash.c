/*
 * Function: getQuickNoteDataFromFlash
 * Entry:    00026750
 * Prototype: undefined4 __stdcall getQuickNoteDataFromFlash(uint param_1, void * param_2, size_t param_3, void * param_4, size_t param_5)
 */


undefined4
getQuickNoteDataFromFlash(uint param_1,void *param_2,size_t param_3,void *param_4,size_t param_5)

{
  bool bVar1;
  char *pcVar2;
  GlassesState *pGVar3;
  int iVar4;
  char *pcVar5;
  size_t extraout_r2;
  size_t n;
  undefined4 extraout_r2_00;
  code *pcVar6;
  
  if (param_1 < 4) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): read quicknote flash data to ram...\r\n\n");
      }
      else {
        ble_printk("%s(): read quicknote flash data to ram...\r\n\n","getQuickNoteDataFromFlash",
                   param_3,BLE_DEBUG);
      }
    }
    bVar1 = z_device_is_ready((device *)&DAT_0008b3a0);
    if (bVar1) {
      memset(&DAT_20019133,0,0x800);
      pGVar3 = __get_dashboard_state();
      pcVar6 = *(code **)&pGVar3->field_0x1044;
      pGVar3 = __get_dashboard_state();
      iVar4 = (*pcVar6)(pGVar3,0x403000,&DAT_20019133,0x800);
      if (iVar4 == 0) {
        iVar4 = param_1 * 0x200;
        if ((&DAT_20019133)[iVar4] == -0x56) {
          if (0x28 < (int)param_3) {
            param_3 = 0x29;
          }
          memcpy(param_2,&DAT_20019134 + iVar4,param_3);
          n = 0x119;
          if ((int)param_5 < 0x11a) {
            n = param_5;
          }
          memcpy(param_4,(void *)(iVar4 + 0x2001915d),n);
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): export flash data to global ram...\n");
              return 0;
            }
            ble_printk("%s(): export flash data to global ram...\n","getQuickNoteDataFromFlash",
                       extraout_r2_00,BLE_DEBUG);
            return 0;
          }
          return 0;
        }
        if (LOG_LEVEL < 3) {
          return 0xffffffff;
        }
        pcVar2 = "%s(): quicknote data is invaild,don\'t export to global ram..\n";
        param_3 = extraout_r2;
        goto LAB_00026770;
      }
      if (LOG_LEVEL < 1) {
        return 0xffffffff;
      }
      pcVar5 = (char *)0x403000;
      pcVar2 = "%s():  form address [%d] read data failed.\n\n";
    }
    else {
      if (LOG_LEVEL < 1) {
        return 0xffffffff;
      }
      pcVar5 = "mx25r6435f@0";
      pcVar2 = "%s():  [%s] device not ready.\n\n";
    }
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2,"getQuickNoteDataFromFlash",pcVar5,BLE_DEBUG);
    }
  }
  else {
    if (LOG_LEVEL < 1) {
      return 0xffffffff;
    }
    pcVar2 = "%s(): quicknote upgrade index out of range\n";
LAB_00026770:
    if (BLE_DEBUG == 0) {
      printk(pcVar2);
    }
    else {
      ble_printk(pcVar2,"getQuickNoteDataFromFlash",param_3,BLE_DEBUG);
    }
  }
  return 0xffffffff;
}


