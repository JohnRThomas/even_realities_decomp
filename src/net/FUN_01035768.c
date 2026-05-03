/*
 * Function: FUN_01035768
 * Entry:    01035768
 * Prototype: undefined1 * __stdcall FUN_01035768(int * param_1, uint * param_2, undefined4 param_3)
 */


undefined1 * FUN_01035768(int *param_1,uint *param_2,undefined4 param_3)

{
  undefined1 *puVar1;
  uint *extraout_r1;
  TIMER0_NS *pTVar2;
  uint uVar3;
  
  uVar3 = (uint)*(byte *)(param_1 + 1);
  if ((&DAT_21004b00)[uVar3 * 0xc] == '\0') {
    (&DAT_21004af8)[uVar3 * 3] = param_3;
    if (param_2 == (uint *)0x0) {
      puVar1 = &DAT_0bad0000;
    }
    else {
      (&DAT_21004afc)[uVar3 * 3] = param_2[2];
      pTVar2 = (TIMER0_NS *)*param_1;
      if ((((pTVar2 != &Peripherals::TIMER0_NS) && (pTVar2 != (TIMER0_NS *)&Peripherals::TIMER1_NS))
          && (pTVar2 != (TIMER0_NS *)&Peripherals::TIMER2_NS)) ||
         (pTVar2 = (TIMER0_NS *)(uint)*(byte *)((int)param_2 + 5), (TIMER0_NS *)0x3 < pTVar2)) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                     "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_timer.c",0x8e,pTVar2);
        param_1 = (int *)FUN_0103a370();
        param_2 = extraout_r1;
      }
      puVar1 = FUN_010356e4(param_1,param_2);
    }
    (&DAT_21004b00)[uVar3 * 0xc] = puVar1 == &DAT_0bad0000;
  }
  else {
    puVar1 = &DAT_0bad0005;
  }
  return puVar1;
}


