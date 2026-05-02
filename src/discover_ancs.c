/*
 * Function: discover_ancs
 * Entry:    000188e0
 * Prototype: undefined __stdcall discover_ancs(bt_conn * param_1, int param_2)
 */


void discover_ancs(bt_conn *param_1,int param_2)

{
  char cVar1;
  GlassesState *pGVar2;
  atomic_val_t aVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  bt_uuid *pbVar9;
  bt_uuid local_2c [4];
  undefined4 uStack_28;
  uint8_t local_24 [16];
  
  pGVar2 = __get_dashboard_state();
  if (((*(char *)pGVar2 == '\x02') && (cVar1 = FUN_00033d5c(), cVar1 != '\x01')) &&
     (uVar7 = GLOBAL_STATE.sem_8.count | 1, iVar5 = GLOBAL_STATE.sem_8.count << 0x1f,
     GLOBAL_STATE.sem_8.count = uVar7, -1 < iVar5)) {
    if (((int)(uVar7 << 0x1e) < 0) ||
       ((param_2 != 0 &&
        (aVar3 = atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-5), -1 < aVar3 << 0x1d)))) {
      atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-2);
      return;
    }
    puVar8 = &DAT_0008bb38;
    pbVar9 = local_2c;
    do {
      uVar4 = *puVar8;
      uVar6 = puVar8[1];
      puVar8 = puVar8 + 2;
      *(undefined4 *)pbVar9 = uVar4;
      *(undefined4 *)(pbVar9 + 4) = uVar6;
      pbVar9 = pbVar9 + 8;
    } while (puVar8 != (undefined4 *)&DAT_0008bb48);
    pbVar9->type = 'y';
    iVar5 = bt_gatt_dm_start(param_1,local_2c,&discover_ancs_cb,&GLOBAL_STATE.field_0xec);
    if (iVar5 != 0) {
      printk("Failed to start discovery for ANCS (err %d)\n",iVar5);
      atomic_and((atomic_t *)&GLOBAL_STATE.sem_8.count,-2);
    }
  }
  return;
}


