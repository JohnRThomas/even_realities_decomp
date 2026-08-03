/*
 * Function: os_mgmt_reset_work_handler
 * Entry:    00084250
 * Prototype: void __stdcall os_mgmt_reset_work_handler(k_work * work)
 */


/* exclude_from_export */

void os_mgmt_reset_work_handler(k_work *work)

{
                    /* WARNING: Subroutine does not return */
  sys_reboot(0);
}


