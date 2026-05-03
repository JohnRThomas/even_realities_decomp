/*
 * Function: send_dmic_msg
 * Entry:    0001a094
 * Prototype: int __stdcall send_dmic_msg(int param_1)
 */


/* WARNING: Restarted to delay deadcode elimination for space: ram */

int send_dmic_msg(int param_1)

{
  longlong lVar1;
  int iVar2;
  GlassesState *pGVar3;
  int iVar4;
  uint uVar5;
  ulonglong uVar6;
  undefined4 local_e4;
  undefined1 auStack_e0 [200];
  
  local_e4 = 0;
  memset(auStack_e0,0,199);
  local_e4 = CONCAT31(local_e4._1_3_,0xf1);
  do {
    local_e4._0_2_ = CONCAT11(DAT_20010dbb,(undefined1)local_e4);
    iVar2 = FUN_0003018c();
    if (iVar2 == 0) {
      return 0;
    }
    iVar2 = dequeue_dmic((void *)((int)&local_e4 + 2));
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar2 = (**(code **)(param_1 + 0xc))(&local_e4,0xca);
    if (iVar2 < 0) {
      pGVar3 = __get_dashboard_state();
      if (pGVar3->field_0xd5 == '\x06') {
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
        pGVar3 = __get_dashboard_state();
        FUN_0007ff66((int)pGVar3,1);
        return iVar2;
      }
    }
    else if (0 < DAT_20007f38) {
      DAT_20007f38 = DAT_20007f38 + -1;
    }
    DAT_20007f3c = DAT_20007f3c + 1;
    if (9 < DAT_20007f3c) {
      DAT_20007f3c = 0;
      uVar6 = sys_clock_tick_get();
      DAT_20007f40 = DAT_20007f40 + 1;
      if (0 < LOG_LEVEL) {
        lVar1 = (uVar6 & 0xffffffff) * 1000;
        uVar5 = (uint)lVar1;
        iVar2 = DAT_20007f40 * 10;
        uVar5 = uVar5 + 0x7fff >> 0xf |
                ((int)(uVar6 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
                (uint)(0xffff8000 < uVar5)) * 0x20000;
        if (BLE_DEBUG == 0) {
          pGVar3 = __get_dashboard_state();
          iVar4 = DAT_20007f34;
          if (pGVar3->field_0xd5 != '\x06') {
            iVar4 = DAT_20007f38;
          }
          printk("%s(): time %d dmic_send_count %d send_fail_count %d\n","send_dmic_msg",uVar5,iVar2
                 ,iVar4);
        }
        else {
          __get_dashboard_state();
          ble_printk("%s(): time %d dmic_send_count %d send_fail_count %d\n","send_dmic_msg",uVar5,
                     iVar2);
        }
      }
    }
    DAT_20010dbb = DAT_20010dbb + 1;
  } while ((DAT_20010dbb & 3) != 0);
  return 0;
}


