/*
 * Function: bt_foreach_bond
 * Entry:    00061980
 * Prototype: void __stdcall bt_foreach_bond(uint8_t id, void * func, void * user_data)
 */


/* exclude_from_export_ai */

void bt_foreach_bond(uint8_t id,void *func,void *user_data)

{
  uint uVar1;
  undefined8 local_20;
  void *pvStack_18;
  
  uVar1 = (uint)id;
  local_20._4_4_ = func;
  pvStack_18 = user_data;
  if (func == (void *)0x0) {
    local_20._0_4_ = uVar1;
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","func != ((void *)0)",
            "WEST_TOPDIR/zephyr/subsys/bluetooth/host/keys.c",160);
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  if (((short)key_pool.ltk_rand0 != 0) && (key_pool.id == uVar1)) {
    local_20._0_4_ = key_pool.addr._0_4_;
    local_20._7_1_ = (undefined1)((uint)func >> 0x18);
    local_20._4_3_ = CONCAT12(key_pool.addr.a.val[5],key_pool.addr.a.val._3_2_);
    (*func)(&local_20,user_data);
  }
  if ((DAT_2000b996 != 0) && (DAT_2000b988 == uVar1)) {
    local_20._0_4_ = DAT_2000b989;
    local_20._4_3_ = CONCAT12(DAT_2000b98f,DAT_2000b98d);
    (*func)(&local_20,user_data);
  }
  return;
}


