/*
 * Function: smp_bt_get_mtu
 * Entry:    00084434
 * Prototype: uint16_t __stdcall smp_bt_get_mtu(net_buf * nb)
 */


/* exclude_from_export_ai */

uint16_t smp_bt_get_mtu(net_buf *nb)

{
  uint16_t uVar1;
  int iVar2;
  bt_gatt_write_params *in_r1;
  
  uVar1 = 0;
  if ((bt_conn *)nb->user_data != (bt_conn *)0x0) {
    iVar2 = gatt_prepare_write((bt_conn *)nb->user_data,in_r1);
    uVar1 = (short)iVar2 - 3;
  }
  return uVar1;
}


