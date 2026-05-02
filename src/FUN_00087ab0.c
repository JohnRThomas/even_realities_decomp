/*
 * Function: FUN_00087ab0
 * Entry:    00087ab0
 * Prototype: undefined __stdcall FUN_00087ab0(int param_1, undefined4 param_2, int param_3, char * param_4)
 */


void FUN_00087ab0(int param_1,undefined4 param_2,int param_3,char *param_4)

{
  int iVar1;
  nrfx_err_t nVar2;
  undefined2 local_12 [3];
  
  iVar1 = FUN_00065318(param_3,param_4,local_12);
  if ((iVar1 != -0x16) &&
     (nVar2 = nrfx_gpiote_channel_get(*(nrfx_gpiote_pin_t *)(param_1 + 0x1c),&Reset),
     -1 < (int)nVar2)) {
    FUN_000875be(*(nrfx_twim_t **)(param_1 + 0x1c),(nrfx_twim_xfer_desc_t *)&Reset,0xf);
  }
  return;
}


