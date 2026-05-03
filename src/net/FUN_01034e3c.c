/*
 * Function: FUN_01034e3c
 * Entry:    01034e3c
 * Prototype: uint __stdcall FUN_01034e3c(uint param_1, int param_2, uint param_3, int * param_4)
 */


uint FUN_01034e3c(uint param_1,int param_2,uint param_3,int *param_4)

{
  int iVar1;
  int extraout_r1;
  int *extraout_r3;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = 0;
  do {
    iVar1 = FUN_01034e10(uVar2 & 0xff,param_2,param_3,param_4);
    param_3 = 1 << (iVar1 - 0x100U >> 2 & 0xff);
    param_2 = extraout_r1;
    param_4 = extraout_r3;
    if ((param_1 & param_3) != 0) {
      param_4 = (int *)((int)&Peripherals::GPIOTE_NS.TASKS_OUT_0_ + iVar1);
      param_2 = *param_4;
      if (param_2 != 0) {
        *param_4 = 0;
        param_4 = (int *)*param_4;
        uVar3 = uVar3 | param_3;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 8);
  uVar2 = Peripherals::GPIOTE_NS.EVENTS_PORT;
  if (uVar2 != 0) {
    Peripherals::GPIOTE_NS.EVENTS_PORT = 0;
    uVar2 = Peripherals::GPIOTE_NS.EVENTS_PORT;
    uVar3 = uVar3 | 0x80000000;
  }
  return uVar3;
}


