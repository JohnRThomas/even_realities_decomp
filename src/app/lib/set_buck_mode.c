/*
 * Function: set_buck_mode
 * Entry:    00087a26
 * Prototype: int __stdcall set_buck_mode(int param_1, int param_2, int param_3)
 */


/* exclude_from_export */

int set_buck_mode(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint32_t num_bytes;
  
  if (param_3 == 0) {
    num_bytes = param_2 * 2 + 5U & 0xff;
  }
  else {
    if (param_3 != 1) {
      return -0x86;
    }
    num_bytes = (param_2 + 2) * 2 & 0xfe;
  }
  iVar1 = i2c_write_dt(*(i2c_dt_spec **)(param_1 + 0x1c),&Reset,num_bytes);
  return iVar1;
}


