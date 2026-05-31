/*
 * Function: $_qspi_FUN_000698ec
 * Entry:    000698ec
 * Prototype: undefined __stdcall $_qspi_FUN_000698ec(void)
 */


void __qspi_FUN_000698ec(void)

{
  qspi_m_cb.evt_ext.data.xfer.p_buffer = qspi_m_cb.p_buffer_primary;
  qspi_m_cb.evt_ext.data.xfer.size = qspi_m_cb.size_primary;
  qspi_m_cb.evt_ext.data.xfer.addr = qspi_m_cb.addr_primary;
  qspi_m_cb.p_buffer_primary = qspi_m_cb.p_buffer_secondary;
  if (qspi_m_cb.p_buffer_secondary != (void *)0x0) {
    qspi_m_cb.size_primary = qspi_m_cb.size_secondary;
    qspi_m_cb.addr_primary = qspi_m_cb.addr_secondary;
    qspi_m_cb.p_buffer_secondary = (void *)0x0;
    return;
  }
  return;
}


