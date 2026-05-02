/*
 * Function: display_reflash_handler
 * Entry:    0004c238
 * Prototype: undefined4 __stdcall display_reflash_handler(int param_1, uint param_2, char * param_3, uint param_4)
 */


undefined4 display_reflash_handler(int param_1,uint param_2,char *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (uint)DAT_2001e1bc;
  if (param_4 == 2) {
    if ((param_2 != uVar1) && (uVar1 != 0)) {
      if (0 < LOG_LEVEL) {
        iVar2 = param_1;
        uVar1 = param_2;
        if (BLE_DEBUG == 0) {
          printk("%s(): !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
        }
        else {
          ble_printk("%s(): !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n",
                     "display_reflash_handler",param_3,BLE_DEBUG);
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): The wrong screen ID has appeared, and the exception handling is closed,The message ID at startup is %d. The current message ID is%d\n"
                   ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2,iVar2,uVar1);
          }
          else {
            ble_printk("%s(): The wrong screen ID has appeared, and the exception handling is closed,The message ID at startup is %d. The current message ID is%d\n"
                       ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2);
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): To perform exception handling, close the previous SCREEN ID = %d UI application first\n"
                    );
            }
            else {
              ble_printk("%s(): To perform exception handling, close the previous SCREEN ID = %d UI application first\n"
                         ,"display_reflash_handler",(uint)DAT_2001e1bc,BLE_DEBUG);
            }
          }
        }
      }
      __ui_task_handler(param_1,param_2,param_3,2);
      return 0xffffffff;
    }
  }
  else if (param_4 == 1) {
    if ((param_2 != uVar1) && (uVar1 != 0)) {
      if (0 < LOG_LEVEL) {
        uVar1 = param_2;
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): ----------------------------------------------------------------------------------------\n"
                );
        }
        else {
          ble_printk("%s(): ----------------------------------------------------------------------------------------\n"
                     ,"display_reflash_handler",param_3,BLE_DEBUG);
        }
        if (0 < LOG_LEVEL) {
          if (BLE_DEBUG == 0) {
            printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                   ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2,1,uVar1);
          }
          else {
            ble_printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                       ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2);
          }
          if (0 < LOG_LEVEL) {
            if (BLE_DEBUG == 0) {
              printk(
                    "%s(): The UI framework closes the opened UI application first, and the closed application ScreenID is %d\n"
                    );
            }
            else {
              ble_printk("%s(): The UI framework closes the opened UI application first, and the closed application ScreenID is %d\n"
                         ,"display_reflash_handler",(uint)DAT_2001e1bc,BLE_DEBUG);
            }
          }
        }
      }
      __ui_task_handler(param_1,(uint)DAT_2001e1bc,param_3,2);
      if (0 < LOG_LEVEL) {
        if (BLE_DEBUG == 0) {
          printk(
                "%s(): Because ScreenID has changed, close the old screenID application first and update the backup value of screenID to %d\n"
                );
        }
        else {
          ble_printk("%s(): Because ScreenID has changed, close the old screenID application first and update the backup value of screenID to %d\n"
                     ,"display_reflash_handler",param_2,BLE_DEBUG);
        }
      }
      DAT_2001e1bc = (byte)param_2;
    }
  }
  else if ((param_2 != uVar1) && (0 < LOG_LEVEL)) {
    uVar1 = param_2;
    if (BLE_DEBUG == 0) {
      printk(
            "%s(): *************************************************************************************************\n"
            );
    }
    else {
      ble_printk("%s(): *************************************************************************************************\n"
                 ,"display_reflash_handler",param_3,BLE_DEBUG);
    }
    if (0 < LOG_LEVEL) {
      if (BLE_DEBUG == 0) {
        printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
               ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2,param_4,uVar1);
      }
      else {
        ble_printk("%s(): There is a screen ID error. The previous screen iD was %d, the current screen ID is %d, and the UI process to be performed is %d\n"
                   ,"display_reflash_handler",(uint)DAT_2001e1bc,param_2);
      }
    }
  }
  __ui_task_handler(param_1,param_2,param_3,param_4);
  return 0;
}


