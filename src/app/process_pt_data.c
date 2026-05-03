/*
 * Function: process_pt_data
 * Entry:    000346f8
 * Prototype: undefined4 __stdcall process_pt_data(undefined4 param_1)
 */


undefined4 process_pt_data(undefined4 param_1)

{
  int iVar1;
  char *fmt;
  st25dv_context *psVar2;
  uint uVar3;
  uint extraout_r2;
  byte *pbVar4;
  byte *extraout_r3;
  undefined4 uVar5;
  uint local_28;
  uint local_24;
  undefined *local_20;
  byte *local_1c [2];
  
  if ((DAT_2000242c == 2) ||
     (((psVar2 = DAT_20002424, DAT_2000242c == 0 || (psVar2 = DAT_20002428, DAT_2000242c == 1)) &&
      (psVar2 == (st25dv_context *)0x0)))) {
    printk("comm para is error\n");
    uVar5 = 0xffffffff;
  }
  else {
    local_28 = 0;
    local_24 = 0;
    local_20 = &DAT_2001acc4;
    local_1c[0] = &DAT_2001adc4;
    FUN_00032158();
    psVar2 = DAT_20002424;
    if (DAT_2000242c != 0) {
      psVar2 = DAT_20002428;
    }
    iVar1 = FUN_000805f2((uint)DAT_2000242c,psVar2,&local_20,&local_24);
    if (iVar1 == 0) {
      iVar1 = process_pt_protocol((uint)DAT_2000242c,&DAT_2001acc4,local_24 & 0xff,(int *)local_1c,
                                  (byte *)&local_28,param_1);
      if (iVar1 == 0) {
        psVar2 = DAT_20002424;
        if (DAT_2000242c != 0) {
          psVar2 = DAT_20002428;
        }
        iVar1 = comm_write((uint)DAT_2000242c,psVar2,local_1c[0],local_28 & 0xff);
        if (iVar1 == 0) {
          FUN_00032164();
          if (local_1c[0][9] == 0x80) {
            sleep(1000);
            local_1c[0][9] = 0;
            FUN_00032158();
            comm_write((uint)DAT_2000242c,DAT_20002424,local_1c[0],local_28 & 0xff);
            FUN_00032164();
          }
          pbVar4 = local_1c[0];
          if (DAT_2000242c != 0) {
            pbVar4 = local_1c[0] + 4;
          }
          uVar3 = (uint)*pbVar4;
          uVar5 = 0;
          if (uVar3 == 0x1b) {
            if (pbVar4[8] != 0) {
              erase_audio_buffer();
            }
          }
          else if (uVar3 == 0x13) {
            if (((pbVar4[4] & 0xfb) == 0) && (iVar1 = __enable_charger(), iVar1 != 0)) {
              uVar5 = 0xfffffffb;
            }
          }
          else {
            if (uVar3 != 6) {
              if (uVar3 != 0xb) goto LAB_0003486c;
              if (LOG_LEVEL < 1) goto LAB_0003485e;
              fmt = "%s(): sys reboot because process_pt_data cmd PTP_DEVICE_RESTART\n";
              uVar5 = 0xb;
              do {
                if (BLE_DEBUG == 0) {
                  printk(fmt);
                }
                else {
                  ble_printk(fmt,"process_pt_data",uVar5,BLE_DEBUG);
                }
LAB_0003485e:
                do {
                  while( true ) {
                    sleep(300);
                    sys_reboot(1);
                    uVar3 = extraout_r2;
                    pbVar4 = extraout_r3;
LAB_0003486c:
                    if (uVar3 != 0x3c) break;
                    if (pbVar4[4] != 0) {
                      return 0;
                    }
                    if (0 < LOG_LEVEL) {
                      if (BLE_DEBUG == 0) {
                        printk("%s(): sys reboot because process_pt_data cmd %d and ACK_SUCC\n");
                      }
                      else {
                        ble_printk("%s(): sys reboot because process_pt_data cmd %d and ACK_SUCC\n",
                                   "process_pt_data",0x3c,BLE_DEBUG);
                      }
                    }
                  }
                  if (uVar3 != 1) {
                    return 0;
                  }
                  if (pbVar4[4] != 0) {
                    return 0;
                  }
                } while (LOG_LEVEL < 1);
                fmt = "%s(): sys reboot because process_pt_data cmd ACK_SUCC\n";
                uVar5 = 1;
              } while( true );
            }
            if (pbVar4[2] == 2) {
              DAT_20019a62 = 1;
              set_box_status(LID_CLOSED,true);
              FUN_0002c6f4(10000);
            }
            else {
              printk("enter into long trip \n");
              sleep(10000);
              change_work_mode(7);
            }
          }
        }
        else {
          printk("comm_write is failed\n");
          uVar5 = 0xfffffffc;
          FUN_00032164();
        }
      }
      else {
        printk("process_pt_protocol is failed\n");
        uVar5 = 0xfffffffd;
        FUN_00032164();
      }
    }
    else {
      FUN_00032164();
      uVar5 = 0xfffffffe;
    }
  }
  return uVar5;
}


