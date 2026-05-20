/*
 * Function: set_mic_info
 * Entry:    000329ec
 * Prototype: undefined4 __stdcall set_mic_info(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


undefined4 set_mic_info(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  bool bVar1;
  GlassesState *pGVar2;
  int iVar3;
  char *d;
  undefined1 uVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  uint uVar8;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("get_mic_info para is NULL\n");
    return 0xffffffff;
  }
  puVar6 = (undefined1 *)*param_3;
  if (*(char *)(param_1 + 4) == '\0') {
    DAT_200100d8 = DAT_200100d8 + 1;
  }
  else {
    DAT_200085cc = DAT_200085cc + 1;
  }
  bVar1 = z_device_is_ready((device *)&PTR_s_mx25r6435f_0_0008b3a0);
  if (bVar1) {
    pGVar2 = __get_dashboard_state();
    if (*(int *)&pGVar2->field_0x1044 == 0) {
      *puVar6 = 0x1b;
      puVar6[1] = 1;
      uVar4 = 3;
      puVar6[2] = 3;
      puVar6[3] = 1;
    }
    else {
      uVar8 = (uint)DAT_200100d8 * 0xf0 + DAT_20002420;
      printk("Flash read addr 0x%x  \n",uVar8);
      iVar3 = FUN_0008062a(0x8b3a0);
      if (iVar3 == 0) {
        printk("flash read ok\n");
        puVar6[1] = 1;
        d = puVar6 + 9;
        puVar6[2] = 3;
        puVar6[3] = 0xf5;
        *puVar6 = 0x1b;
        memcpy(d,&DAT_2001aacb,0xf0);
        iVar3 = 0;
        do {
          d = d + 1;
          if (*d == -1) {
            iVar3 = iVar3 + 1;
          }
        } while (d != puVar6 + 0x13);
        puVar6[8] = 0;
        if (((iVar3 == 10) || (DAT_200085cc == 3)) || (0x410000 < uVar8)) {
          puVar6[8] = 1;
          DAT_200085cc = 0;
          DAT_200100d8 = 0;
          DAT_20002420 = 0x400000;
          printk(
                "***********************************************************************************\n"
                );
        }
        iVar5 = 0;
        iVar3 = 0;
        do {
          do {
            iVar7 = iVar3;
            iVar3 = iVar7 + 1;
          } while (iVar7 - 4U < 4);
          iVar5 = iVar5 + (uint)(byte)puVar6[iVar7];
        } while (iVar3 != 0xfa);
        puVar6[4] = (char)((uint)iVar5 >> 0x18);
        puVar6[5] = (char)((uint)iVar5 >> 0x10);
        puVar6[7] = (char)iVar5;
        puVar6[6] = (char)((uint)iVar5 >> 8);
        uVar4 = 0xf9;
        goto LAB_00032a46;
      }
      printk("Flash read failed! %d\n",iVar3);
      puVar6[1] = 1;
      puVar6[3] = 1;
      *puVar6 = 0x1b;
      uVar4 = 2;
      puVar6[2] = 3;
    }
  }
  else {
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s():  [%s] device not ready.\n");
      }
      else {
        ble_printk("%s():  [%s] device not ready.\n","set_mic_info","mx25r6435f@0",BLE_DEBUG);
      }
    }
    *puVar6 = 0x1b;
    uVar4 = 1;
    puVar6[2] = 3;
    puVar6[1] = 1;
    puVar6[3] = 1;
  }
  puVar6[4] = uVar4;
  uVar4 = 5;
LAB_00032a46:
  *param_4 = uVar4;
  return 0;
}


