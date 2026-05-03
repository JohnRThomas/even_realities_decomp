/*
 * Function: parse_receiver_pack_pkcs7
 * Entry:    00019e90
 * Prototype: undefined4 __stdcall parse_receiver_pack_pkcs7(int param_1, byte * param_2, uint param_3)
 */


undefined4 parse_receiver_pack_pkcs7(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  char *fmt;
  undefined4 uVar4;
  uint uVar5;
  
  if (param_2 == (byte *)0x0) {
    uVar4 = 0xb3;
    fmt = "[%s-%d]error, req is NULL ! \n";
  }
  else {
    if (param_1 != 0) {
      if (param_3 < 3) {
        if (BLE_DEBUG != 0) {
          ble_printk("[%s-%d]error, req_len is %d, too short ! \n","parse_receiver_pack_pkcs7",0xbe,
                     param_3);
          return 0xca;
        }
        printk("[%s-%d]error, req_len is %d, too short ! \n","parse_receiver_pack_pkcs7",0xbe,
               param_3,param_1,param_2);
        return 0xca;
      }
      bVar1 = param_2[2];
      uVar5 = (uint)*param_2;
      bVar2 = param_2[1];
      if (bVar1 == 0) {
        DAT_2000e0dc = (ushort)bVar1;
        DAT_20010dba = *param_2;
      }
      if (DAT_20010dba != uVar5) {
        if (BLE_DEBUG != 0) {
          ble_printk("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n",
                     "parse_receiver_pack_pkcs7",0xd3,uVar5);
          return 0xca;
        }
        printk("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n","parse_receiver_pack_pkcs7",
               0xd3,uVar5,(uint)DAT_20010dba,param_2);
        return 0xca;
      }
      sVar3 = (short)param_3 + (DAT_2000e0dc - 3);
      memcpy((void *)(param_1 + (uint)DAT_2000e0dc),param_2 + 3,param_3 - 3);
      if ((uint)bVar1 == bVar2 - 1) {
        DAT_2000e0dc = sVar3;
        return 0xc9;
      }
      DAT_2000e0dc = sVar3;
      return 0xcb;
    }
    uVar4 = 0xb8;
    fmt = "[%s-%d]error, origin_data is NULL ! \n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt);
  }
  else {
    ble_printk(fmt,"parse_receiver_pack_pkcs7",uVar4,BLE_DEBUG);
  }
  return 0xca;
}


