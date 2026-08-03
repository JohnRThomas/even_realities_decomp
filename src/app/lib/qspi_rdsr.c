/*
 * Function: qspi_rdsr
 * Entry:    00087156
 * Prototype: int __stdcall qspi_rdsr(device * dev, uint8_t sr_num)
 */


/* exclude_from_export */

int qspi_rdsr(device *dev,uint8_t sr_num)

{
  uint uVar1;
  byte local_1d;
  byte *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1d = 0xff;
  local_1c = &local_1d;
  local_18 = 1;
  local_14 = 5;
  uVar1 = qspi_send_cmd(dev,(qspi_cmd *)&local_14,false);
  if (-1 < (int)uVar1) {
    uVar1 = (uint)local_1d;
  }
  return uVar1;
}


