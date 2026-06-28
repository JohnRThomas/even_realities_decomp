/*
 * Function: update_burial_point_day_index
 * Entry:    0004d5d8
 * Prototype: int __stdcall update_burial_point_day_index(void)
 */


int update_burial_point_day_index(void)

{
  uint uVar1;
  dashboard_ts_context *dashboard_ts_ctx;
  GlassesState *pGVar2;
  GlassesState *pGVar3;
  undefined4 extraout_r2;
  uint uVar4;
  int iVar5;
  undefined4 burial_point_year;
  uint local_20;
  undefined4 local_1c;
  
  dashboard_ts_ctx = __get_dashboard_tx_ctx();
  burial_point_year = 0;
  local_20 = 0;
  local_1c = 0;
  __init_burial_point_date(dashboard_ts_ctx,(undefined2 *)&burial_point_year);
  if (((burial_point_year & 0xffff) < 2024) ||
     (((burial_point_year & 0xffff) == 2024 && (burial_point_year._2_2_ < 8)))) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): burial point date was not init!\n");
      }
      else {
        ble_printk("%s(): burial point date was not init!\n","update_burial_point_day_index",
                   extraout_r2,BLE_DEBUG);
      }
    }
    return -1;
  }
  pGVar2 = __get_dashboard_state();
  if (6 < (byte)(pGVar2->__burial_point_ctx).field_0x15) {
    pGVar2 = __get_dashboard_state();
    (pGVar2->__burial_point_ctx).field_0x15 = 0;
  }
  pGVar2 = __get_dashboard_state();
  pGVar3 = __get_dashboard_state();
  if (*(short *)(&(pGVar2->__burial_point_ctx).field_0x18 +
                (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) ==
      (short)burial_point_year) {
    pGVar2 = __get_dashboard_state();
    pGVar3 = __get_dashboard_state();
    if ((byte)(&(pGVar2->__burial_point_ctx).field_0x1a)
              [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] == burial_point_year._2_2_
       ) {
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      if ((uint)(byte)(&(pGVar2->__burial_point_ctx).field_0x1b)
                      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] ==
          (local_20 & 0xffff)) {
        return 0;
      }
    }
  }
  uVar4 = 0;
  do {
    pGVar2 = __get_dashboard_state();
    if ((uint)(byte)(pGVar2->__burial_point_ctx).field_0x15 != (uVar4 & 0xff)) {
      pGVar2 = __get_dashboard_state();
      iVar5 = uVar4 * 0xc;
      if (*(short *)(&(pGVar2->__burial_point_ctx).field_0x18 + iVar5) == (short)burial_point_year)
      {
        pGVar2 = __get_dashboard_state();
        if (((byte)(&(pGVar2->__burial_point_ctx).field_0x1a)[iVar5] == burial_point_year._2_2_) &&
           (pGVar2 = __get_dashboard_state(),
           (uint)(byte)(&(pGVar2->__burial_point_ctx).field_0x1b)[iVar5] == (local_20 & 0xffff))) {
          pGVar2 = __get_dashboard_state();
          (pGVar2->__burial_point_ctx).field_0x15 = (char)uVar4;
          goto LAB_0004d6d4;
        }
      }
    }
    uVar4 = uVar4 + 1;
    if (uVar4 == 7) {
      pGVar2 = __get_dashboard_state();
      (pGVar2->__burial_point_ctx).field_0x15 = (pGVar2->__burial_point_ctx).field_0x15 + '\x01';
      pGVar2 = __get_dashboard_state();
      if (6 < (byte)(pGVar2->__burial_point_ctx).field_0x15) {
        pGVar2 = __get_dashboard_state();
        (pGVar2->__burial_point_ctx).field_0x15 = 0;
      }
LAB_0004d6d4:
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar4 = burial_point_year;
      *(short *)(&(pGVar2->__burial_point_ctx).field_0x18 +
                (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) =
           (short)burial_point_year;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar1 = local_20;
      (&(pGVar2->__burial_point_ctx).field_0x1a)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)(uVar4 >> 0x10);
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      (&(pGVar2->__burial_point_ctx).field_0x1b)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)uVar1;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0x1c +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0x20 +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar4 = burial_point_year;
      *(short *)(&(pGVar2->__burial_point_ctx).field_0x6c +
                (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) =
           (short)burial_point_year;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar1 = local_20;
      (&(pGVar2->__burial_point_ctx).field_0x6e)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)(uVar4 >> 0x10);
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      (&(pGVar2->__burial_point_ctx).field_0x6f)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)uVar1;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0x70 +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0x74 +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar4 = burial_point_year;
      *(short *)(&(pGVar2->__burial_point_ctx).field_0xc8 +
                (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) =
           (short)burial_point_year;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      uVar1 = local_20;
      (&(pGVar2->__burial_point_ctx).field_0xca)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)(uVar4 >> 0x10);
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      (&(pGVar2->__burial_point_ctx).field_0xcb)
      [(uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc] = (char)uVar1;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0xcc +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      pGVar2 = __get_dashboard_state();
      pGVar3 = __get_dashboard_state();
      *(undefined4 *)
       (&(pGVar2->__burial_point_ctx).field_0xd0 +
       (uint)(byte)(pGVar3->__burial_point_ctx).field_0x15 * 0xc) = 0;
      return 0;
    }
  } while( true );
}


