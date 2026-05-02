/*
 * Function: discover_gattp
 * Entry:    000183ec
 * Prototype: undefined __stdcall discover_gattp(bt_conn * param_1, ushort param_2, undefined4 param_3)
 */


void discover_gattp(bt_conn *param_1,ushort param_2,undefined4 param_3)

{
  int iVar1;
  ushort local_c;
  undefined2 local_a;
  undefined4 uStack_8;
  
  _local_c = CONCAT22(0x1801,param_2 & 0xff00);
  uStack_8 = param_3;
  iVar1 = bt_gatt_dm_start(param_1,(bt_uuid *)&local_c,&discovery_cb,&GLOBAL_STATE.sem_8.poll_events
                          );
  if (iVar1 != 0) {
    printk("Failed to start discovery for GATT Service (err %d)\n",iVar1);
  }
  return;
}


