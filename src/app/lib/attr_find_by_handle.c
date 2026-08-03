/*
 * Function: attr_find_by_handle
 * Entry:    00082b1e
 * Prototype: bt_gatt_dm_attr * __stdcall attr_find_by_handle(bt_gatt_dm * dm, uint16_t handle)
 */


/* exclude_from_export */

bt_gatt_dm_attr * attr_find_by_handle(bt_gatt_dm *dm,uint16_t handle)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)((int)&dm[5].STATE_NUM_ + 3);
  if (iVar2 != 0) {
    iVar4 = 0;
    iVar2 = iVar2 + -1;
    while (iVar4 <= iVar2) {
      iVar3 = (iVar4 + iVar2) / 2;
      uVar1 = (ushort)(&dm->u32)[iVar3 * 2];
      if (uVar1 < handle) {
        iVar4 = iVar3 + 1;
      }
      else {
        if (uVar1 <= handle) {
          return (bt_gatt_dm_attr *)(&dm->u16 + iVar3 * 2);
        }
        iVar2 = iVar3 + -1;
      }
    }
  }
  return (bt_gatt_dm_attr *)0x0;
}


