/*
 * Function: display_reflash_handler
 * Entry:    0004c238
 * Prototype: undefined4 __stdcall display_reflash_handler(GlassesState * param_1, uint new_screen_id, undefined4 param_3, uint param_4)
 */


undefined4
display_reflash_handler(GlassesState *param_1,uint new_screen_id,undefined4 param_3,uint param_4)

{
  uint uVar1;
  GlassesState *pGVar2;
  
  uVar1 = (uint)__SCREEN_ID;
  if (param_4 == 2) {
    if ((new_screen_id != uVar1) && (uVar1 != 0)) {
      if (0 < LOG_LEVEL) {
        pGVar2 = param_1;
        uVar1 = new_screen_id;
        if (BLE_DEBUG == 0) {
          printk("%s(): !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n","display_reflash_handler",
                 param_3,0,param_1,new_screen_id);
        }
        else {
          ble_printk("%s(): !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): The wrong screen ID has appeared, and the exception handling is closed,The message ID at startup is %d. The current message ID is%d\n"
                   ,"display_reflash_handler",(uint)__SCREEN_ID,new_screen_id,pGVar2,uVar1);
          }
          else {
            ble_printk("%s(): The wrong screen ID has appeared, and the exception handling is closed,The message ID at startup is %d. The current message ID is%d\n"
                       ,"display_reflash_handler",(uint)__SCREEN_ID,new_screen_id);
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): To perform exception handling, close the previous SCREEN ID = %d UI application first\n"
                     ,"display_reflash_handler",(uint)__SCREEN_ID,0,pGVar2,uVar1);
            }
            else {
              ble_printk(
                        "%s(): To perform exception handling, close the previous SCREEN ID = %d UI application first\n"
                        );
            }
          }
        }
      }
      __ui_task_handler(param_1,new_screen_id,param_3,2);
      return 0xffffffff;
    }
  }
  else if (param_4 == 1) {
    if ((new_screen_id != uVar1) && (uVar1 != 0)) {
      pGVar2 = param_1;
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): ----------------------------------------------------------------------------------------\n"
                 ,"display_reflash_handler",param_3,0,param_1,new_screen_id);
        }
        else {
          ble_printk(
                    "%s(): ----------------------------------------------------------------------------------------\n"
                    );
        }
        if (0 < LOG_LEVEL) {
          pGVar2 = (GlassesState *)&DAT_00000001;
          if (BLE_DEBUG == 0) {
            printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                   ,"display_reflash_handler",(uint)__SCREEN_ID,new_screen_id,1);
          }
          else {
            ble_printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                       ,"display_reflash_handler");
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk("%s(): The UI framework closes the opened UI application first, and the closed application ScreenID is %d\n"
                     ,"display_reflash_handler",(uint)__SCREEN_ID,0,pGVar2);
            }
            else {
              ble_printk(
                        "%s(): The UI framework closes the opened UI application first, and the closed application ScreenID is %d\n"
                        );
            }
          }
        }
      }
      __ui_task_handler(param_1,(uint)__SCREEN_ID,param_3,2);
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk("%s(): Because ScreenID has changed, close the old screenID application first and update the backup value of screenID to %d\n"
                 ,"display_reflash_handler",new_screen_id,0,pGVar2);
        }
        else {
          ble_printk(
                    "%s(): Because ScreenID has changed, close the old screenID application first and update the backup value of screenID to %d\n"
                    );
        }
      }
      __SCREEN_ID = (byte)new_screen_id;
    }
  }
  else if ((new_screen_id != uVar1) && (0 < LOG_LEVEL)) {
    if (BLE_DEBUG == 0) {
      printk("%s(): *************************************************************************************************\n"
             ,"display_reflash_handler",param_3,0,param_1,new_screen_id);
    }
    else {
      ble_printk(
                "%s(): *************************************************************************************************\n"
                );
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
               ,"display_reflash_handler",(uint)__SCREEN_ID,new_screen_id,param_4);
      }
      else {
        ble_printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                   ,"display_reflash_handler",(uint)__SCREEN_ID,new_screen_id);
      }
    }
  }
  __ui_task_handler(param_1,new_screen_id,param_3,param_4);
  return 0;
}


