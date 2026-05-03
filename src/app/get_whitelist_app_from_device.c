/*
 * Function: get_whitelist_app_from_device
 * Entry:    00036b34
 * Prototype: undefined __stdcall get_whitelist_app_from_device(int param_1, int param_2)
 */


void get_whitelist_app_from_device(int param_1,int param_2)

{
  char cVar1;
  char *buf;
  uint uVar2;
  char *s;
  int iVar3;
  char *pcVar4;
  code *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint n;
  uint uVar9;
  char *d;
  char *pcVar5;
  
  iVar3 = param_1;
  buf = malloc(0x15e3);
  if (buf == (char *)0x0) {
    if (BLE_DEBUG != 0) {
      ble_printk("[%s-%d] buf is NULL \n","get_whitelist_app_from_device",0x237,BLE_DEBUG);
      return;
    }
    printk("[%s-%d] buf is NULL \n");
    return;
  }
  *(undefined1 *)(param_2 + 1) = 0x6a;
  memset(buf,0,0x15e3);
  uVar2 = convert_app_whitelist_to_json(buf);
  if (uVar2 != 0) {
    uVar9 = 0;
    n = uVar2 % 0x11;
    *(char *)(param_2 + 1) = (char)(uVar2 / 0x11) + '\x01';
    d = (char *)(param_2 + 3);
    while( true ) {
      s = buf + uVar9 * 0x11;
      if (uVar9 == uVar2 / 0x11) break;
      *(char *)(param_2 + 2) = (char)uVar9;
      pcVar5 = s;
      pcVar7 = d;
      do {
        pcVar4 = pcVar5 + 4;
        pcVar8 = pcVar7 + 4;
        *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
        pcVar5 = pcVar4;
        pcVar7 = pcVar8;
      } while (pcVar4 != s + 0x10);
      cVar1 = *pcVar4;
      *pcVar8 = cVar1;
      (**(code **)(param_1 + 0xc))(param_2,0x14,cVar1,*(code **)(param_1 + 0xc),iVar3);
      uVar9 = uVar9 + 1;
    }
    *(char *)(param_2 + 2) = (char)uVar9;
    if (n == 0) {
      memset(d,0,0x11);
      iVar3 = 3;
      pcVar6 = *(code **)(param_1 + 0xc);
    }
    else {
      iVar3 = n + 3;
      memcpy(d,s,n);
      memset((void *)(param_2 + iVar3),0,0x11 - n & 0xff);
      pcVar6 = *(code **)(param_1 + 0xc);
    }
    (*pcVar6)(param_2,iVar3);
    free(buf);
    return;
  }
  if (BLE_DEBUG != 0) {
    ble_printk("[%s-%d] total_len is %d \n","get_whitelist_app_from_device",0x23f,0);
    return;
  }
  printk("[%s-%d] total_len is %d \n","get_whitelist_app_from_device",0x23f);
  return;
}


