/*
 * Function: aw9320x_reg_read_val
 * Entry:    00080568
 * Prototype: int32_t __stdcall aw9320x_reg_read_val(uint32_t * read_data, uint16_t start_addr)
 */


/* exclude_from_export */

int32_t aw9320x_reg_read_val(uint32_t *read_data,uint16_t start_addr)

{
  aw9320x_err_code aVar1;
  int8_t iVar2;
  int iVar3;
  int32_t iVar4;
  
  aVar1 = aw9320x_i2c_write(0x4704,(uint)start_addr);
  if ((((aVar1 == AW_OK) && (aVar1 = aw9320x_i2c_write(0x4710,3), aVar1 == AW_OK)) &&
      (aVar1 = aw9320x_i2c_write(0x4714,1), aVar1 == AW_OK)) &&
     (iVar4 = aw9320x_check_isp_go_reg(), iVar4 == 0)) {
    iVar2 = aw9320x_i2c_read(0x470c,read_data);
    iVar3 = -(uint)(iVar2 != '\0');
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}


