/*
 * Function: bt_start
 * Entry:    000194b4
 * Prototype: int __stdcall bt_start(void)
 */


int bt_start(void)

{
  longlong lVar1;
  bool bVar2;
  char cVar3;
  GlassesState *pGVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  ulonglong uVar10;
  bt_le_adv_param local_34;
  
  while (DAT_20010960 != '\0') {
    sleep(1);
  }
  DAT_20010960 = 1;
  pGVar4 = __get_dashboard_state();
  if ((pGVar4->field_0x106c == '\x02') ||
     (pGVar4 = __get_dashboard_state(), pGVar4->field_0x106c == '\0')) {
    DAT_20010960 = 0;
    return 0;
  }
  DAT_20002360 = 0x14ff;
  bVar2 = __is_master();
  if (bVar2) {
    DAT_20010961 = 1;
  }
  else {
    DAT_20010961 = 2;
  }
  DAT_20002364 = &DAT_20010961;
  pcVar5 = (char *)FUN_00025338();
  __strcpy_chk(&DAT_20010962,pcVar5,0x13);
  pGVar4 = __get_dashboard_state();
  printk("c->esb_channel %d\r\n",(uint)(byte)pGVar4->field_0x2);
  bVar2 = __is_master();
  if (bVar2) {
    cVar3 = FUN_00033d5c();
    if (cVar3 != '\x01') {
      pGVar4 = __get_dashboard_state();
      if (pGVar4->field_0x2 == -1) {
        __get_dashboard_state();
        __get_dashboard_state();
        __get_dashboard_state();
        pcVar5 = "%s_R_%02X%02X%02X";
LAB_00019676:
        FUN_0008a6b0(&DAT_20010975,0,0x20,(byte *)pcVar5);
        goto LAB_00019594;
      }
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      pcVar5 = "%s_%d_R_%02X%02X%02X";
LAB_00019648:
      FUN_0008a6b0(&DAT_20010975,0,0x20,(byte *)pcVar5);
      goto LAB_00019594;
    }
    pGVar4 = __get_dashboard_state();
    if (pGVar4->field_0x2 == -1) {
      FUN_0008069e();
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      pcVar5 = "%sV%d%d%d_R_%02X%02X%02X";
LAB_00019608:
      FUN_0008a6b0(&DAT_20010975,0,0x20,(byte *)pcVar5);
      goto LAB_00019594;
    }
    FUN_0008069e();
    __get_dashboard_state();
    __get_dashboard_state();
    __get_dashboard_state();
    __get_dashboard_state();
    pcVar5 = "%sV%d%d%d_%d_R_%02X%02X%02X";
  }
  else {
    cVar3 = FUN_00033d5c();
    if (cVar3 != '\x01') {
      pGVar4 = __get_dashboard_state();
      if (pGVar4->field_0x2 == -1) {
        __get_dashboard_state();
        __get_dashboard_state();
        __get_dashboard_state();
        pcVar5 = "%s_L_%02X%02X%02X";
        goto LAB_00019676;
      }
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      pcVar5 = "%s_%d_L_%02X%02X%02X";
      goto LAB_00019648;
    }
    pGVar4 = __get_dashboard_state();
    if (pGVar4->field_0x2 == -1) {
      FUN_0008069e();
      __get_dashboard_state();
      __get_dashboard_state();
      __get_dashboard_state();
      pcVar5 = "%sV%d%d%d_L_%02X%02X%02X";
      goto LAB_00019608;
    }
    FUN_0008069e();
    __get_dashboard_state();
    __get_dashboard_state();
    __get_dashboard_state();
    __get_dashboard_state();
    pcVar5 = "%sV%d%d%d_%d_L_%02X%02X%02X";
  }
  FUN_0008a6b0(&DAT_20010975,0,0x20,(byte *)pcVar5);
LAB_00019594:
  DAT_20002354 = &DAT_20010975;
  sVar6 = ____strlen(&DAT_20010975);
  DAT_20002351 = (undefined1)sVar6;
  iVar7 = bt_set_name(&DAT_20010975);
  if (iVar7 == 0) {
    local_34.id = 0;
    local_34.sid = 0;
    local_34.secondary_max_skip = 0;
    local_34.pad = 0;
    local_34.options = 1;
    local_34.interval_min = 0x160;
    local_34.interval_max = 0x1e0;
    local_34.peer = (undefined *)0x0;
    iVar7 = bt_le_adv_start(&local_34,(bt_data *)&DAT_20002358,2,(bt_data *)&DAT_20002350,1);
    if (iVar7 == 0) {
      pGVar4 = __get_dashboard_state();
      pGVar4->field_0x106c = 2;
      uVar10 = sys_clock_tick_get();
      lVar1 = (uVar10 & 0xffffffff) * 1000;
      uVar9 = (uint)lVar1;
      uVar8 = (int)(uVar10 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20) +
              (uint)(0xffff8000 < uVar9);
      printk("Advertising %s successfully started uptime %lld\n",&DAT_20010975,
             uVar9 + 0x7fff >> 0xf | uVar8 * 0x20000,uVar8 >> 0xf);
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Failed to set device name (err %d)\n\n");
    }
    else {
      ble_printk("%s(): Failed to set device name (err %d)\n\n","bt_start",iVar7,BLE_DEBUG);
    }
  }
  DAT_20010960 = 0;
  return iVar7;
}


