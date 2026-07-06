/*
 * Function: FUN_0002dea8
 * Entry:    0002dea8
 * Prototype: undefined4 __stdcall FUN_0002dea8(void)
 */


undefined4 FUN_0002dea8(void)

{
  undefined4 *puVar1;
  GlassesState *pGVar2;
  uint uVar3;
  short sVar4;
  int iVar5;
  
  sVar4 = 1000;
  DAT_20019a6d = 1;
  do {
    puVar1 = FUN_00035260(10);
    if ((*(char *)(puVar1 + 4) == '\0') || (*(char *)(puVar1 + 3) == '\0')) break;
    sVar4 = sVar4 + -1;
    z_impl_k_sleep(0x21,0);
  } while (sVar4 != 0);
  pGVar2 = __get_dashboard_state();
  uVar3 = FUN_000294d0((int)pGVar2,10,(void *)0x0,0);
  if ((uVar3 < 2000) && (pGVar2 = __get_dashboard_state(), pGVar2->field_0x106e == '\x02')) {
    iVar5 = 0;
    do {
      if (DAT_20019a5b != '\0') goto LAB_0002df12;
      iVar5 = iVar5 + 1;
      z_impl_k_sleep(0xccd,0);
    } while (iVar5 != 10);
    if (DAT_20019a5b != '\0') {
LAB_0002df12:
      DAT_20019a5b = 0;
      pGVar2 = __get_dashboard_state();
      uVar3 = FUN_00035310();
      pGVar2->field20_0xc8[0x15] = (char)uVar3;
      DAT_20019a6d = 0;
      return 0;
    }
  }
  else if (BLE_DEBUG == 0) {
    printk("#########timeout,should retry !");
  }
  else {
    ble_printk("#########timeout,should retry !");
  }
  DAT_20019a6d = 0;
  return 0xffffffff;
}


