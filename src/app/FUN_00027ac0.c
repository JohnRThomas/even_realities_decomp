/*
 * Function: FUN_00027ac0
 * Entry:    00027ac0
 * Prototype: int __stdcall FUN_00027ac0(st25dv_context * param_1, undefined4 * param_2, uint * param_3)
 */


int FUN_00027ac0(st25dv_context *param_1,undefined4 *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_18;
  undefined4 *local_14;
  
  if (((param_1 == (st25dv_context *)0x0) || (param_2 == (undefined4 *)0x0)) ||
     (param_3 == (uint *)0x0)) {
    iVar2 = -1;
  }
  else {
    uStack_18 = (uint)param_1 & 0xffffff;
    local_14 = param_2;
    puVar1 = (undefined4 *)
             __eeprom_st25dv_read(param_1,ST25DV_MB_CTRL_DYN_REG,(int)&uStack_18 + 3,1);
    if (puVar1 == (undefined4 *)0x0) {
      if ((uStack_18._3_1_ & 5) == 5) {
        local_14 = puVar1;
        uVar3 = __eeprom_st25dv_read(param_1,ST25DV_MBLEN_DYN_REG,&local_14,1);
        if (uVar3 == 0) {
          *param_3 = (uint)local_14;
          uVar3 = __eeprom_st25dv_read(param_1,ST25DV_MAILBOX_RAM_REG,*param_2,0xff);
          iVar2 = 0;
          if (uVar3 != 0) {
            printk("eeprom_st25dv_read ST25DV_REG_MAILBOX_DYN is failed\n");
            iVar2 = -5;
          }
        }
        else {
          printk("eeprom_st25dv_read ST25DV_REG_MB_LEN_DYN is failed\n");
          iVar2 = -4;
        }
      }
      else {
        iVar2 = -3;
      }
    }
    else {
      printk("eeprom_st25dv_read ST25DV_REG_MB_CTRL_DYN is failed\n");
      iVar2 = -2;
    }
  }
  return iVar2;
}


