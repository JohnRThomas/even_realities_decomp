/*
 * Function: ancs_c_init
 * Entry:    00019208
 * Prototype: int __stdcall ancs_c_init(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

int ancs_c_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = bt_ancs_client_init((bt_ancs_client *)&GLOBAL_STATE.field_0xec);
  if (iVar1 == 0) {
    iVar1 = bt_ancs_register_attr
                      ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,0,(uint8_t *)(param_1 + 0x10),0x20
                      );
    if (iVar1 == 0) {
      iVar1 = bt_ancs_register_app_attr
                        ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,0,(uint8_t *)(param_1 + 0x30),
                         0x20);
      if (iVar1 == 0) {
        iVar1 = bt_ancs_register_attr
                          ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,1,(uint8_t *)(param_1 + 0x50),
                           0x20);
        if (iVar1 == 0) {
          iVar1 = bt_ancs_register_attr
                            ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,2,
                             (uint8_t *)(param_1 + 0x70),0x20);
          if (iVar1 == 0) {
            iVar1 = bt_ancs_register_attr
                              ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,3,
                               (uint8_t *)(param_1 + 0x90),0x100);
            if (iVar1 == 0) {
              iVar1 = bt_ancs_register_attr
                                ((bt_ancs_client *)&GLOBAL_STATE.field_0xec,5,
                                 (uint8_t *)(param_1 + 400),0x20);
              if (iVar1 == 0) {
                return 0;
              }
              if (LOG_LEVEL < 1) {
                return iVar1;
              }
              if (BLE_DEBUG == 0) {
                uVar2 = 0x3ea;
                goto LAB_0001923c;
              }
              uVar2 = 0x3ea;
            }
            else {
              if (LOG_LEVEL < 1) {
                return iVar1;
              }
              if (BLE_DEBUG == 0) {
                uVar2 = 0x3e2;
LAB_0001923c:
                printk("%s(): %d: err=%d\n","ancs_c_init",uVar2,iVar1,param_4);
                return iVar1;
              }
              uVar2 = 0x3e2;
            }
          }
          else {
            if (LOG_LEVEL < 1) {
              return iVar1;
            }
            if (BLE_DEBUG == 0) {
              uVar2 = 0x3da;
              goto LAB_0001923c;
            }
            uVar2 = 0x3da;
          }
        }
        else {
          if (LOG_LEVEL < 1) {
            return iVar1;
          }
          if (BLE_DEBUG == 0) {
            uVar2 = 0x3d2;
            goto LAB_0001923c;
          }
          uVar2 = 0x3d2;
        }
      }
      else {
        if (LOG_LEVEL < 1) {
          return iVar1;
        }
        if (BLE_DEBUG == 0) {
          uVar2 = 0x3ca;
          goto LAB_0001923c;
        }
        uVar2 = 0x3ca;
      }
    }
    else {
      if (LOG_LEVEL < 1) {
        return iVar1;
      }
      if (BLE_DEBUG == 0) {
        uVar2 = 0x3c2;
        goto LAB_0001923c;
      }
      uVar2 = 0x3c2;
    }
  }
  else {
    if (LOG_LEVEL < 1) {
      return iVar1;
    }
    if (BLE_DEBUG == 0) {
      uVar2 = 0x3ba;
      goto LAB_0001923c;
    }
    uVar2 = 0x3ba;
  }
  ble_printk("%s(): %d: err=%d\n","ancs_c_init",uVar2,iVar1);
  return iVar1;
}


