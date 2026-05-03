/*
 * Function: FUN_00087a7c
 * Entry:    00087a7c
 * Prototype: undefined __stdcall FUN_00087a7c(int param_1, undefined4 param_2, int param_3, char * param_4)
 */


void FUN_00087a7c(int param_1,undefined4 param_2,int param_3,char *param_4)

{
  int iVar1;
  undefined4 uStack_14;
  int iStack_10;
  
  uStack_14 = param_2;
  iStack_10 = param_3;
  iVar1 = FUN_00065318(param_3,param_4,(undefined2 *)((int)&uStack_14 + 2));
  if (iVar1 != -0x16) {
    nrfx_gpiote_channel_get(*(nrfx_gpiote_pin_t *)(param_1 + 0x1c),&NMI);
    return;
  }
  return;
}


