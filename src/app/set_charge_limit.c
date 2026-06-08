/*
 * Function: set_charge_limit
 * Entry:    00033360
 * Prototype: undefined4 __stdcall set_charge_limit(int param_1, undefined4 param_2, undefined4 * param_3, undefined1 * param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 set_charge_limit(int param_1,undefined4 param_2,undefined4 *param_3,undefined1 *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  GlassesState *pGVar3;
  int iVar4;
  char cVar5;
  undefined1 *puVar6;
  byte bVar7;
  byte bVar8;
  undefined1 auStack_44 [21];
  byte local_2f;
  byte local_2e;
  
  if ((param_3 == (undefined4 *)0x0) || (param_4 == (undefined1 *)0x0)) {
    printk("set_charge_limit para is NULL\n");
    uVar2 = 0xffffffff;
  }
  else {
    puVar6 = (undefined1 *)*param_3;
    *puVar6 = 0x40;
    puVar6[2] = 3;
    puVar6[1] = 1;
    puVar6[3] = 1;
    bVar1 = *(byte *)(param_1 + 4);
    bVar7 = *(byte *)(param_1 + 5);
    bVar8 = bVar1;
    if (99 < bVar1) {
      bVar8 = 100;
    }
    if (99 < bVar7) {
      bVar7 = 100;
    }
    if (bVar1 == 0) {
      __enable_charger();
    }
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0x10d8 = bVar8;
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0x10d9 = bVar7;
    pGVar3 = __get_dashboard_state();
    FUN_0007f556((int)pGVar3);
    cVar5 = '\0';
    do {
      iVar4 = read_usr_settting_from_flash((int)auStack_44);
      if (((iVar4 == 0) && (local_2f == bVar8)) && (local_2e == bVar7)) break;
      cVar5 = cVar5 + '\x01';
      sleep(100);
    } while (cVar5 != '\x05');
    puVar6[4] = cVar5 == '\x05';
    uVar2 = 0;
    *param_4 = 5;
  }
  return uVar2;
}


