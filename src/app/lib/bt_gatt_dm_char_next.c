/*
 * Function: bt_gatt_dm_char_next
 * Entry:    00082c6e
 * Prototype: bt_gatt_dm_attr * __stdcall bt_gatt_dm_char_next(bt_gatt_dm * dm, bt_gatt_dm_attr * prev)
 */


/* exclude_from_export */

bt_gatt_dm_attr * bt_gatt_dm_char_next(bt_gatt_dm *dm,bt_gatt_dm_attr *prev)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  dword *pdVar4;
  undefined4 local_1c;
  
  pdVar4 = &dm->u16;
  if ((prev == (bt_gatt_dm_attr *)0x0) || (pdVar4 = (dword *)prev, &dm->u16 <= prev)) {
    iVar3 = *(int *)((int)&dm[5].STATE_NUM_ + 3);
    local_1c = prev;
    do {
      pdVar4 = pdVar4 + 2;
      if (&dm->u16 + iVar3 * 2 <= pdVar4) goto LAB_00082c7a;
      uVar1 = (ushort)local_1c;
      local_1c = (bt_gatt_dm_attr *)CONCAT22(0x2803,uVar1 & 0xff00);
      iVar2 = bt_uuid_cmp((bt_uuid *)&local_1c,(bt_uuid *)*pdVar4);
    } while (iVar2 != 0);
  }
  else {
LAB_00082c7a:
    pdVar4 = (dword *)0x0;
  }
  return (bt_gatt_dm_attr *)pdVar4;
}


