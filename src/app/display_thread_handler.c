/*
 * Function: display_thread_handler
 * Entry:    0004c460
 * Prototype: undefined __stdcall display_thread_handler(GlassesState * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void display_thread_handler(GlassesState *param_1)

{
  byte bVar1;
  longlong lVar2;
  bool bVar3;
  undefined1 uVar4;
  undefined4 extraout_r0;
  int iVar5;
  GlassesState *pGVar6;
  undefined4 extraout_r1;
  uint new_screen_id;
  uint uVar7;
  undefined *puVar8;
  k_timeout_t timeout;
  byte local_38 [2];
  short local_36;
  undefined4 local_34;
  
  puVar8 = param_1->field20_0xc8 + 0xc;
  memset(local_38,0,0x18);
  k_timer_init((k_timer *)&DAT_20004ec0,&LAB_00080fc2_1,(k_timer_stop_t)0x0);
  __set_frame_buffer(&(param_1->jdb_panel_context).__panel_buffer);
  _DAT_2001e1bb = 0;
switchD_0004c664_default:
  do {
    while ((param_1->field_0x1 == '\x01' || (param_1->field_0x1 == '\b'))) {
      z_impl_k_sleep((k_timeout_t)0x28000);
    }
    memset(local_38,0,0x18);
    bVar3 = false;
    lVar2 = (longlong)(int)(_DAT_20002564 & ~((int)_DAT_20002564 >> 0x1f)) * 0x8000 + 999;
    __aeabi_uldivmod((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),1000,0);
    timeout.ticks._4_4_ = extraout_r1;
    timeout.ticks._0_4_ = extraout_r0;
    iVar5 = z_impl_k_msgq_get((k_msgq *)&DAT_20003a64,local_38,timeout);
    if (iVar5 == 0) {
      bVar3 = true;
    }
    else if ((iVar5 == -0x23) || (iVar5 == -0xb)) {
      bVar3 = false;
    }
    if (DAT_2001e1bb == '\x01') {
      if (bVar3) {
        if (local_38[0] == 2) {
          if (local_36 == 0) {
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            uVar7 = 1;
          }
          else {
            if (local_36 != 2) goto switchD_0004c664_default;
            if ((local_34 & 0xff) != 1) {
              if (0 < LOG_LEVEL) {
                if (BLE_DEBUG == 0) {
                  printk("%s(): screen ID message parampter error!\n","display_thread_handler");
                }
                else {
                  ble_printk("%s(): screen ID message parampter error!\n");
                }
              }
              goto switchD_0004c664_default;
            }
            new_screen_id = (uint)local_34._1_1_;
            uVar7 = 1;
          }
        }
        else {
          switch(local_38[0]) {
          case 3:
            _DAT_2001e1bb = CONCAT11(__SCREEN_ID,2);
            if (local_36 == 0) {
LAB_0004c678:
              bVar1 = param_1->field20_0xc8[0xd];
LAB_0004c694:
              display_reflash_handler(param_1,(uint)bVar1,puVar8,2);
            }
            else if (local_36 == 2) {
              bVar1 = local_34._1_1_;
              if ((local_34 & 0xff) != 1) {
                if (0 < LOG_LEVEL) {
                  if (BLE_DEBUG == 0) {
                    printk("%s(): screen ID message parampter error!\n","display_thread_handler");
                  }
                  else {
                    ble_printk("%s(): screen ID message parampter error!\n");
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
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            uVar7 = 3;
            break;
          case 5:
            uVar7 = 4;
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            break;
          case 6:
            uVar7 = 5;
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            break;
          case 7:
            uVar7 = 6;
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            break;
          case 8:
            uVar7 = 7;
            new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
            break;
          default:
            goto switchD_0004c664_default;
          }
        }
      }
      else {
        if (param_1->field20_0xc8[0xd] == '\0') {
          if (param_1->field20_0xc8[0xd] == '\0') {
            if (0 < LOG_LEVEL) {
              if (BLE_DEBUG == 0) {
                printk("%s(): When the UI exit command is not received in IDLE state, the UI exit is performed by itself\n"
                       ,"display_thread_handler");
              }
              else {
                ble_printk(
                          "%s(): When the UI exit command is not received in IDLE state, the UI exit is performed by itself\n"
                          );
              }
            }
            FUN_00080dbc(0);
            FUN_0004c404();
            _DAT_2001e1bb = 0;
          }
          goto switchD_0004c664_default;
        }
        uVar7 = 0;
        new_screen_id = (uint)(byte)param_1->field20_0xc8[0xd];
      }
      display_reflash_handler(param_1,new_screen_id,puVar8,uVar7);
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
          printk("%s(): unknow display thread state\n","display_thread_handler");
        }
        else {
          ble_printk("%s(): unknow display thread state\n");
        }
      }
      display_reflash_handler(param_1,(uint)(byte)param_1->field20_0xc8[0xd],puVar8,2);
      goto LAB_0004c69e;
    }
  } while (!bVar3);
  if (local_38[0] == 2) {
    if ((param_1->field20_0xc8[0xd] == '\x10') &&
       (pGVar6 = __get_dashboard_state(), **(byte **)&pGVar6->field_0x1010 < 0xc)) {
      FUN_00080dbc(0);
    }
    if (local_36 == 0) {
      __SCREEN_ID = param_1->field20_0xc8[0xd];
      display_reflash_handler(param_1,(uint)(byte)param_1->field20_0xc8[0xd],puVar8,1);
      _DAT_2001e1bb = CONCAT11(__SCREEN_ID,1);
    }
    else if (local_36 == 2) {
      uVar4 = (undefined1)local_34;
      if ((local_34 & 0xff) == 1) {
        __SCREEN_ID = local_34._1_1_;
        display_reflash_handler(param_1,(uint)local_34._1_1_,puVar8,1);
        _DAT_2001e1bb = CONCAT11(__SCREEN_ID,uVar4);
      }
      else if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ---screen ID message parampter error!\n","display_thread_handler");
        }
        else {
          ble_printk("%s(): ---screen ID message parampter error!\n");
        }
      }
    }
    goto LAB_0004c558;
  }
  if (local_38[0] != 3) goto switchD_0004c664_default;
  _DAT_2001e1bb = _DAT_2001e1bb & 0xff;
  if (local_36 == 0) {
LAB_0004c5b8:
    bVar1 = param_1->field20_0xc8[0xd];
  }
  else {
    if (local_36 != 2) goto LAB_0004c558;
    bVar1 = local_34._1_1_;
    if ((local_34 & 0xff) != 1) {
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): exit .screen ID message parampter error!\n","display_thread_handler");
        }
        else {
          ble_printk("%s(): exit .screen ID message parampter error!\n");
        }
      }
      goto LAB_0004c5b8;
    }
  }
  display_reflash_handler(param_1,(uint)bVar1,puVar8,2);
LAB_0004c558:
  FUN_0004c43c();
  goto switchD_0004c664_default;
}


