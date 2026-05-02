/*
 * Function: put_whitelist_app_from_app
 * Entry:    00036d24
 * Prototype: undefined __stdcall put_whitelist_app_from_app(int param_1, undefined4 param_2, byte * param_3, uint param_4, int param_5)
 */


void put_whitelist_app_from_app
               (int param_1,undefined4 param_2,byte *param_3,uint param_4,int param_5)

{
  int iVar1;
  char *pcVar2;
  char *fmt;
  char *extraout_r1;
  char *extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar3;
  
  if (DAT_2000a99c == (char *)0x0) {
    DAT_2000a99c = malloc(0x1800);
    if (DAT_2000a99c == (char *)0x0) {
      if (BLE_DEBUG == 0) {
        printk("[%s-%d] malloc failed !!\n");
      }
      else {
        ble_printk("[%s-%d] malloc failed !!\n","put_whitelist_app_from_app",0x1ca,BLE_DEBUG);
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
  pcVar2 = __is_the_same_whitelist_app(DAT_2000a99c);
  if (pcVar2 == (char *)0x0) {
    iVar1 = __parse_app_white_list_json(DAT_2000a99c);
    if (iVar1 == 0) {
      fmt = "invalid whilte list json ! \n";
      pcVar2 = extraout_r1;
      uVar3 = extraout_r2;
    }
    else {
      iVar1 = store_whitelist();
      if (iVar1 == 0) goto LAB_00036daa;
      fmt = "store_write#whitelist_app: FAIL";
      pcVar2 = extraout_r1_00;
      uVar3 = extraout_r2_00;
    }
    if (BLE_DEBUG == 0) {
      printk(fmt);
    }
    else {
      ble_printk(fmt,pcVar2,uVar3,BLE_DEBUG);
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


