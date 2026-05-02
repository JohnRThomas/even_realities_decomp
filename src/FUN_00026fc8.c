/*
 * Function: FUN_00026fc8
 * Entry:    00026fc8
 * Prototype: int __stdcall FUN_00026fc8(undefined4 param_1, uint param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_00026fc8(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 uStack_14;
  
  DAT_200083fc = 0;
  local_1c = param_2;
  local_18 = param_3;
  uStack_14 = param_4;
  iVar2 = FUN_00026f90((int)&local_18);
  sVar1 = (short)iVar2;
  iVar2 = (int)sVar1;
  if (iVar2 == 0) {
    if (((byte)((char)local_18 + 0x1fU) < 2) && ((local_18._1_1_ & 0xfc) == 0x40)) {
      uVar4 = (uint)local_18._2_1_;
      DAT_200083f4._2_1_ = local_18._2_1_;
      if (uVar4 == 0) {
        DAT_20008400 = 8;
        uVar4 = (uStack_14._2_2_ & 0xff) << 8 | (uint)(uStack_14._2_2_ >> 8);
        sVar1 = (short)uVar4;
      }
      else {
        DAT_20008400 = 4;
      }
      DAT_200083f4._1_1_ = local_18._1_1_;
      DAT_200083f4._0_1_ = (char)local_18;
      DAT_200083f4._3_1_ = local_18._3_1_;
      DAT_200083fa = sVar1;
      while ((uVar3 = __eeprom_st25dv_read(global_st25dv_context_ptr,DAT_20008400,&local_1c,4),
             uVar3 == 0 && (DAT_20008400 < uVar4))) {
        if ((local_1c & 0xff) == 3) {
          if (local_1c._1_1_ == 0) {
            local_1c._0_1_ = 1;
          }
          else if ((DAT_200083f4._1_1_ & 3) == 0) {
            local_1c._0_1_ = 2;
          }
          DAT_200083fc = (undefined1)local_1c;
          return 0;
        }
        if ((local_1c & 0xff) != 0xfd) break;
        uVar3 = (uint)local_1c._1_1_;
        if (uVar3 == 0xff) {
          uVar3 = local_1c >> 0x10;
        }
        DAT_20008400 = DAT_20008400 + uVar3;
      }
    }
    iVar2 = -5;
  }
  return iVar2;
}


