/*
 * Function: bt_le_lim_adv_cancel_timeout
 * Entry:    00084ad8
 * Prototype: int __stdcall bt_le_lim_adv_cancel_timeout(bt_le_ext_adv * adv)
 */


/* exclude_from_export */

int bt_le_lim_adv_cancel_timeout(bt_le_ext_adv *adv)

{
  int iVar1;
  
  iVar1 = k_work_cancel_delayable((k_work_delayable *)&adv->tx_power);
  return iVar1;
}


