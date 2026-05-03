/*
 * Function: ?_set_charger_status
 * Entry:    0002ff60
 * Prototype: undefined4 __stdcall ?_set_charger_status(void)
 */


/* WARNING: Removing unreachable block (ram,0x0002ff9e) */

undefined4 __set_charger_status(void)

{
  nrfx_err_t nVar1;
  undefined4 uVar2;
  
  nVar1 = nrfx_twim_xfer((nrfx_twim_t *)&DAT_0008b430,(nrfx_twim_xfer_desc_t *)0x3,0x34);
  if ((int)nVar1 < 0) {
    printk("Could not get charger status\n");
    uVar2 = 0xffffffff;
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}


