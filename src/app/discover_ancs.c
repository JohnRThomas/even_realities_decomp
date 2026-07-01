/*
 * Function: discover_ancs
 * Entry:    000188e0
 * Prototype: undefined __stdcall discover_ancs(bt_conn * param_1, int param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void discover_ancs(bt_conn *param_1,int param_2)

{
  char cVar1;
  GlassesState *pGVar2;
  atomic_val_t aVar3;
  undefined *puVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  undefined **ppuVar8;
  bt_uuid *pbVar9;
  bt_uuid local_2c [4];
  undefined4 uStack_28;
  uint8_t local_24 [16];
  
  pGVar2 = __get_dashboard_state();
  if (((*(char *)pGVar2 == '\x02') && (cVar1 = FUN_00033d5c(), cVar1 != '\x01')) &&
     (uVar7 = _ancs_discovery_flags | 1, iVar5 = _ancs_discovery_flags << 0x1f,
     _ancs_discovery_flags = uVar7, -1 < iVar5)) {
    if (((int)(uVar7 << 0x1e) < 0) ||
       ((param_2 != 0 &&
        (aVar3 = atomic_and((atomic_t *)&ancs_discovery_flags,-5), -1 < aVar3 << 0x1d)))) {
      atomic_and((atomic_t *)&ancs_discovery_flags,-2);
      return;
    }
    ppuVar8 = &PTR_DAT_0008bb38;
    pbVar9 = local_2c;
    do {
      puVar4 = *ppuVar8;
      puVar6 = ppuVar8[1];
      ppuVar8 = ppuVar8 + 2;
      *(undefined **)pbVar9 = puVar4;
      *(undefined **)(pbVar9 + 4) = puVar6;
      pbVar9 = pbVar9 + 8;
    } while (ppuVar8 != (undefined **)&DAT_0008bb48);
    pbVar9->type = 'y';
    iVar5 = bt_gatt_dm_start(param_1,local_2c,&discover_ancs_cb,&DAT_20006cc8);
    if (iVar5 != 0) {
      printk("Failed to start discovery for ANCS (err %d)\n",iVar5);
      atomic_and((atomic_t *)&ancs_discovery_flags,-2);
    }
  }
  return;
}


