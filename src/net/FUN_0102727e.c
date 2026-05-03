/*
 * Function: FUN_0102727e
 * Entry:    0102727e
 * Prototype: short __stdcall FUN_0102727e(ushort param_1, byte param_2, short param_3)
 */


short FUN_0102727e(ushort param_1,byte param_2,short param_3)

{
  short sVar1;
  undefined2 local_a;
  
  sVar1 = FUN_0102709c(param_1,param_2,param_3);
  local_a = 0;
  if (param_1 < 0x45) {
    local_a = 0x45 - param_1;
  }
  return local_a + sVar1 + 0x18;
}


