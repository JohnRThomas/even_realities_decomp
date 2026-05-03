/*
 * Function: post_notification_cmd_process
 * Entry:    00034f00
 * Prototype: undefined __stdcall post_notification_cmd_process(int param_1, undefined1 * param_2, byte * param_3)
 */


void post_notification_cmd_process(int param_1,undefined1 *param_2,byte *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_r2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 local_b4;
  undefined1 auStack_b0 [16];
  byte abStack_a0 [132];
  
  if (((param_1 == 0) || (param_2 == (undefined1 *)0x0)) || (param_3 == (byte *)0x0)) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG != 0) {
        ble_printk("%s(): input param invalid !\n","post_notification_cmd_process",param_3,BLE_DEBUG
                  );
        return;
      }
      printk("%s(): input param invalid !\n");
      return;
    }
  }
  else {
    puVar3 = *(undefined1 **)(param_1 + 0x10);
    local_b4 = 0;
    memset(auStack_b0,0,0x10);
    local_b4 = CONCAT31(local_b4._1_3_,*param_2);
    *puVar3 = *param_2;
    puVar3[1] = param_2[1];
    *(uint *)(param_1 + 0x14) = *(ushort *)(puVar3 + 2) + 4;
    uVar4 = (uint)(byte)puVar3[1];
    if ((uVar4 == 2) || (uVar4 == 4)) {
      *(undefined2 *)(puVar3 + 2) = 0x1b4;
      memcpy(puVar3 + 4,param_3,0x1b4);
      if (2 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(s__s____ANCS_____master__source__d_000a9b92);
        }
        else {
          ble_printk(s__s____ANCS_____master__source__d_000a9b92,"post_notification_cmd_process",
                     uVar4,BLE_DEBUG);
        }
      }
      FUN_00019d14(param_1,abStack_a0,8);
    }
    else {
      if (DAT_20008788 == (char *)0x0) {
        DAT_20008788 = malloc(0x800);
        if (DAT_20008788 == (char *)0x0) {
          if (BLE_DEBUG == 0) {
            printk("[%s-%d] malloc failed !!\n");
          }
          else {
            ble_printk("[%s-%d] malloc failed !!\n","post_notification_cmd_process",0x19f,BLE_DEBUG)
            ;
          }
        }
        else {
          memset(DAT_20008788,0,0x800);
        }
      }
      if (DAT_20008788 != (char *)0x0) {
        iVar2 = parse_receiver_msg_pack_pkcs7(DAT_20008788,param_3,(uint)(byte)puVar3[2]);
        uVar1 = local_b4;
        local_b4._0_2_ = CONCAT11((char)iVar2,(undefined1)local_b4);
        local_b4._3_1_ = SUB41(uVar1,3);
        local_b4._0_3_ = CONCAT12(param_3[1],(undefined2)local_b4);
        if (iVar2 == 0xc9) {
          parse_ncs_notification(DAT_20008788,(undefined4 *)(puVar3 + 4));
          if (2 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): ncs data receive okay !\n\n");
            }
            else {
              ble_printk("%s(): ncs data receive okay !\n\n","post_notification_cmd_process",
                         extraout_r2,BLE_DEBUG);
            }
          }
          *(undefined2 *)(puVar3 + 2) = 0x1b4;
          FUN_00019d14(param_1,abStack_a0,8);
          local_b4._0_2_ = CONCAT11(0xc9,(undefined1)local_b4);
          free(DAT_20008788);
          DAT_20008788 = (char *)0x0;
        }
      }
      (**(code **)(param_1 + 0xc))(&local_b4,0x14);
    }
  }
  return;
}


