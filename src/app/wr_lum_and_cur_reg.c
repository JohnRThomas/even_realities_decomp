/*
 * Function: $_wr_lum_and_cur_reg
 * Entry:    0004aa00
 * Prototype: void __stdcall $_wr_lum_and_cur_reg(int lum_value, int cur_value)
 */


void __wr_lum_and_cur_reg(int lum_value,int cur_value)

{
  if (lum_value != JBD_LUM_REG_VAL) {
    __wr_lum_reg((uint16_t)lum_value);
    JBD_LUM_REG_VAL = lum_value;
  }
  if (cur_value != JBD_CUR_REG_VAL) {
    __wr_cur_reg((uint8_t)cur_value);
    JBD_CUR_REG_VAL = cur_value;
  }
  return;
}


