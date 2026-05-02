/*
 * Function: deal_event_to_phone
 * Entry:    00022448
 * Prototype: undefined4 __stdcall deal_event_to_phone(int param_1, undefined2 * param_2)
 */


undefined4 deal_event_to_phone(int param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined4 extraout_r2;
  undefined1 uVar4;
  undefined4 local_28;
  undefined1 local_24 [20];
  
  local_28 = 0;
  memset(local_24,0,0x11);
  uVar2 = DAT_20019a68;
  uVar1 = DAT_20019a67;
  bVar3 = *(byte *)((int)param_2 + 1);
  if (0x12 < bVar3) {
    if (bVar3 == 0xf1) {
      local_28._0_2_ = 0xc90f;
LAB_000224dc:
      uVar4 = *(undefined1 *)(param_1 + -0x6b0);
LAB_000224b2:
      local_28._0_3_ = CONCAT12(uVar4,(undefined2)local_28);
      DAT_20019a68 = 0;
      local_28 = CONCAT13(uVar2,(undefined3)local_28);
      DAT_20019a67 = 0;
      local_24[0] = uVar1;
    }
    else {
      if (bVar3 < 0xf2) {
        if (bVar3 == 0x1e) {
          if (1 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): send dashboard start...\n");
            }
            else {
              ble_printk("%s(): send dashboard start...\n","deal_event_to_phone",extraout_r2,
                         BLE_DEBUG);
            }
          }
        }
        else if (bVar3 == 0xf0) {
          local_28._0_2_ = 0xc90d;
          uVar4 = *(undefined1 *)(param_1 + -0x6af);
          goto LAB_000224b2;
        }
      }
      else if (bVar3 == 0xf2) {
        local_28._0_2_ = 0xc94e;
        goto LAB_000224dc;
      }
switchD_0002246e_caseD_b:
      local_28._0_2_ = CONCAT11(*(undefined1 *)((int)param_2 + 1),0xf5);
    }
    goto LAB_000224ca;
  }
  switch(bVar3) {
  case 9:
    bVar3 = *(byte *)(param_2 + 1);
    local_28 = CONCAT22(local_28._2_2_,*param_2);
    break;
  case 10:
    local_28 = CONCAT22(local_28._2_2_,0xaf5);
    bVar3 = *(byte *)(param_1 + 0x848);
    if (bVar3 == 0x5d) {
      if (*(char *)(param_1 + 0x84a) == '\0') {
        bVar3 = 0x5e;
      }
      else {
        bVar3 = 0x5f;
      }
    }
    else if (bVar3 == 0x5e) {
      if (*(char *)(param_1 + 0x84a) == '\0') {
        bVar3 = 0x60;
      }
      else {
        bVar3 = 0x61;
      }
    }
    else if (bVar3 == 0x5f) {
      bVar3 = 0x62;
    }
    else if (bVar3 == 0x60) {
      bVar3 = 99;
    }
    else if (0x60 < bVar3) {
      bVar3 = 100;
    }
    break;
  default:
    goto switchD_0002246e_caseD_b;
  case 0xe:
    local_28 = CONCAT22(local_28._2_2_,0xef5);
    bVar3 = FUN_00033754();
    goto LAB_00022504;
  case 0xf:
    local_28 = CONCAT22(local_28._2_2_,0xff5);
    bVar3 = FUN_00033760();
LAB_00022504:
    local_28._0_3_ = CONCAT12(bVar3,(undefined2)local_28);
    goto LAB_000224ca;
  case 0x12:
    local_28 = CONCAT22(local_28._2_2_,0x12f5);
    bVar3 = *(byte *)(param_1 + 0x759);
  }
  local_28._0_3_ = CONCAT12(bVar3,(undefined2)local_28);
LAB_000224ca:
  (**(code **)(param_1 + 0xc))(&local_28,0x15);
  return 0;
}


