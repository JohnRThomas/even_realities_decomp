/*
 * Function: bt_start
 * Entry:    000194b4
 * Prototype: int __stdcall bt_start(void)
 */


int bt_start(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  longlong lVar5;
  bool bVar6;
  char cVar7;
  GlassesState *pGVar8;
  char *pcVar9;
  undefined4 uVar10;
  size_t sVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  ulonglong uVar15;
  bt_le_adv_param local_34;
  
  while (DAT_20010960 != '\0') {
    sleep(1);
  }
  DAT_20010960 = 1;
  pGVar8 = __get_dashboard_state();
  if ((pGVar8->field_0x106c == '\x02') ||
     (pGVar8 = __get_dashboard_state(), pGVar8->field_0x106c == '\0')) {
    DAT_20010960 = 0;
    return 0;
  }
  DAT_20002360 = 0x14ff;
  bVar6 = __is_master();
  if (bVar6) {
    DAT_20010961 = 1;
  }
  else {
    DAT_20010961 = 2;
  }
  DAT_20002364 = &DAT_20010961;
  pcVar9 = get_serial_number();
  __strcpy_chk(&DAT_20010962,pcVar9,0x13);
  pGVar8 = __get_dashboard_state();
  printk("c->esb_channel %d\r\n",(uint)(byte)pGVar8->esb_channel);
  bVar6 = __is_master();
  if (bVar6) {
    cVar7 = FUN_00033d5c();
    if (cVar7 != '\x01') {
      pGVar8 = __get_dashboard_state();
      if (pGVar8->esb_channel == -1) {
        pGVar8 = __get_dashboard_state();
        bVar3 = pGVar8->field_0xfe0;
        pGVar8 = __get_dashboard_state();
        bVar4 = pGVar8->field_0xfdf;
        pGVar8 = __get_dashboard_state();
        bVar1 = pGVar8->field_0xfde;
        pcVar9 = "%s_R_%02X%02X%02X";
LAB_00019676:
        __sprintf_chk(&DAT_20010975,0,0x20,pcVar9,"Even G1",(uint)bVar3,(uint)bVar4,(uint)bVar1);
        goto LAB_00019594;
      }
      pGVar8 = __get_dashboard_state();
      bVar1 = pGVar8->esb_channel;
      pGVar8 = __get_dashboard_state();
      bVar2 = pGVar8->field_0xfe0;
      pGVar8 = __get_dashboard_state();
      bVar3 = pGVar8->field_0xfdf;
      pGVar8 = __get_dashboard_state();
      bVar4 = pGVar8->field_0xfde;
      pcVar9 = "%s_%d_R_%02X%02X%02X";
LAB_00019648:
      __sprintf_chk(&DAT_20010975,0,0x20,pcVar9,"Even G1",(uint)bVar1,(uint)bVar2,(uint)bVar3,
                    (uint)bVar4);
      goto LAB_00019594;
    }
    pGVar8 = __get_dashboard_state();
    if (pGVar8->esb_channel == -1) {
      uVar10 = FUN_0008069e();
      pGVar8 = __get_dashboard_state();
      bVar3 = pGVar8->field_0xfe0;
      pGVar8 = __get_dashboard_state();
      bVar4 = pGVar8->field_0xfdf;
      pGVar8 = __get_dashboard_state();
      bVar1 = pGVar8->field_0xfde;
      pcVar9 = "%sV%d%d%d_R_%02X%02X%02X";
LAB_00019608:
      __sprintf_chk(&DAT_20010975,0,0x20,pcVar9,"Even G1",uVar10,6,3,(uint)bVar3,(uint)bVar4,
                    (uint)bVar1);
      goto LAB_00019594;
    }
    uVar10 = FUN_0008069e();
    pGVar8 = __get_dashboard_state();
    bVar1 = pGVar8->esb_channel;
    pGVar8 = __get_dashboard_state();
    bVar2 = pGVar8->field_0xfe0;
    pGVar8 = __get_dashboard_state();
    bVar3 = pGVar8->field_0xfdf;
    pGVar8 = __get_dashboard_state();
    bVar4 = pGVar8->field_0xfde;
    pcVar9 = "%sV%d%d%d_%d_R_%02X%02X%02X";
  }
  else {
    cVar7 = FUN_00033d5c();
    if (cVar7 != '\x01') {
      pGVar8 = __get_dashboard_state();
      if (pGVar8->esb_channel == -1) {
        pGVar8 = __get_dashboard_state();
        bVar3 = pGVar8->field_0xfe6;
        pGVar8 = __get_dashboard_state();
        bVar4 = pGVar8->field_0xfe5;
        pGVar8 = __get_dashboard_state();
        bVar1 = pGVar8->field_0xfe4;
        pcVar9 = "%s_L_%02X%02X%02X";
        goto LAB_00019676;
      }
      pGVar8 = __get_dashboard_state();
      bVar1 = pGVar8->esb_channel;
      pGVar8 = __get_dashboard_state();
      bVar2 = pGVar8->field_0xfe6;
      pGVar8 = __get_dashboard_state();
      bVar3 = pGVar8->field_0xfe5;
      pGVar8 = __get_dashboard_state();
      bVar4 = pGVar8->field_0xfe4;
      pcVar9 = "%s_%d_L_%02X%02X%02X";
      goto LAB_00019648;
    }
    pGVar8 = __get_dashboard_state();
    if (pGVar8->esb_channel == -1) {
      uVar10 = FUN_0008069e();
      pGVar8 = __get_dashboard_state();
      bVar3 = pGVar8->field_0xfe6;
      pGVar8 = __get_dashboard_state();
      bVar4 = pGVar8->field_0xfe5;
      pGVar8 = __get_dashboard_state();
      bVar1 = pGVar8->field_0xfe4;
      pcVar9 = "%sV%d%d%d_L_%02X%02X%02X";
      goto LAB_00019608;
    }
    uVar10 = FUN_0008069e();
    pGVar8 = __get_dashboard_state();
    bVar1 = pGVar8->esb_channel;
    pGVar8 = __get_dashboard_state();
    bVar2 = pGVar8->field_0xfe6;
    pGVar8 = __get_dashboard_state();
    bVar3 = pGVar8->field_0xfe5;
    pGVar8 = __get_dashboard_state();
    bVar4 = pGVar8->field_0xfe4;
    pcVar9 = "%sV%d%d%d_%d_L_%02X%02X%02X";
  }
  __sprintf_chk(&DAT_20010975,0,0x20,pcVar9,"Even G1",uVar10,6,3,(uint)bVar1,(uint)bVar2,(uint)bVar3
                ,(uint)bVar4);
LAB_00019594:
  DAT_20002354 = &DAT_20010975;
  sVar11 = strlen(&DAT_20010975);
  DAT_20002351 = (undefined1)sVar11;
  iVar12 = bt_set_name(&DAT_20010975);
  if (iVar12 == 0) {
    local_34.id = 0;
    local_34.sid = 0;
    local_34.secondary_max_skip = 0;
    local_34.pad = 0;
    local_34.options = 1;
    local_34.interval_min = 0x160;
    local_34.interval_max = 0x1e0;
    local_34.peer = (undefined *)0x0;
    iVar12 = bt_le_adv_start(&local_34,(bt_data *)&DAT_20002358,2,(bt_data *)&DAT_20002350,1);
    if (iVar12 == 0) {
      pGVar8 = __get_dashboard_state();
      pGVar8->field_0x106c = 2;
      uVar15 = sys_clock_tick_get();
      lVar5 = (uVar15 & 0xffffffff) * 1000;
      uVar14 = (uint)lVar5;
      uVar13 = (int)(uVar15 >> 0x20) * 1000 + (int)((ulonglong)lVar5 >> 0x20) +
               (uint)(0xffff8000 < uVar14);
      printk("Advertising %s successfully started uptime %lld\n",&DAT_20010975,
             uVar14 + 0x7fff >> 0xf | uVar13 * 0x20000,uVar13 >> 0xf);
    }
  }
  else if (0 < LOG_LEVEL) {
    if (BLE_DEBUG == 0) {
      printk("%s(): Failed to set device name (err %d)\n\n");
    }
    else {
      ble_printk("%s(): Failed to set device name (err %d)\n\n","bt_start",iVar12,BLE_DEBUG);
    }
  }
  DAT_20010960 = 0;
  return iVar12;
}


