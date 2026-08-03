/*
 * Function: qspi_device_uninit
 * Entry:    00069d88
 * Prototype: void __stdcall qspi_device_uninit(device * dev)
 */


/* exclude_from_export_ai */

void qspi_device_uninit(device *dev)

{
  uint3 in_r1;
  uint in_r3;
  undefined4 uStack_14;
  nrf_qspi_cinstr_conf_t local_10;
  uint local_c;
  
  local_10.opaque[0] = 5;
  local_10.opaque[1] = 2;
  local_10.opaque[2] = 0;
  local_10.opaque[3] = 1;
  uStack_14 = (uint)in_r1;
  local_c = in_r3 & 0xffff0000;
  nrfx_qspi_cinstr_xfer(&local_10,(void *)((int)&uStack_14 + 3),(void *)((int)&uStack_14 + 3));
  return;
}


