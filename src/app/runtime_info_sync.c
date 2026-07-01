/*
 * Function: runtime_info_sync
 * Entry:    00016308
 * Prototype: int __stdcall runtime_info_sync(undefined2 * param_1)
 */


int runtime_info_sync(undefined2 *param_1)

{
  int iVar1;
  undefined4 local_18;
  uint local_14;
  
  local_18 = CONCAT22(*param_1,1);
  local_14 = (uint)*(uint3 *)(param_1 + 1);
  iVar1 = global_ipc_service_send(&local_18,8,(uint)(ushort)*(uint3 *)(param_1 + 1));
  if ((DAT_20003002 != '\0') && (DAT_20003002 = '\0', 1 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk(
            "%s(): --role:%d --mode:%d, esb_channel %d --ret:%d esb_master_addr %02X esb_slave_addr %02X\n"
            );
    }
    else {
      ble_printk("%s(): --role:%d --mode:%d, esb_channel %d --ret:%d esb_master_addr %02X esb_slave_addr %02X\n"
                 ,"runtime_info_sync",local_18 >> 0x10 & 0xff,local_18 >> 0x18,local_14 & 0xff,iVar1
                 ,(uint)*(byte *)((int)param_1 + 3),(uint)*(byte *)(param_1 + 2));
    }
  }
  return iVar1;
}


