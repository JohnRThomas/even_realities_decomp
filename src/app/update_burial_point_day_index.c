/*
 * Function: update_burial_point_day_index
 * Entry:    0004d5d8
 * Prototype: undefined4 __stdcall update_burial_point_day_index(void)
 */


undefined4 update_burial_point_day_index(void)

{
  uint uVar1;
  uint uVar2;
  GlassesState *pGVar3;
  GlassesState *pGVar4;
  undefined4 extraout_r2;
  int iVar5;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  
  uVar2 = FUN_00080724();
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  FUN_0004d1e0(uVar2,(undefined2 *)&local_24);
  if (((local_24 & 0xffff) < 0x7e8) || (((local_24 & 0xffff) == 0x7e8 && (local_24._2_2_ < 8)))) {
    if (1 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): burial point date was not init!\n");
      }
      else {
        ble_printk("%s(): burial point date was not init!\n","update_burial_point_day_index",
                   extraout_r2,BLE_DEBUG);
      }
    }
    return 0xffffffff;
  }
  pGVar3 = __get_dashboard_state();
  if (6 < (byte)pGVar3->field_0x113d) {
    pGVar3 = __get_dashboard_state();
    pGVar3->field_0x113d = 0;
  }
  pGVar3 = __get_dashboard_state();
  pGVar4 = __get_dashboard_state();
  if (*(short *)(&pGVar3->field_0x1140 + (uint)(byte)pGVar4->field_0x113d * 0xc) == (short)local_24)
  {
    pGVar3 = __get_dashboard_state();
    pGVar4 = __get_dashboard_state();
    if ((byte)(&pGVar3->field_0x1142)[(uint)(byte)pGVar4->field_0x113d * 0xc] == local_24._2_2_) {
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      if ((uint)(byte)(&pGVar3->field_0x1143)[(uint)(byte)pGVar4->field_0x113d * 0xc] ==
          (local_20 & 0xffff)) {
        return 0;
      }
    }
  }
  uVar2 = 0;
  do {
    pGVar3 = __get_dashboard_state();
    if ((uint)(byte)pGVar3->field_0x113d != (uVar2 & 0xff)) {
      pGVar3 = __get_dashboard_state();
      iVar5 = uVar2 * 0xc;
      if (*(short *)(&pGVar3->field_0x1140 + iVar5) == (short)local_24) {
        pGVar3 = __get_dashboard_state();
        if (((byte)(&pGVar3->field_0x1142)[iVar5] == local_24._2_2_) &&
           (pGVar3 = __get_dashboard_state(),
           (uint)(byte)(&pGVar3->field_0x1143)[iVar5] == (local_20 & 0xffff))) {
          pGVar3 = __get_dashboard_state();
          pGVar3->field_0x113d = (char)uVar2;
          goto LAB_0004d6d4;
        }
      }
    }
    uVar2 = uVar2 + 1;
    if (uVar2 == 7) {
      pGVar3 = __get_dashboard_state();
      pGVar3->field_0x113d = pGVar3->field_0x113d + '\x01';
      pGVar3 = __get_dashboard_state();
      if (6 < (byte)pGVar3->field_0x113d) {
        pGVar3 = __get_dashboard_state();
        pGVar3->field_0x113d = 0;
      }
LAB_0004d6d4:
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar2 = local_24;
      *(short *)(&pGVar3->field_0x1140 + (uint)(byte)pGVar4->field_0x113d * 0xc) = (short)local_24;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar1 = local_20;
      (&pGVar3->field_0x1142)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)(uVar2 >> 0x10);
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      (&pGVar3->field_0x1143)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)uVar1;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x1144 + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x1148 + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar2 = local_24;
      *(short *)(&pGVar3->field_0x1194 + (uint)(byte)pGVar4->field_0x113d * 0xc) = (short)local_24;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar1 = local_20;
      (&pGVar3->field_0x1196)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)(uVar2 >> 0x10);
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      (&pGVar3->field_0x1197)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)uVar1;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x1198 + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x119c + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar2 = local_24;
      *(short *)(&pGVar3->field_0x11f0 + (uint)(byte)pGVar4->field_0x113d * 0xc) = (short)local_24;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      uVar1 = local_20;
      (&pGVar3->field_0x11f2)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)(uVar2 >> 0x10);
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      (&pGVar3->field_0x11f3)[(uint)(byte)pGVar4->field_0x113d * 0xc] = (char)uVar1;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x11f4 + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      pGVar3 = __get_dashboard_state();
      pGVar4 = __get_dashboard_state();
      *(undefined4 *)(&pGVar3->field_0x11f8 + (uint)(byte)pGVar4->field_0x113d * 0xc) = 0;
      return 0;
    }
  } while( true );
}


