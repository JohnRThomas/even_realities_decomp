/*
 * Function: adc_nrfx_read_async
 * Entry:    00062c78
 * Prototype: undefined __stdcall adc_nrfx_read_async(undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* exclude_from_export */

void adc_nrfx_read_async(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = Peripherals::SAADC_S.EVENTS_END;
  if (uVar2 == 0) {
    uVar2 = Peripherals::SAADC_S.EVENTS_CALIBRATEDONE;
    if (uVar2 == 0) {
      return;
    }
    Peripherals::SAADC_S.EVENTS_CALIBRATEDONE = 0;
    uVar2 = Peripherals::SAADC_S.EVENTS_CALIBRATEDONE;
    Peripherals::SAADC_S.TASKS_STOP = 1;
    Peripherals::SAADC_S.TASKS_START = 1;
    Peripherals::SAADC_S.TASKS_SAMPLE = 1;
    return;
  }
  Peripherals::SAADC_S.EVENTS_END = 0;
  uVar2 = Peripherals::SAADC_S.EVENTS_END;
  Peripherals::SAADC_S.TASKS_STOP = 1;
  Peripherals::SAADC_S.ENABLE = 0;
  if (DAT_20002204 == 0) goto LAB_00062d0c;
  if (DAT_2000221c == (code *)0x0) {
LAB_00062cb6:
    if (DAT_20002228 < (ushort)DAT_20002224) {
      DAT_20002228 = DAT_20002228 + 1;
      iVar3 = DAT_5000e62c;
      uVar2 = DAT_5000e634;
      DAT_5000e62c = iVar3 + (uVar2 & 0xffff) * 2;
LAB_00062cdc:
      if ((DAT_20002218 != 0) &&
         (iVar3 = DAT_20002190 + -1, bVar1 = DAT_20002190 < 2, DAT_20002190 = iVar3, bVar1)) {
        return;
      }
      adc_context_start_sampling((adc_context *)&DAT_20002190);
      return;
    }
  }
  else {
    iVar3 = (*DAT_2000221c)(param_1,&DAT_20002204,DAT_20002228,DAT_2000221c,param_4);
    if (iVar3 == 1) goto LAB_00062cdc;
    if (iVar3 != 2) goto LAB_00062cb6;
  }
  if (DAT_20002218 != 0) {
    z_impl_k_timer_stop((k_timer *)&DAT_20002198);
  }
LAB_00062d0c:
  k_sem_give((k_sem *)&DAT_200021e8);
  return;
}


