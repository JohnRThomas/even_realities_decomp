/*
 * Function: FUN_0002dea8
 * Entry:    0002dea8
 * Prototype: undefined4 __stdcall FUN_0002dea8(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 FUN_0002dea8(void)

{
  undefined4 *puVar1;
  GlassesState *pGVar2;
  uint uVar3;
  char *extraout_r1;
  char *extraout_r1_00;
  char *pcVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar5;
  short sVar6;
  int iVar7;
  
  sVar6 = 1000;
  DAT_20019a6d = 1;
  do {
    puVar1 = FUN_00035260(10);
    if ((*(char *)(puVar1 + 4) == '\0') || (*(char *)(puVar1 + 3) == '\0')) break;
    sVar6 = sVar6 + -1;
    z_impl_k_sleep(0x21,0);
  } while (sVar6 != 0);
  pGVar2 = __get_dashboard_state();
  uVar3 = FUN_000294d0((int)pGVar2,10,(void *)0x0,0);
  pcVar4 = extraout_r1;
  uVar5 = extraout_r2;
  if ((uVar3 < 2000) &&
     (pGVar2 = __get_dashboard_state(), pcVar4 = extraout_r1_00, uVar5 = extraout_r2_00,
     pGVar2->field_0x106e == '\x02')) {
    iVar7 = 0;
    do {
      if (DAT_20019a5b != '\0') goto LAB_0002df12;
      iVar7 = iVar7 + 1;
      z_impl_k_sleep(0xccd,0);
    } while (iVar7 != 10);
    if (DAT_20019a5b != '\0') {
LAB_0002df12:
      DAT_20019a5b = 0;
      pGVar2 = __get_dashboard_state();
      uVar3 = FUN_00035310();
      pGVar2->field_0xdd = (char)uVar3;
      DAT_20019a6d = 0;
      return 0;
    }
  }
  else if (BLE_DEBUG == 0) {
    printk("#########timeout,should retry !");
  }
  else {
    ble_printk("#########timeout,should retry !",pcVar4,uVar5,BLE_DEBUG);
  }
  DAT_20019a6d = 0;
  return 0xffffffff;
}


