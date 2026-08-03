/*
 * Function: exit_dpd
 * Entry:    0008710c
 * Prototype: int __stdcall exit_dpd(device * dev)
 */


/* exclude_from_export */

int exit_dpd(device *dev)

{
  uint uVar1;
  undefined1 local_14 [12];
  
  local_14._4_4_ = 0;
  local_14._8_4_ = 0;
  local_14._0_4_ = 0xab;
  uVar1 = qspi_send_cmd(dev,(qspi_cmd *)local_14,false);
  return uVar1 & (int)uVar1 >> 0x1f;
}


