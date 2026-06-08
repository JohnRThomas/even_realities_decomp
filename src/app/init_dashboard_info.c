/*
 * Function: init_dashboard_info
 * Entry:    00038940
 * Prototype: undefined __stdcall init_dashboard_info(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void init_dashboard_info(void)

{
  int iVar2;
  GlassesState *pGVar3;
  char *fmt;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  global_state_struct_0FF0 *iVar1;
  int iVar6;
  global_state_struct_0FF0 *pgVar7;
  uint uVar8;
  
  iVar2 = is_ncs_mem_initialized();
  if (iVar2 == 0) {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): system startup ,NCS memory is vaild\n");
      }
      else {
        ble_printk("%s(): system startup ,NCS memory is vaild\n","init_dashboard_info",extraout_r2,
                   BLE_DEBUG);
      }
    }
    FUN_000166f8();
  }
  else {
    if (2 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): system startup ,NCS memory is invaild\n");
      }
      else {
        ble_printk("%s(): system startup ,NCS memory is invaild\n","init_dashboard_info",extraout_r2
                   ,BLE_DEBUG);
      }
    }
    pGVar3 = __get_dashboard_state();
    pgVar7 = pGVar3->glasses_state_struct_0FF0;
    *(undefined1 *)pgVar7 = 0x80;
    pgVar7->field_0x2 = 0x92;
    pgVar7->field_0x1 = 0;
    pgVar7->field_0x3 = 0x65;
    pGVar3 = __get_dashboard_state();
    iVar1 = pGVar3->glasses_state_struct_0FF0;
    iVar1->field6_0x6 = 0;
    iVar1->field7_0x7 = 0xf4;
    iVar1->field8_0x8 = 0x51;
    iVar1->field9_0x9 = 0xc2;
    iVar1->field10_0xa = 0x8c;
    iVar1->field12_0xc = 0;
    iVar1->field11_0xb = 1;
    iVar1->field13_0xd = 0;
    pGVar3 = __get_dashboard_state();
    pgVar7 = pGVar3->glasses_state_struct_0FF0;
    uVar4._0_1_ = pgVar7->field6_0x6;
    uVar4._1_1_ = pgVar7->field7_0x7;
    uVar4._2_1_ = pgVar7->field8_0x8;
    uVar4._3_1_ = pgVar7->field9_0x9;
    uVar5._0_1_ = pgVar7->field10_0xa;
    uVar5._1_1_ = pgVar7->field11_0xb;
    uVar5._2_1_ = pgVar7->field12_0xc;
    uVar5._3_1_ = pgVar7->field13_0xd;
    FUN_0004d4dc(uVar4,uVar5);
  }
  iVar2 = 4;
  uVar8 = 0;
  do {
    pGVar3 = __get_dashboard_state();
    iVar6 = *(int *)&pGVar3->field_0x1030;
    pGVar3 = __get_dashboard_state();
    iVar6 = getQuickNoteDataFromFlash
                      (uVar8,(void *)(iVar6 + iVar2),0x29,
                       (void *)(iVar2 + 0x29 + *(int *)&pGVar3->field_0x1030),0x119);
    if (iVar6 == -1) {
      pGVar3 = __get_dashboard_state();
      *(undefined1 *)(uVar8 * 0x143 + *(int *)&pGVar3->field_0x1030 + 3) = 0;
      if (2 < LOG_LEVEL) {
        fmt = "%s(): QuickNote %d is invaild,don\'t export\n";
LAB_000389c8:
        if (BLE_DEBUG == 0) {
          printk(fmt);
        }
        else {
          ble_printk(fmt,"init_dashboard_info",uVar8,BLE_DEBUG);
        }
      }
    }
    else if (iVar6 == 0) {
      pGVar3 = __get_dashboard_state();
      *(undefined1 *)(uVar8 * 0x143 + *(int *)&pGVar3->field_0x1030 + 3) = 1;
      if (2 < LOG_LEVEL) {
        fmt = "%s(): success export quicknote text from flash,quicknote index = %d\n";
        goto LAB_000389c8;
      }
    }
    else if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): !!!! getQuickNoteDataFromFlash return unknown value.\n");
      }
      else {
        ble_printk("%s(): !!!! getQuickNoteDataFromFlash return unknown value.\n",
                   "init_dashboard_info",extraout_r2_00,BLE_DEBUG);
      }
    }
    uVar8 = uVar8 + 1;
    iVar2 = iVar2 + 0x143;
    if (uVar8 == 4) {
      return;
    }
  } while( true );
}


