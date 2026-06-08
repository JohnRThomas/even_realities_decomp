/*
 * Function: find_chinese_bitmap_by_unicode
 * Entry:    0004b1b4
 * Prototype: undefined4 __stdcall find_chinese_bitmap_by_unicode(int param_1, short param_2, short param_3)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

undefined4 find_chinese_bitmap_by_unicode(int param_1,short param_2,short param_3)

{
  undefined4 uVar1;
  GlassesState *pGVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  uint n;
  undefined *puVar4;
  undefined1 *buf;
  code *pcVar5;
  uint uVar6;
  undefined1 auStack_28 [4];
  ushort local_24;
  ushort local_22;
  
  n = (uint)(ushort)(param_2 * param_3);
  buf = auStack_28 + -(n + 7 & 0xfffffff8);
  if (param_1 - 0x20U < 0x60) {
    uVar1 = FUN_00080f9e();
  }
  else {
    pGVar2 = __get_dashboard_state();
    if (*(int *)&pGVar2->field_0x1044 == 0) {
      buf = (undefined1 *)0x0;
    }
    else {
      pGVar2 = __get_dashboard_state();
      pcVar5 = *(code **)&pGVar2->field_0x1044;
      pGVar2 = __get_dashboard_state();
      iVar3 = (*pcVar5)(pGVar2,&DAT_00140000 + (param_1 + -0xa4) * 4,&local_24);
      if (iVar3 != 0) {
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): read flash fail\n\n");
          }
          else {
            ble_printk("%s(): read flash fail\n\n","find_chinese_bitmap_by_unicode",extraout_r2,
                       BLE_DEBUG);
          }
        }
        return 0;
      }
      printk("unicode=%x, offset=%d\n",(uint)local_24,(uint)local_22);
      uVar6 = (uint)((ushort)(param_2 * param_3) >> 2);
      puVar4 = (undefined *)(uVar6 * local_22);
      if (n == 0x1b0) {
        puVar4 = &UNK_000cf120 + (int)puVar4;
      }
      memset(buf,0,n);
      pGVar2 = __get_dashboard_state();
      pcVar5 = *(code **)&pGVar2->field_0x1044;
      pGVar2 = __get_dashboard_state();
      iVar3 = (*pcVar5)(pGVar2,puVar4 + 0x200000,buf,uVar6);
      if ((iVar3 != 0) && (0 < LOG_LEVEL)) {
        if (BLE_DEBUG == 0) {
          printk("%s(): read flash fail: %d\n\n");
        }
        else {
          ble_printk("%s(): read flash fail: %d\n\n","find_chinese_bitmap_by_unicode",iVar3,
                     BLE_DEBUG);
        }
      }
    }
    FUN_0004b194((int)buf,n,0x2001dd06);
    uVar1 = extraout_r2_00;
  }
  return uVar1;
}


