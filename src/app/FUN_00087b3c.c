/*
 * Function: FUN_00087b3c
 * Entry:    00087b3c
 * Prototype: nrfx_err_t __stdcall FUN_00087b3c(int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, uint32_t param_5)
 */


/* WARNING: Removing unreachable block (ram,0x000654ec) */

nrfx_err_t
FUN_00087b3c(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,uint32_t param_5)

{
  nrfx_err_t nVar1;
  device *dev;
  uint16_t dev_addr;
  int iVar2;
  
  dev = *(device **)(param_1 + 4);
  switch((uint8_t *)(uint)*(byte *)&dev[1].api) {
  case (uint8_t *)0x0:
    dev_addr = 0;
    break;
  case (uint8_t *)0x1:
    dev_addr = 1;
    break;
  case (uint8_t *)0x2:
    iVar2 = 0;
    goto LAB_00087b5c;
  case (uint8_t *)0x3:
    iVar2 = 1;
LAB_00087b5c:
    nVar1 = nrfx_twim_xfer((nrfx_twim_t *)dev[1].config,(nrfx_twim_xfer_desc_t *)&NMI,iVar2 + 0xc);
    if (-1 < (int)nVar1) {
      nVar1 = 0;
      *param_2 = " gyroscope full-scale\r\n";
    }
    return nVar1;
  default:
    return 0xffffffed;
  }
  nVar1 = i2c_burst_read(dev,dev_addr,(uint8_t)param_2,(uint8_t *)(uint)*(byte *)&dev[1].api,param_5
                        );
  return nVar1;
}


