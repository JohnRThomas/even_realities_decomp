/*
 * Function: nus_ccc_cfg_changed
 * Entry:    00052770
 * Prototype: void __stdcall nus_ccc_cfg_changed(bt_gatt_attr * attr, uint16_t value)
 */


/* exclude_from_export_ai */

void nus_ccc_cfg_changed(bt_gatt_attr *attr,uint16_t value)

{
  if (DAT_2000aca0 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0005277c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_2000aca0)(value != 1);
    return;
  }
  return;
}


