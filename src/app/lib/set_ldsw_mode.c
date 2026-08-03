/*
 * Function: set_ldsw_mode
 * Entry:    00087a00
 * Prototype: int __stdcall set_ldsw_mode(int param_1, char param_2, int param_3)
 */


/* exclude_from_export */

int set_ldsw_mode(int param_1,char param_2,int param_3)

{
  int iVar1;
  
  if ((param_3 != 2) && (param_3 != 3)) {
    return -0x86;
  }
  iVar1 = i2c_write_dt(*(i2c_dt_spec **)(param_1 + 0x1c),&NMI,(uint)(byte)(param_2 + 8));
  return iVar1;
}


