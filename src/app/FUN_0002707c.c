/*
 * Function: FUN_0002707c
 * Entry:    0002707c
 * Prototype: int __stdcall FUN_0002707c(undefined4 param_1, uint param_2, void * param_3)
 */


int FUN_0002707c(undefined4 param_1,uint param_2,void *param_3)

{
  int iVar1;
  uint extraout_r1;
  int iVar2;
  uint uVar3;
  size_t sVar4;
  undefined1 local_1d;
  undefined4 local_1c;
  
  local_1c = param_2;
  iVar1 = FUN_00026f6c(param_1,param_2,param_3);
  if (param_2 < 0xff) {
    iVar2 = 2;
  }
  else {
    iVar2 = 4;
  }
  uVar3 = ((iVar1 - DAT_20008400) + -1) - iVar2;
  if (uVar3 < param_2) {
    iVar1 = -2;
  }
  else {
    iVar2 = FUN_00026fc8(iVar1,extraout_r1,iVar2,uVar3);
    iVar1 = DAT_20008400;
    if (iVar2 == 0) {
      if (param_2 < 0xff) {
        sVar4 = 2;
        local_1c._0_2_ = CONCAT11((char)param_2,(char)param_1);
      }
      else {
        sVar4 = 4;
        local_1c._0_2_ = CONCAT11(0xff,(char)param_1);
        local_1c = CONCAT22((ushort)((param_2 & 0xff) << 8) | (ushort)(param_2 >> 8) & 0xff,
                            (undefined2)local_1c);
      }
      uVar3 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,DAT_20008400,&local_1c,sVar4);
      if (uVar3 == 0) {
        uVar3 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,sVar4 + iVar1,param_3,param_2);
        if (uVar3 == 0) {
          uVar3 = __eeprom_st25dv_write
                            ((int)global_st25dv_context_ptr,param_2 + sVar4 + iVar1,&local_1d,1);
          return -(uint)(uVar3 != 0);
        }
      }
    }
    iVar1 = -1;
  }
  return iVar1;
}


