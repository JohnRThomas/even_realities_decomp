/*
 * Function: FUN_00027124
 * Entry:    00027124
 * Prototype: int __stdcall FUN_00027124(void * param_1)
 */


int FUN_00027124(void *param_1)

{
  uint uVar1;
  
  uVar1 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,0,param_1,4);
  if (*(char *)((int)param_1 + 2) == '\0') {
    if (uVar1 != 0) {
      return -1;
    }
    uVar1 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,4,(void *)((int)param_1 + 4),4);
  }
  return -(uint)(uVar1 != 0);
}


