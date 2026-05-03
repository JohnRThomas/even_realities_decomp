/*
 * Function: subcontracing_send_data_pkcs7
 * Entry:    00023a00
 * Prototype: undefined4 __stdcall subcontracing_send_data_pkcs7(int param_1, int param_2, undefined1 param_3, undefined * param_4)
 */


undefined4
subcontracing_send_data_pkcs7(int param_1,int param_2,undefined1 param_3,undefined *param_4)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int iVar9;
  uint uVar10;
  size_t n;
  int iVar11;
  int iVar12;
  undefined1 local_3c [3];
  undefined4 uStack_39;
  undefined1 local_35 [17];
  undefined4 *puVar8;
  
  uVar10 = param_2 / 0x11;
  _local_3c = 0;
  memset((void *)((int)&uStack_39 + 1),0,0x10);
  iVar9 = uVar10 + 1;
  n = param_2 % 0x11;
  local_3c._0_2_ = CONCAT11((char)iVar9,param_3);
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): integer_num: %d, tail_len: %d, raw_data_len: %d\n",
             "subcontracing_send_data_pkcs7",iVar9,n,param_2);
    }
    else {
      ble_printk("%s(): integer_num: %d, tail_len: %d, raw_data_len: %d\n",
                 "subcontracing_send_data_pkcs7",iVar9,n);
    }
  }
  iVar12 = 0;
  while( true ) {
    iVar1 = LOG_LEVEL;
    iVar11 = iVar12 + 1;
    if ((int)uVar10 <= iVar12) break;
    puVar6 = (undefined4 *)(iVar12 * 0x11 + param_1);
    local_3c = (undefined1  [3])CONCAT12((char)iVar12,local_3c._0_2_);
    puVar3 = (undefined4 *)(local_3c + 3);
    puVar7 = puVar6;
    do {
      puVar8 = puVar7 + 1;
      puVar4 = puVar3 + 1;
      *puVar3 = *puVar7;
      puVar3 = puVar4;
      puVar7 = puVar8;
    } while (puVar8 != puVar6 + 4);
    *(undefined1 *)puVar4 = *(undefined1 *)puVar8;
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk(s__s_________d__d_000a1ab2,"subcontracing_send_data_pkcs7",iVar11,iVar9);
      }
      else {
        ble_printk(s__s_________d__d_000a1ab2,"subcontracing_send_data_pkcs7",iVar11,iVar9);
      }
    }
    FUN_0004d44c("body",(int)local_3c,0x14);
    (*(code *)param_4)(local_3c);
    iVar12 = iVar11;
  }
  uVar5 = uVar10 & ~((int)uVar10 >> 0x1f);
  iVar12 = uVar5 + 1;
  local_3c = (undefined1  [3])CONCAT12((char)uVar5,local_3c._0_2_);
  if (n == 0) {
    memset(local_3c + 3,0x11,0x11);
    if (iVar1 < 3) goto LAB_00023b1a;
    if (BLE_DEBUG == 0) {
      pcVar2 = s__s____PKCS_7_____d__d_000a1acd;
LAB_00023b16:
      printk(pcVar2,"subcontracing_send_data_pkcs7",iVar12,iVar9);
      goto LAB_00023b1a;
    }
    pcVar2 = s__s____PKCS_7_____d__d_000a1acd;
  }
  else {
    memset(local_3c + n + 3,0x11 - n,0x11 - n);
    memcpy(local_3c + 3,(void *)(uVar10 * 0x11 + param_1),n);
    if (iVar1 < 3) goto LAB_00023b1a;
    if (BLE_DEBUG == 0) {
      pcVar2 = s__s____PKCS_7__tail___d__d_000a1aee;
      goto LAB_00023b16;
    }
    pcVar2 = s__s____PKCS_7__tail___d__d_000a1aee;
  }
  ble_printk(pcVar2,"subcontracing_send_data_pkcs7",iVar12,iVar9);
LAB_00023b1a:
  FUN_0004d44c("tail",(int)local_3c,0x14);
  if (2 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): total-size:%d\n");
    }
    else {
      ble_printk("%s(): total-size:%d\n","subcontracing_send_data_pkcs7",param_2,BLE_DEBUG);
    }
  }
  (*(code *)param_4)(local_3c);
  return 0;
}


