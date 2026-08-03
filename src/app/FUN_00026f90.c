/*
 * Function: FUN_00026f90
 * Entry:    00026f90
 * Prototype: int __stdcall FUN_00026f90(undefined * param_1)
 */


int FUN_00026f90(undefined *param_1)

{
  uint uVar1;
  
  uVar1 = __eeprom_st25dv_read(global_st25dv_context_ptr,ST25DV_GPO_REG,param_1,4);
  if (param_1[2] == 0) {
    if (uVar1 != 0) {
      return -1;
    }
    uVar1 = __eeprom_st25dv_read(global_st25dv_context_ptr,ST25DV_RFA1SS_REG,param_1 + 4,4);
  }
  return -(uint)(uVar1 != 0);
}


