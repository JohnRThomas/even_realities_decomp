/*
 * Function: put_whitelist_app_from_app
 * Entry:    00036d24
 * Prototype: undefined __stdcall put_whitelist_app_from_app(int param_1, undefined4 param_2, byte * param_3, uint param_4, int param_5)
 */


void put_whitelist_app_from_app
               (int param_1,undefined4 param_2,byte *param_3,uint param_4,int param_5)

{
  int iVar1;
  char *fmt;
  
  if (DAT_2000a99c == (char *)0x0) {
    DAT_2000a99c = malloc(0x1800);
    if (DAT_2000a99c == (char *)0x0) {
      if (BLE_DEBUG == 0) {
        printk("[%s-%d] malloc failed !!\n","put_whitelist_app_from_app",0x1ca);
      }
      else {
        ble_printk("[%s-%d] malloc failed !!\n");
      }
    }
    else {
      memset(DAT_2000a99c,0,0x1800);
    }
  }
  if (DAT_2000a99c == (char *)0x0) goto LAB_00036db4;
  iVar1 = parse_receiver_pack_pkcs7((int)DAT_2000a99c,param_3,param_4);
  *(char *)(param_5 + 1) = (char)iVar1;
  if (iVar1 != 0xc9) goto LAB_00036db4;
  iVar1 = __is_the_same_whitelist_app(DAT_2000a99c);
  if (iVar1 == 0) {
    iVar1 = __parse_app_white_list_json(DAT_2000a99c);
    if (iVar1 == 0) {
      fmt = "invalid whilte list json ! \n";
    }
    else {
      iVar1 = store_whitelist();
      if (iVar1 == 0) goto LAB_00036daa;
      fmt = "store_write#whitelist_app: FAIL";
    }
    if (BLE_DEBUG == 0) {
      printk(fmt);
    }
    else {
      ble_printk(fmt);
    }
    *(undefined1 *)(param_5 + 1) = 0xca;
  }
LAB_00036daa:
  free(DAT_2000a99c);
  DAT_2000a99c = (char *)0x0;
LAB_00036db4:
                    /* WARNING: Could not recover jumptable at 0x00036dbe. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(param_1 + 0xc))(param_5,2);
  return;
}


