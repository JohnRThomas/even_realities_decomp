/*
 * Function: attr_store
 * Entry:    00051c40
 * Prototype: bt_gatt_dm_attr * __stdcall attr_store(bt_gatt_dm * dm, bt_gatt_attr * attr, size_t additional_len)
 */


/* exclude_from_export */

bt_gatt_dm_attr * attr_store(bt_gatt_dm *dm,bt_gatt_attr *attr,size_t additional_len)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  size_t n;
  void *pvVar6;
  size_t len;
  dword in_stack_ffffffd0;
  uint8_t *in_stack_ffffffd4;
  void *in_stack_ffffffd8;
  undefined4 local_20;
  char *local_1c;
  
  if (DAT_2000ac68 < 0x23) {
    n = get_uuid_size((bt_uuid *)(uint)(byte)dm->conn->handle);
    pvVar6 = user_data_alloc((bt_gatt_dm *)((int)&attr->uuid + n),len);
    uVar5 = DAT_2000ac68;
    if (pvVar6 != (void *)0x0) {
      iVar2 = DAT_2000ac68 * 8;
      iVar3 = DAT_2000ac68 * 2;
      iVar4 = DAT_2000ac68 * 2;
      DAT_2000ac68 = DAT_2000ac68 + 1;
      *(short *)(&bt_gatt_dm_inst.u32 + iVar4) = (short)dm->cur_attr_id;
      uVar1 = *(undefined2 *)((int)&dm->cur_attr_id + 2);
      (&bt_gatt_dm_inst.u16)[uVar5 * 2] = (dword)((int)pvVar6 + (int)attr);
      *(char *)((int)&bt_gatt_dm_inst.u32 + iVar2 + 2) = (char)uVar1;
      memcpy((void *)((int)pvVar6 + (int)attr),dm->conn,n);
      return (bt_gatt_dm_attr *)(&bt_gatt_dm_inst.u16 + iVar3);
    }
    local_1c = "No space for attribute data.";
  }
  else {
    local_1c = "No space for new attribute.";
  }
  local_20 = 2;
  LOG_ERRFMT(&PTR_s_bt_gatt_dm_0008b8e0,0x1040,&local_20,2,in_stack_ffffffd0,in_stack_ffffffd4,
             in_stack_ffffffd8);
  return (bt_gatt_dm_attr *)0x0;
}


