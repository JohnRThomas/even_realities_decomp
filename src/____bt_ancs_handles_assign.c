/*
 * Function: $_?_bt_ancs_handles_assign
 * Entry:    00083094
 * Prototype: int __stdcall $_?_bt_ancs_handles_assign(bt_gatt_dm * dm, bt_ancs_client * ancs_c)
 */


int ____bt_ancs_handles_assign(bt_gatt_dm *dm,bt_ancs_client *ancs_c)

{
  ushort uVar1;
  bt_gatt_dm_attr *pbVar2;
  bt_gatt_service_val *pbVar3;
  int iVar4;
  bt_gatt_dm_attr *pbVar5;
  bt_conn *pbVar6;
  ushort in_r2;
  ushort in_r3;
  undefined4 local_24;
  ushort local_20;
  undefined2 local_1e;
  ushort local_1c;
  undefined2 local_1a;
  
  local_24 = ancs_c;
  local_1c = in_r3;
  local_20 = in_r2;
  pbVar2 = bt_gatt_dm_service_get(dm);
  pbVar3 = bt_gatt_dm_attr_service_val(pbVar2);
  local_1c = local_1c & 0xff00;
  _local_1c = CONCAT22(0x1801,local_1c);
  iVar4 = bt_uuid_cmp((bt_uuid *)*pbVar3,(bt_uuid *)&local_1c);
  if (iVar4 == 0) {
    *(undefined4 *)ancs_c = 0;
    *(undefined4 *)(ancs_c + 4) = 0;
    *(undefined4 *)(ancs_c + 0x28) = 0;
    uVar1 = (ushort)local_24;
    local_24 = (bt_ancs_client *)CONCAT22(0x2a05,uVar1 & 0xff00);
    pbVar2 = bt_gatt_dm_char_by_uuid(dm,(bt_uuid *)&local_24);
    if (pbVar2 != (bt_gatt_dm_attr *)0x0) {
      local_20 = local_20 & 0xff00;
      _local_20 = CONCAT22(0x2a05,local_20);
      pbVar5 = bt_gatt_dm_desc_by_uuid(dm,pbVar2,(bt_uuid *)&local_20);
      if (pbVar5 != (bt_gatt_dm_attr *)0x0) {
        *(short *)(ancs_c + 4) = (short)pbVar5[1];
        local_1c = (ushort)_local_1c & 0xff00;
        _local_1c = CONCAT22(0x2902,local_1c);
        pbVar2 = bt_gatt_dm_desc_by_uuid(dm,pbVar2,(bt_uuid *)&local_1c);
        if (pbVar2 != (bt_gatt_dm_attr *)0x0) {
          *(short *)(ancs_c + 6) = (short)pbVar2[1];
          pbVar6 = bt_gatt_dm_conn_get(dm);
          *(bt_conn **)ancs_c = pbVar6;
          return 0;
        }
      }
    }
    iVar4 = -0x16;
  }
  else {
    iVar4 = -0x86;
  }
  return iVar4;
}


