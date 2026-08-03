/*
 * Function: FUN_0002707c
 * Entry:    0002707c
 * Prototype: int __stdcall FUN_0002707c(undefined4 param_1, uint param_2, void * param_3)
 */


int FUN_0002707c(undefined4 param_1,uint param_2,void *param_3)

{
  st25dv_register sVar1;
  int iVar2;
  uint extraout_r1;
  int iVar3;
  uint uVar4;
  size_t sVar5;
  undefined1 local_1d;
  undefined4 local_1c;
  
  local_1c = param_2;
  iVar2 = FUN_00026f6c(param_1,param_2,param_3);
  if (param_2 < 0xff) {
    iVar3 = 2;
  }
  else {
    iVar3 = 4;
  }
  uVar4 = ((iVar2 - DAT_20008400) + -1) - iVar3;
  if (uVar4 < param_2) {
    iVar2 = -2;
  }
  else {
    iVar2 = FUN_00026fc8(iVar2,extraout_r1,iVar3,uVar4);
    sVar1 = DAT_20008400;
    if (iVar2 == 0) {
      if (param_2 < 0xff) {
        sVar5 = 2;
        local_1c._0_2_ = CONCAT11((char)param_2,(char)param_1);
      }
      else {
        sVar5 = 4;
        local_1c._0_2_ = CONCAT11(0xff,(char)param_1);
        local_1c = CONCAT22((ushort)((param_2 & 0xff) << 8) | (ushort)(param_2 >> 8) & 0xff,
                            (undefined2)local_1c);
      }
      uVar4 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,DAT_20008400,&local_1c,sVar5);
      if (uVar4 == 0) {
        uVar4 = __eeprom_st25dv_write((int)global_st25dv_context_ptr,sVar5 + sVar1,param_3,param_2);
        if (uVar4 == 0) {
          uVar4 = __eeprom_st25dv_write
                            ((int)global_st25dv_context_ptr,param_2 + sVar5 + sVar1,&local_1d,1);
          return -(uint)(uVar4 != 0);
        }
      }
    }
    iVar2 = -1;
  }
  return iVar2;
}


