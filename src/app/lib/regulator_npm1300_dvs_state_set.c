/*
 * Function: regulator_npm1300_dvs_state_set
 * Entry:    00065268
 * Prototype: int __stdcall regulator_npm1300_dvs_state_set(int param_1, int param_2)
 */


/* exclude_from_export */

int regulator_npm1300_dvs_state_set(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  char *test;
  char *file;
  uint uVar3;
  int line;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = 0;
  iVar6 = *(int *)(param_1 + 4);
  do {
    iVar1 = *(int *)(iVar6 + 4);
    if (iVar1 != 0) {
      uVar2 = 1 << *(sbyte *)(iVar6 + 8);
      uVar3 = param_2 >> (uVar5 & 0xff) & 1;
      if ((uVar2 & **(uint **)(iVar1 + 4)) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",0x64f);
        _ASSERT("\tUnsupported pin\n",test,file,line);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      if ((uVar2 & **(uint **)(iVar1 + 0x10)) != 0) {
        uVar3 = uVar3 ^ 1;
      }
      if (uVar3 == 0) {
        pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
      }
      else {
        pcVar4 = *(code **)(*(int *)(iVar1 + 8) + 0xc);
      }
      iVar1 = (*pcVar4)();
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    uVar5 = uVar5 + 1;
    iVar6 = iVar6 + 8;
    if (uVar5 == 5) {
      return 0;
    }
  } while( true );
}


