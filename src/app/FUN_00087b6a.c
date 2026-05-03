/*
 * Function: FUN_00087b6a
 * Entry:    00087b6a
 * Prototype: nrfx_err_t __stdcall FUN_00087b6a(int param_1, int * param_2, int param_3)
 */


nrfx_err_t FUN_00087b6a(int param_1,int *param_2,int param_3)

{
  int iVar1;
  nrfx_err_t nVar2;
  
  if (*param_2 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  switch(*(undefined1 *)(iVar1 + 0x20)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto joined_r0x00087bb4;
  case 3:
joined_r0x00087bb4:
    if (param_3 != 0) {
      return 0xffffff7a;
    }
    nVar2 = nrfx_gpiote_channel_get(*(nrfx_gpiote_pin_t *)(iVar1 + 0x1c),&NMI);
    return nVar2;
  default:
    return 0xffffffed;
  }
  nVar2 = FUN_000879ac(iVar1);
  return nVar2;
}


