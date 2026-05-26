/*
 * Function: $_?_FUN_000638d8
 * Entry:    000638d8
 * Prototype: undefined __stdcall $_?_FUN_000638d8(undefined4 param_1)
 */


void ____FUN_000638d8(undefined4 param_1)

{
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = 0;
    if ((DAT_2000bb08 & 7) != 0) {
      return;
    }
    break;
  case 1:
    iVar1 = 1;
    break;
  default:
    do {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
              "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x272);
LAB_0006391c:
      k_panic();
    } while( true );
  case 4:
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
            "WEST_TOPDIR/zephyr/drivers/clock_control/clock_control_nrf.c",0x26e);
    goto LAB_0006391c;
  case 5:
    iVar1 = 3;
    break;
  case 6:
    iVar1 = 2;
  }
  clkstarted_handle(iVar1);
  return;
}


