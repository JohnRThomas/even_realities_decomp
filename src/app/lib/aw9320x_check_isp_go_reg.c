/*
 * Function: aw9320x_check_isp_go_reg
 * Entry:    000804b6
 * Prototype: int32_t __stdcall aw9320x_check_isp_go_reg(void)
 */


/* exclude_from_export */

int32_t aw9320x_check_isp_go_reg(void)

{
  int8_t iVar1;
  int32_t iVar2;
  int iVar3;
  bool bVar4;
  uint32_t local_c;
  
  iVar3 = 100;
  local_c = 0;
  do {
    iVar1 = aw9320x_i2c_read(0x4714,&local_c);
    if (iVar1 != 0) {
      return (int)iVar1;
    }
    if (local_c == 0) break;
    AW_DELAY(1);
    bVar4 = iVar3 != 0;
    iVar3 = iVar3 + -1;
  } while (bVar4);
  iVar2 = -1;
  if (iVar3 != -1) {
    iVar2 = 0;
  }
  return iVar2;
}


