/*
 * Function: send_dmic_msg
 * Entry:    0001a094
 * Prototype: int __stdcall send_dmic_msg(int param_1)
 */


/* WARNING: Restarted to delay deadcode elimination for space: ram */

int send_dmic_msg(int param_1)

{
  longlong lVar1;
  dword dVar2;
  int iVar3;
  GlassesState *pGVar4;
  int iVar5;
  uint uVar6;
  ulonglong uVar7;
  undefined4 local_e4;
  undefined1 auStack_e0 [200];
  
  local_e4 = 0;
  memset(auStack_e0,0,199);
  local_e4 = CONCAT31(local_e4._1_3_,0xf1);
  do {
    local_e4._0_2_ = CONCAT11(DAT_20010dbb,(undefined1)local_e4);
    dVar2 = __get_dmic_num_messages();
    if (dVar2 == 0) {
      return 0;
    }
    iVar3 = dequeue_dmic((void *)((int)&local_e4 + 2));
    if (iVar3 != 0) {
      return iVar3;
    }
    iVar3 = (**(code **)(param_1 + 0xc))(&local_e4,0xca);
    if (iVar3 < 0) {
      pGVar4 = __get_dashboard_state();
      if (pGVar4->field_0xd5 == '\x06') {
        if (DAT_20007f34 < 100) {
          DAT_20007f34 = DAT_20007f34 + 1;
        }
        DAT_20007f38 = 0;
      }
      else {
        DAT_20007f38 = DAT_20007f38 + 1;
        DAT_20007f34 = 0;
      }
      if (9 < DAT_20007f38) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): BLE send failed for %d times\n");
          }
          else {
            ble_printk("%s(): BLE send failed for %d times\n","send_dmic_msg",DAT_20007f38,BLE_DEBUG
                      );
          }
        }
        DAT_20007f38 = 0;
        pGVar4 = __get_dashboard_state();
        FUN_0007ff66((int)pGVar4,1);
        return iVar3;
      }
    }
    else if (0 < DAT_20007f38) {
      DAT_20007f38 = DAT_20007f38 + -1;
    }
    DAT_20007f3c = DAT_20007f3c + 1;
    if (9 < DAT_20007f3c) {
      DAT_20007f3c = 0;
      uVar7 = sys_clock_tick_get();
      DAT_20007f40 = DAT_20007f40 + 1;
      if (0 < LOG_LEVEL) {
        lVar1 = (uVar7 & 0xffffffff) * 1000;
        uVar6 = (uint)lVar1;
        iVar3 = DAT_20007f40 * 10;
        uVar6 = uVar6 + 0x7fff >> 0xf |
                ((int)(uVar7 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
                (uint)(0xffff8000 < uVar6)) * 0x20000;
        if (BLE_DEBUG == 0) {
          pGVar4 = __get_dashboard_state();
          iVar5 = DAT_20007f34;
          if (pGVar4->field_0xd5 != '\x06') {
            iVar5 = DAT_20007f38;
          }
          printk("%s(): time %d dmic_send_count %d send_fail_count %d\n","send_dmic_msg",uVar6,iVar3
                 ,iVar5);
        }
        else {
          __get_dashboard_state();
          ble_printk("%s(): time %d dmic_send_count %d send_fail_count %d\n","send_dmic_msg",uVar6,
                     iVar3);
        }
      }
    }
    DAT_20010dbb = DAT_20010dbb + 1;
  } while ((DAT_20010dbb & 3) != 0);
  return 0;
}


