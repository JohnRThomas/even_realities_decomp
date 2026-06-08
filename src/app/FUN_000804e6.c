/*
 * Function: FUN_000804e6
 * Entry:    000804e6
 * Prototype: int __stdcall FUN_000804e6(void)
 */


int FUN_000804e6(void)

{
  aw9320x_err_code aVar1;
  uint32_t in_r0;
  int iVar2;
  int32_t iVar3;
  uint32_t in_r1;
  
  aVar1 = aw9320x_i2c_write(0x4704,in_r0);
  if ((((aVar1 == AW_OK) && (aVar1 = aw9320x_i2c_write(0x4708,in_r1), aVar1 == AW_OK)) &&
      (aVar1 = aw9320x_i2c_write(0x4710,0xc), aVar1 == AW_OK)) &&
     (aVar1 = aw9320x_i2c_write(0x4714,1), aVar1 == AW_OK)) {
    iVar3 = aw9320x_check_isp_go_reg();
    iVar2 = -(uint)(iVar3 != 0);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


