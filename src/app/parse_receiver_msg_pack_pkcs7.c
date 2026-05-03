/*
 * Function: parse_receiver_msg_pack_pkcs7
 * Entry:    00019f64
 * Prototype: undefined4 __stdcall parse_receiver_msg_pack_pkcs7(char * param_1, byte * param_2, uint param_3)
 */


undefined4 parse_receiver_msg_pack_pkcs7(char *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  char *pcVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 extraout_r2;
  uint uVar8;
  
  if (param_2 == (byte *)0x0) {
    uVar6 = 0xe7;
    pcVar4 = "[%s-%d]error, req is NULL ! \n";
  }
  else {
    if (param_1 != (char *)0x0) {
      if (param_3 < 4) {
        if (BLE_DEBUG != 0) {
          ble_printk("[%s-%d]error, req_len is %d, too short ! \n","parse_receiver_msg_pack_pkcs7",
                     0xf2,param_3);
          return 0xca;
        }
        printk("[%s-%d]error, req_len is %d, too short ! \n","parse_receiver_msg_pack_pkcs7",0xf2,
               param_3,param_1,param_2,param_3);
        return 0xca;
      }
      bVar2 = param_2[3];
      uVar7 = (uint)*param_2;
      uVar8 = (uint)param_2[1];
      bVar1 = param_2[2];
      if (bVar2 == 0) {
        DAT_2000e0da = (ushort)bVar2;
        DAT_2000e0d8 = (ushort)param_2[1];
        DAT_20010db9 = *param_2;
      }
      uVar5 = (uint)DAT_20010db9;
      if (uVar5 == uVar7) {
        uVar5 = (uint)DAT_2000e0d8;
        if (uVar8 == uVar5) {
          sVar3 = DAT_2000e0da - 4;
          memcpy(param_1 + DAT_2000e0da,param_2 + 4,param_3 - 4);
          DAT_2000e0da = (short)param_3 + sVar3;
          if ((uint)bVar2 != bVar1 - 1) {
            return 0xcb;
          }
          if (BLE_DEBUG == 0) {
            printk("origin_data is %s \n");
          }
          else {
            ble_printk("origin_data is %s \n",param_1,extraout_r2,BLE_DEBUG);
          }
          return 0xc9;
        }
        uVar6 = 0x112;
        if (BLE_DEBUG == 0) {
          pcVar4 = "[%s-%d]error, curMsgId is %d, but parseMsgId is %d ! \n";
          goto LAB_0001a006;
        }
        pcVar4 = "[%s-%d]error, curMsgId is %d, but parseMsgId is %d ! \n";
      }
      else {
        uVar8 = uVar7;
        if (BLE_DEBUG == 0) {
          uVar6 = 0x10c;
          pcVar4 = "[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n";
LAB_0001a006:
          printk(pcVar4,"parse_receiver_msg_pack_pkcs7",uVar6,uVar8,uVar5,param_2,param_3);
          return 0xca;
        }
        uVar6 = 0x10c;
        pcVar4 = "[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n";
      }
      ble_printk(pcVar4,"parse_receiver_msg_pack_pkcs7",uVar6,uVar8);
      return 0xca;
    }
    uVar6 = 0xec;
    pcVar4 = "[%s-%d]error, origin_data is NULL ! \n";
  }
  if (BLE_DEBUG == 0) {
    printk(pcVar4);
  }
  else {
    ble_printk(pcVar4,"parse_receiver_msg_pack_pkcs7",uVar6,BLE_DEBUG);
  }
  return 0xca;
}


