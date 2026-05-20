/*
 * Function: write_whitelist_to_flash
 * Entry:    0002478c
 * Prototype: int __stdcall write_whitelist_to_flash(int param_1, int param_2, char * param_3)
 */


int write_whitelist_to_flash(int param_1,int param_2,char *param_3)

{
  int iVar1;
  size_t sVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (BLE_DEBUG == 0) {
    printk("size is %d\n");
  }
  else {
    ble_printk("size is %d\n",param_3,param_3,BLE_DEBUG);
  }
  iVar5 = 0;
  uVar4 = ((uint)param_3 >> 0xc) + 1 & 0xff;
  iVar6 = uVar4 - 1;
  for (uVar3 = 0; (uVar3 & 0xff) < uVar4; uVar3 = uVar3 + 1) {
    sVar2 = (int)(short)((short)param_3 + (short)iVar6 * -0x1000);
    if ((int)uVar3 < iVar6) {
      sVar2 = 0x1000;
    }
    iVar1 = flash_settings_write_and_verify
                      (param_1 + uVar3 * 0x1000,(void *)(param_2 + uVar3 * 0x1000),sVar2);
    iVar5 = iVar5 + iVar1;
  }
  return iVar5;
}


