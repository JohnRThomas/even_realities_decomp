/*
 * Function: qspi_send_cmd
 * Entry:    00063d54
 * Prototype: int __stdcall qspi_send_cmd(device * dev, qspi_cmd * cmd, bool wren)
 */


/* exclude_from_export */

int qspi_send_cmd(device *dev,qspi_cmd *cmd,bool wren)

{
  nrfx_err_t res;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  void *p_tx_buffer;
  void *p_rx_buffer;
  char local_30 [4];
  char *local_2c;
  uint uStack_28;
  uint local_24;
  nrf_qspi_cinstr_conf_t local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  
  puVar3 = *(undefined4 **)((int)&cmd->tx_buf + 3);
  if (puVar3 == (undefined4 *)0x0) {
    iVar2 = 0;
    p_tx_buffer = (void *)0x0;
  }
  else {
    p_tx_buffer = (void *)*puVar3;
    iVar2 = puVar3[1];
  }
  puVar3 = *(undefined4 **)((int)&cmd->rx_buf + 3);
  if (puVar3 == (undefined4 *)0x0) {
    iVar1 = 0;
    p_rx_buffer = (void *)0x0;
  }
  else {
    p_rx_buffer = (void *)*puVar3;
    iVar1 = puVar3[1];
    if ((iVar1 != 0) && (iVar2 != 0)) {
      if (iVar1 != iVar2) {
        return -0x16;
      }
      local_24 = iVar2 + 1;
      goto LAB_00063d84;
    }
  }
  local_24 = iVar2 + 1 + iVar1;
LAB_00063d84:
  local_20.opaque[0] = cmd->op_code;
  uStack_28 = (uint)local_20.opaque[0];
  if (9 < local_24) {
    local_2c = "cinstr %02x transfer too long: %zu";
    local_30[0] = '\x04';
    local_30[1] = '\0';
    local_30[2] = '\0';
    local_30[3] = '\0';
    LOG_ERR(&PTR_s_qspi_nor_0008ba20,0x2080,local_30);
    return -0x16;
  }
  local_20.opaque[1] = (byte)local_24;
  local_20.opaque[2] = 1;
  local_20.opaque[3] = 1;
  local_1c = 0;
  local_1b = wren;
  qspi_lock(dev);
  res = nrfx_qspi_cinstr_xfer(&local_20,p_tx_buffer,p_rx_buffer);
  qspi_unlock(dev);
  iVar2 = qspi_get_zephyr_ret_code(res);
  return iVar2;
}


