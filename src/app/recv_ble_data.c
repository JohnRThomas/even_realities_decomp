/*
 * Function: recv_ble_data
 * Entry:    0001981c
 * Prototype: undefined __stdcall recv_ble_data(int param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void recv_ble_data(int param_1)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined1 uVar2;
  byte local_1c8 [4];
  int local_1c4 [2];
  undefined4 local_1bc;
  char local_1b4 [384];
  undefined1 auStack_34 [32];
  uint local_14;
  
  local_1c8[0] = 0x4b;
  local_1c8[1] = 0;
  local_1c8[2] = 0;
  local_1c8[3] = 0;
  memset(local_1c4,0,0x1b4);
  iVar1 = dequeue_ancs(local_1c4);
  if ((iVar1 == 0) && ((1 < local_14 || (local_1b4[0] != '\0')))) {
    local_1c4[0] = FUN_00080732();
    if (local_1c4[0] == 0) {
      local_1c4[0] = 1;
    }
    local_1bc = _DAT_20006c8c;
    dump_ancs("FROM:ancs",(int)local_1c4,extraout_r2,_DAT_20006c8c);
    if ((local_14 < 2) &&
       (iVar1 = is_on_whitelist_by_identifier(local_1b4,extraout_r1,extraout_r2_00,local_14),
       iVar1 != 2)) {
      if (iVar1 != 3) {
        if (iVar1 != 1) {
          return;
        }
        if (BLE_DEBUG == 0) {
          printk("blocked! app(%s) not in whitelist \n");
        }
        else {
          ble_printk("blocked! app(%s) not in whitelist \n",local_1b4,extraout_r2_01,BLE_DEBUG);
        }
        com_android_phone_missed((int)local_1c4);
        return;
      }
      uVar2 = 4;
    }
    else {
      uVar2 = 2;
    }
    local_1c8[1] = uVar2;
    if (DAT_20006c92 == '\x02') {
      strcpy(local_1b4,"com.apple.mobilephone_missed");
    }
    FUN_0007fdfa(auStack_34);
    ble_process_req_dispatch(param_1,local_1c8,(byte *)local_1c4);
  }
  return;
}


