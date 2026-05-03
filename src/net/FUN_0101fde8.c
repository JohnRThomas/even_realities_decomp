/*
 * Function: FUN_0101fde8
 * Entry:    0101fde8
 * Prototype: undefined4 __stdcall FUN_0101fde8(char * param_1, undefined4 param_2)
 */


undefined4 FUN_0101fde8(char *param_1,undefined4 param_2)

{
  char local_12;
  char local_11;
  
  if (*param_1 != '\0') {
    FUN_01022108();
    local_12 = (char)((uint)param_2 >> 0x10);
    FUN_01022114();
    local_11 = (char)((uint)param_2 >> 0x18);
    if (local_12 != '\0' || local_11 != '\0') {
      return 0xc;
    }
  }
  DAT_2100120c._0_1_ = *param_1;
  return 0;
}


