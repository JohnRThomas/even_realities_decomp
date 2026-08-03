/*
 * Function: bt_gatt_clear
 * Entry:    0005fb84
 * Prototype: int __stdcall bt_gatt_clear(uint8_t id, bt_addr_le_t * addr)
 */


/* exclude_from_export_ai */

int bt_gatt_clear(uint8_t id,bt_addr_le_t *addr)

{
  bool bVar1;
  int iVar2;
  gatt_cf_cfg *cfg;
  int *piVar3;
  bt_gatt_subscribe_params *params;
  gatt_sub *sub;
  bt_addr_le_t *b;
  bt_addr_le_t *local_20;
  uint8_t local_1c;
  undefined3 uStack_1b;
  
  _local_1c = CONCAT31((int3)((uint)addr >> 8),id);
  local_20 = addr;
  bt_gatt_foreach_attr(1,0xffff,(bt_gatt_attr_func_t)0x5d581,&local_20);
  iVar2 = bt_settings_delete_ccc(id,addr);
  if ((-1 < iVar2) && (iVar2 = bt_gatt_clear_sc(id,addr), -1 < iVar2)) {
    cfg = find_cf_cfg_by_addr(id,addr);
    if (cfg != (gatt_cf_cfg *)0x0) {
      clear_cf_cfg(cfg);
    }
    iVar2 = bt_settings_delete_ccc(id,addr);
    if (-1 < iVar2) {
      iVar2 = 0;
      b = (bt_addr_le_t *)&DAT_2000b8f9;
      do {
        if ((b[-1].a.val[5] == id) && (bVar1 = bt_addr_le_eq(addr,b), bVar1)) {
          sub = (gatt_sub *)(&DAT_2000b8f8 + iVar2);
          piVar3 = *(int **)((int)&DAT_2000b900 + iVar2);
          if (piVar3 != (int *)0x0) {
            params = (bt_gatt_subscribe_params *)*piVar3;
            if (params != (bt_gatt_subscribe_params *)0x0) {
              params = params + -6;
            }
            *(undefined2 *)(piVar3 + -2) = 0;
            gatt_sub_remove((bt_conn *)0x0,sub,(sys_snode_t *)0x0,piVar3 + -6);
            if (params != (bt_gatt_subscribe_params *)0x0) {
              while (iVar2 = params[6], iVar2 != 0) {
                *(undefined2 *)(params + 4) = 0;
                gatt_sub_remove((bt_conn *)0x0,sub,(sys_snode_t *)0x0,params);
                params = (bt_gatt_subscribe_params *)(iVar2 + -0x18);
              }
              *(undefined2 *)(params + 4) = 0;
              gatt_sub_remove((bt_conn *)0x0,sub,(sys_snode_t *)0x0,params);
            }
          }
          break;
        }
        iVar2 = iVar2 + 0x10;
        b = (bt_addr_le_t *)(b[2].a.val + 1);
      } while (iVar2 != 0x30);
      iVar2 = 0;
    }
  }
  return iVar2;
}


