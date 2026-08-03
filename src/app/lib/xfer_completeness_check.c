/*
 * Function: xfer_completeness_check
 * Entry:    00088ac6
 * Prototype: bool __stdcall xfer_completeness_check(NRF_TWI_Type * p_twi, twi_control_block_t * p_cb)
 */


/* exclude_from_export */

bool xfer_completeness_check(NRF_TWI_Type *p_twi,twi_control_block_t *p_cb)

{
  NRF_TWI_Type NVar1;
  NRF_TWI_Type NVar2;
  
  switch((char)p_cb[8]) {
  case '\0':
    NVar2 = p_twi[0x153];
    break;
  case '\x01':
    NVar2 = p_twi[0x14f];
    break;
  case '\x02':
    if (p_cb[4] != p_twi[0x153]) goto LAB_00088af8;
    NVar2 = p_twi[0x14f];
    goto LAB_00088af2;
  case '\x03':
    if (((int)(p_cb[2] << 0xd) < 0) && (p_cb[4] != p_twi[0x153])) goto LAB_00088af8;
    if ((int)(p_cb[2] << 0xd) < 0) {
      return true;
    }
    NVar2 = p_twi[0x153];
LAB_00088af2:
    NVar1 = p_cb[6];
    goto LAB_00088af4;
  default:
    goto switchD_00088ad0_default;
  }
  NVar1 = p_cb[4];
LAB_00088af4:
  if (NVar1 != NVar2) {
LAB_00088af8:
    p_twi[0x140] = 0;
    p_twi[0x140] = 6;
    return false;
  }
switchD_00088ad0_default:
  return true;
}


