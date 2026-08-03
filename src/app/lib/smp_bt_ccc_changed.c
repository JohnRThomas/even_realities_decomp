/*
 * Function: smp_bt_ccc_changed
 * Entry:    00055b00
 * Prototype: void __stdcall smp_bt_ccc_changed(bt_gatt_attr * attr, uint16_t value)
 */


/* exclude_from_export_ai */

void smp_bt_ccc_changed(bt_gatt_attr *attr,uint16_t value)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = smp_reassembly_expected(&smp_bt_transport);
  if ((-1 < iVar1) && (value == 0)) {
    puVar2 = smp_reassembly_get_ud(&smp_bt_transport);
    *puVar2 = 0;
    *(undefined1 *)(puVar2 + 1) = 0;
    smp_reassembly_drop(&smp_bt_transport);
    return;
  }
  return;
}


