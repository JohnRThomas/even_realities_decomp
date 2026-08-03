/*
 * Function: clk_init
 * Entry:    00063830
 * Prototype: void __stdcall clk_init(void)
 */


/* exclude_from_export */

void clk_init(void)

{
  nrfx_err_t nVar1;
  int in_r0;
  int iVar2;
  int iVar3;
  int iVar4;
  
  z_arm_irq_priority_set(5,1,0);
  nVar1 = nrfx_clock_init((nrfx_clock_event_handler_t *)0x638d9);
  if ((undefined1 *)(uint)nVar1 == &DAT_0bad0000) {
    Peripherals::CLOCK_S._1372_4_ = 0x9ba5;
    nrfx_clock_enable();
    iVar3 = 0;
    do {
      iVar4 = *(int *)(in_r0 + 0x10);
      iVar2 = onoff_manager_init((onoff_manager *)(iVar4 + iVar3 * 0x20),
                                 (onoff_transitions *)&PTR_onoff_start_1_0008f18c);
      if (iVar2 < 0) {
        return;
      }
      iVar2 = iVar3 * 0xc;
      iVar3 = iVar3 + 1;
      *(undefined4 *)(iVar2 + iVar4 + 0x88) = 1;
    } while (iVar3 != 4);
  }
  return;
}


