/*
 * Function: parse_receiver_pack_pkcs7
 * Entry:    00019e90
 * Prototype: undefined4 __stdcall parse_receiver_pack_pkcs7(int param_1, byte * param_2, uint param_3)
 */


undefined4 parse_receiver_pack_pkcs7(int param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  short sVar4;
  char *fmt;
  undefined4 uVar5;
  
  if (param_2 == (byte *)0x0) {
    uVar5 = 0xb3;
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
      bVar2 = *param_2;
      bVar3 = param_2[1];
      if (bVar1 == 0) {
        DAT_2000e0dc = (ushort)bVar1;
        DAT_20010dba = bVar2;
      }
      if ((uint)DAT_20010dba != (uint)bVar2) {
        if (BLE_DEBUG != 0) {
          ble_printk("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n",
                     "parse_receiver_pack_pkcs7");
          return 0xca;
        }
        printk("[%s-%d]error, curCmd is %d, but parseCmd is %d ! \n","parse_receiver_pack_pkcs7",
               0xd3,(uint)bVar2,(uint)DAT_20010dba,param_2);
        return 0xca;
      }
      sVar4 = (short)param_3 + (DAT_2000e0dc - 3);
      memcpy((void *)(param_1 + (uint)DAT_2000e0dc),param_2 + 3,param_3 - 3);
      if ((uint)bVar1 == bVar3 - 1) {
        DAT_2000e0dc = sVar4;
        return 0xc9;
      }
      DAT_2000e0dc = sVar4;
      return 0xcb;
    }
    uVar5 = 0xb8;
    fmt = "[%s-%d]error, origin_data is NULL ! \n";
  }
  if (BLE_DEBUG == 0) {
    printk(fmt,"parse_receiver_pack_pkcs7",uVar5,0,param_1,param_2);
  }
  else {
    ble_printk(fmt);
  }
  return 0xca;
}


