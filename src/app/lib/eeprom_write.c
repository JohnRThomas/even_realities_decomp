/*
 * Function: eeprom_write
 * Entry:    00026ee4
 * Prototype: char __stdcall eeprom_write(int param_1)
 */


/* exclude_from_export_ai */

char eeprom_write(int param_1)

{
  char local_19;
  undefined4 local_18;
  undefined4 local_14;
  
  local_19 = '\0';
  FUN_0007fd8c(global_st25dv_context_ptr,&local_19);
  if (local_19 == '\0') {
    if (param_1 == 0) goto LAB_00026f10;
    local_14 = 0;
    local_18 = 0;
  }
  else {
    if ((local_19 != '\x01') || (param_1 != 0)) goto LAB_00026f10;
    local_18 = 0x12345678;
    local_14 = 0x13245678;
  }
  __data_write((uint32_t *)global_st25dv_context_ptr);
LAB_00026f10:
  FUN_0007fd8c(global_st25dv_context_ptr,&local_19);
  return local_19;
}


