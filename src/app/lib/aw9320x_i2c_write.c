/*
 * Function: aw9320x_i2c_write
 * Entry:    00031618
 * Prototype: aw9320x_err_code __stdcall aw9320x_i2c_write(uint16_t reg_addr, uint32_t reg_data)
 */


/* exclude_from_export_ai */

aw9320x_err_code aw9320x_i2c_write(uint16_t reg_addr,uint32_t reg_data)

{
  ushort uVar1;
  int status;
  char cnt;
  uint8_t tx_buf [6];
  undefined2 uStack_12;
  
  cnt = 3;
  uVar1 = reg_addr << 8 | reg_addr >> 8;
  tx_buf[2] = (char)(reg_data >> 0x18);
  tx_buf[0] = (char)uVar1;
  tx_buf[1] = (char)(uVar1 >> 8);
  tx_buf[3] = (uint8_t)(reg_data >> 0x10);
  stack0xffffffec =
       CONCAT22((short)(reg_data >> 0x10),
                (ushort)((reg_data & 0xff) << 8) | (ushort)(reg_data >> 8) & 0xff);
  do {
    status = (**(code **)(g_aw9320x_func.i2c_func.i2c_r + 4))(tx_buf,6);
    if (status == 0) {
      return AW_OK;
    }
    cnt = cnt + -1;
    AW_DELAY(1);
  } while (cnt != '\0');
  return ~AW_OK;
}


