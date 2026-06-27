/*
 * Function: display_thread_handler
 * Entry:    0004c460
 * Prototype: undefined __stdcall display_thread_handler(int param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void display_thread_handler(int param_1)

{
  byte bVar1;
  longlong lVar2;
  undefined1 uVar3;
  undefined4 extraout_r0;
  int iVar4;
  GlassesState *pGVar5;
  undefined4 extraout_r1;
  uint uVar6;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar7;
  uint uVar8;
  char *pcVar9;
  k_timeout_t timeout;
  byte local_39;
  byte local_38 [2];
  short local_36;
  undefined4 local_34;
  
  pcVar9 = (char *)(param_1 + 0xd4);
  memset(local_38,0,0x18);
  k_timer_init((k_timer *)&DAT_20004ec0,&LAB_00080fc2_1,(k_timer_stop_t)0x0);
  FUN_000452f0(param_1 + 0xb90);
  _DAT_2001e1bb = 0;
switchD_0004c664_default:
  do {
    while ((*(char *)(param_1 + 1) == '\x01' || (*(char *)(param_1 + 1) == '\b'))) {
      z_impl_k_sleep((k_timeout_t)0x28000);
    }
    memset(local_38,0,0x18);
    local_39 = 0;
    lVar2 = (longlong)(int)(DAT_20002564 & ~((int)DAT_20002564 >> 0x1f)) * 0x8000 + 999;
    __aeabi_uldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),1000,0);
    timeout.ticks._4_4_ = extraout_r1;
    timeout.ticks._0_4_ = extraout_r0;
    iVar4 = z_impl_k_msgq_get((k_msgq *)&DAT_20003a64,local_38,timeout);
    if (iVar4 == 0) {
      local_39 = 1;
    }
    else if ((iVar4 == -0x23) || (iVar4 == -0xb)) {
      local_39 = 0;
    }
    if (DAT_2001e1bb == '\x01') {
      uVar8 = (uint)local_39;
      if (local_39 == 1) {
        if (local_38[0] == 2) {
          if (local_36 == 0) {
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
          }
          else {
            if (local_36 != 2) goto switchD_0004c664_default;
            if ((local_34 & 0xff) != 1) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): screen ID message parampter error!\n");
                }
                else {
                  ble_printk("%s(): screen ID message parampter error!\n","display_thread_handler",2
                             ,BLE_DEBUG);
                }
              }
              goto switchD_0004c664_default;
            }
            uVar6 = (uint)local_34._1_1_;
            uVar8 = 1;
          }
        }
        else {
          switch(local_38[0]) {
          case 3:
            _DAT_2001e1bb = CONCAT11(DAT_2001e1bc,2);
            if (local_36 == 0) {
LAB_0004c678:
              bVar1 = *(byte *)(param_1 + 0xd5);
LAB_0004c694:
              display_reflash_handler(param_1,(uint)bVar1,pcVar9,2);
            }
            else if (local_36 == 2) {
              bVar1 = local_34._1_1_;
              if ((local_34 & 0xff) != 1) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): screen ID message parampter error!\n");
                  }
                  else {
                    ble_printk("%s(): screen ID message parampter error!\n","display_thread_handler"
                               ,local_34 & 0xff,BLE_DEBUG);
                  }
                }
                goto LAB_0004c678;
              }
              goto LAB_0004c694;
            }
            FUN_0004c404();
            goto LAB_0004c69e;
          case 4:
            DAT_2000aa74 = local_34;
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
            uVar8 = 3;
            break;
          case 5:
            uVar8 = 4;
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
            break;
          case 6:
            uVar8 = 5;
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
            break;
          case 7:
            uVar8 = 6;
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
            break;
          case 8:
            uVar8 = 7;
            uVar6 = (uint)*(byte *)(param_1 + 0xd5);
            break;
          default:
            goto switchD_0004c664_default;
          }
        }
      }
      else {
        if (*(char *)(param_1 + 0xd5) == '\0') {
          if (*(char *)(param_1 + 0xd5) == '\0') {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk(
                      "%s(): When the UI exit command is not received in IDLE state, the UI exit is performed by itself\n"
                      );
              }
              else {
                ble_printk("%s(): When the UI exit command is not received in IDLE state, the UI exit is performed by itself\n"
                           ,"display_thread_handler",(uint)local_39,BLE_DEBUG);
              }
            }
            FUN_00080dbc(0);
            FUN_0004c404();
            _DAT_2001e1bb = 0;
          }
          goto switchD_0004c664_default;
        }
        uVar8 = 0;
        uVar6 = (uint)*(byte *)(param_1 + 0xd5);
      }
      display_reflash_handler(param_1,uVar6,pcVar9,uVar8);
      goto switchD_0004c664_default;
    }
    if (DAT_2001e1bb == '\x02') {
LAB_0004c69e:
      FUN_00080dbc(0);
      FUN_0004c404();
      _DAT_2001e1bb = 0;
      goto LAB_0004c558;
    }
    if (DAT_2001e1bb != '\0') {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): unknow display thread state\n");
        }
        else {
          ble_printk("%s(): unknow display thread state\n","display_thread_handler",extraout_r2,
                     BLE_DEBUG);
        }
      }
      display_reflash_handler(param_1,(uint)*(byte *)(param_1 + 0xd5),pcVar9,2);
      goto LAB_0004c69e;
    }
  } while (local_39 != 1);
  if (local_38[0] == 2) {
    uVar7 = extraout_r2;
    if ((*(char *)(param_1 + 0xd5) == '\x10') &&
       (pGVar5 = __get_dashboard_state(), uVar7 = extraout_r2_00,
       **(byte **)&pGVar5->field_0x1010 < 0xc)) {
      FUN_00080dbc(0);
      uVar7 = extraout_r2_01;
    }
    if (local_36 == 0) {
      DAT_2001e1bc = *(undefined1 *)(param_1 + 0xd5);
      display_reflash_handler(param_1,(uint)*(byte *)(param_1 + 0xd5),pcVar9,1);
      _DAT_2001e1bb = CONCAT11(DAT_2001e1bc,1);
    }
    else if (local_36 == 2) {
      uVar3 = (undefined1)local_34;
      if ((local_34 & 0xff) == 1) {
        DAT_2001e1bc = local_34._1_1_;
        display_reflash_handler(param_1,(uint)local_34._1_1_,pcVar9,1);
        _DAT_2001e1bb = CONCAT11(DAT_2001e1bc,uVar3);
      }
      else if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ---screen ID message parampter error!\n");
        }
        else {
          ble_printk("%s(): ---screen ID message parampter error!\n","display_thread_handler",uVar7,
                     BLE_DEBUG);
        }
      }
    }
    goto LAB_0004c558;
  }
  if (local_38[0] != 3) goto switchD_0004c664_default;
  _DAT_2001e1bb = _DAT_2001e1bb & 0xff;
  if (local_36 == 0) {
LAB_0004c5b8:
    bVar1 = *(byte *)(param_1 + 0xd5);
  }
  else {
    if (local_36 != 2) goto LAB_0004c558;
    bVar1 = local_34._1_1_;
    if ((local_34 & 0xff) != 1) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exit .screen ID message parampter error!\n");
        }
        else {
          ble_printk("%s(): exit .screen ID message parampter error!\n","display_thread_handler",
                     local_34 & 0xff,BLE_DEBUG);
        }
      }
      goto LAB_0004c5b8;
    }
  }
  display_reflash_handler(param_1,(uint)bVar1,pcVar9,2);
LAB_0004c558:
  FUN_0004c43c();
  goto switchD_0004c664_default;
}


