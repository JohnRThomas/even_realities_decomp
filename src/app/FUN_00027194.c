/*
 * Function: FUN_00027194
 * Entry:    00027194
 * Prototype: int __stdcall FUN_00027194(void)
 */


int FUN_00027194(void)

{
  int iVar1;
  uint uVar2;
  undefined1 local_19;
  undefined4 local_18;
  ushort local_12;
  
  local_18 = DAT_200083f4;
  DAT_20008400 = 4;
  if (DAT_200083f4._2_1_ == '\0') {
    local_12 = DAT_200083fa << 8 | DAT_200083fa >> 8;
    DAT_20008400 = 8;
  }
  iVar1 = FUN_00027124(&local_18);
  iVar1 = (int)(short)iVar1;
  if (iVar1 == 0) {
    local_19 = 3;
    uVar2 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,DAT_20008400,&local_19,1);
    if (uVar2 == 0) {
      local_19 = 0;
      uVar2 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,DAT_20008400 + 1,&local_19,1);
      iVar1 = -(uint)(uVar2 != 0);
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}


