/*
 * Function: FUN_00065268
 * Entry:    00065268
 * Prototype: int __stdcall FUN_00065268(int param_1, int param_2)
 */


int FUN_00065268(int param_1,int param_2)

{
  int iVar1;
  int extraout_r0;
  uint uVar2;
  char *test;
  uint extraout_r1;
  char *file;
  uint uVar3;
  int line;
  uint extraout_r3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *extraout_r12;
  
  uVar5 = 0;
  iVar6 = *(int *)(param_1 + 4);
  do {
    iVar1 = *(int *)(iVar6 + 4);
    if (iVar1 != 0) {
      uVar2 = 1 << *(sbyte *)(iVar6 + 8);
      puVar7 = *(uint **)(iVar1 + 0x10);
      uVar3 = param_2 >> (uVar5 & 0xff) & 1;
      if ((uVar2 & **(uint **)(iVar1 + 4)) == 0) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
                "(cfg->port_pin_mask & (gpio_port_pins_t)(1UL << (pin))) != 0U",
                "WEST_TOPDIR/zephyr/include/zephyr/drivers/gpio.h",0x64f);
        _ASSERT("\tUnsupported pin\n",test,file,line);
        k_panic();
        iVar1 = extraout_r0;
        uVar2 = extraout_r1;
        uVar3 = extraout_r3;
        puVar7 = extraout_r12;
      }
      if ((uVar2 & *puVar7) != 0) {
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


