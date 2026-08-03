/*
 * Function: gatt_ccc_changed
 * Entry:    00085d78
 * Prototype: void __stdcall gatt_ccc_changed(bt_gatt_attr * attr, _bt_gatt_ccc * ccc)
 */


/* exclude_from_export_ai */

void gatt_ccc_changed(bt_gatt_attr *attr,_bt_gatt_ccc *ccc)

{
  if (*(short *)((int)ccc + 10) != (short)ccc[2]) {
    *(short *)((int)ccc + 10) = (short)ccc[2];
    if ((code *)ccc[3] != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00085d88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)ccc[3])(attr);
      return;
    }
  }
  return;
}


