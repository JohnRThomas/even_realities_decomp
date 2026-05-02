/*
 * Function: mic_transm_thread
 * Entry:    00033498
 * Prototype: undefined __stdcall mic_transm_thread(void)
 */


void mic_transm_thread(void)

{
  char *pcVar1;
  bool bVar2;
  int iVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r1;
  undefined4 uVar5;
  undefined4 extraout_r1_00;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  k_timeout_t timeout;
  undefined *local_f8;
  undefined2 local_f4;
  char local_f2 [206];
  
  uVar7 = 0;
  local_f8 = (undefined1 *)0x0;
  memset(&local_f4,0,0xca);
  z_impl_k_sem_init((k_sem *)&DAT_200085b4,0,1);
  uVar5 = extraout_r1;
  do {
    timeout.ticks._4_4_ = 0xffffffff;
    timeout.ticks._0_4_ = uVar5;
    z_impl_k_sem_take((k_sem *)&DAT_200085b4,timeout);
    local_f8 = &DAT_01f1a55a;
    bVar2 = z_device_is_ready((device *)&DAT_0008b3a0);
    if (bVar2) {
      pGVar4 = __get_dashboard_state();
      if (*(int *)&pGVar4->field_0x1044 != 0) {
        uVar8 = 0;
        while( true ) {
          uVar9 = uVar8 * 200 + DAT_20002420;
          printk("start send mic data,flash address:0x%x,seq:%d\n",uVar9,uVar8);
          iVar3 = FUN_0008062a((int)&DAT_0008b3a0);
          if (iVar3 != 0) break;
          iVar6 = 6;
          local_f4 = (ushort)(byte)uVar8;
          iVar3 = 0;
          do {
            pcVar1 = (char *)((int)&local_f8 + iVar6);
            iVar6 = iVar6 + 1;
            if (*pcVar1 == -1) {
              iVar3 = iVar3 + 1;
            }
          } while (iVar6 != 0x1a);
          if ((iVar3 == 0x14) || (0x410000 < uVar9)) {
            local_f4 = 0x100;
            goto LAB_0003354c;
          }
          pGVar4 = __get_dashboard_state();
          iVar3 = (**(code **)&pGVar4->field_0x788)(&local_f8,0xce);
          if (iVar3 < 0) {
            uVar7 = uVar7 + 1 & 0xff;
            if (9 < uVar7) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): BLE send failed for %d times\n");
                }
                else {
                  ble_printk("%s(): BLE send failed for %d times\n","mic_transm_thread",uVar7,
                             BLE_DEBUG);
                }
              }
              uVar7 = 0;
              goto LAB_0003355a;
            }
          }
          else {
            uVar8 = uVar8 + 1 & 0xffff;
          }
          sleep(0x14);
        }
        printk("Flash read failed! %d\n");
        local_f4 = CONCAT11(0xca,(byte)uVar8);
        goto LAB_0003354c;
      }
    }
    else {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s():  [%s] device not ready.\n");
        }
        else {
          ble_printk("%s():  [%s] device not ready.\n","mic_transm_thread","mx25r6435f@0",BLE_DEBUG)
          ;
        }
      }
      local_f4 = 0xca00;
LAB_0003354c:
      pGVar4 = __get_dashboard_state();
      (**(code **)&pGVar4->field_0x788)(&local_f8,10);
    }
LAB_0003355a:
    memset(&local_f8,0,0xce);
    uVar5 = extraout_r1_00;
  } while( true );
}


