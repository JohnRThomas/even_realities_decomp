/*
 * Function: aw9320x_get_irq_stat
 * Entry:    00031f90
 * Prototype: void __stdcall aw9320x_get_irq_stat(cap_event_status * p_irq_stat_data, uint32_t * irq_status)
 */


/* exclude_from_export */

void aw9320x_get_irq_stat(cap_event_status *p_irq_stat_data,uint32_t *irq_status)

{
  int8_t iVar1;
  uint32_t local_c [2];
  
  local_c[0] = 0;
  iVar1 = aw9320x_i2c_read(0x4410,local_c);
  if (-1 < iVar1) {
    if ((int)(local_c[0] << 0x1d) < 0) {
      aw9320x_wearing = OUT_EAR;
    }
    if ((local_c[0] & 2) != 0) {
      aw9320x_wearing = IN_EAR;
    }
    if ((local_c[0] & 1) != 0) {
      aw9320x_para_loaded();
      return;
    }
  }
  return;
}


