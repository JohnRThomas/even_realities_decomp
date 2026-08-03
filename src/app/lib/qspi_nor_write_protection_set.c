/*
 * Function: qspi_nor_write_protection_set
 * Entry:    0008712c
 * Prototype: int __stdcall qspi_nor_write_protection_set(device * dev, bool write_protect)
 */


/* exclude_from_export */

int qspi_nor_write_protection_set(device *dev,bool write_protect)

{
  int iVar1;
  int iVar2;
  undefined1 local_14 [12];
  
  if (write_protect) {
    local_14[0] = 4;
  }
  else {
    local_14[0] = 6;
  }
  local_14._4_4_ = 0;
  local_14._8_4_ = 0;
  local_14._1_3_ = 0;
  iVar1 = qspi_send_cmd(dev,(qspi_cmd *)local_14,false);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = -5;
  }
  return iVar2;
}


