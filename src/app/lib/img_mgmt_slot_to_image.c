/*
 * Function: img_mgmt_slot_to_image
 * Entry:    00054f14
 * Prototype: int __stdcall img_mgmt_slot_to_image(int slot)
 */


/* exclude_from_export_ai */

int img_mgmt_slot_to_image(int slot)

{
  char *test;
  char *file;
  int line;
  
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","slot >= 0 && slot < (2 << 1)",
          "WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/grp/img_mgmt/include/mgmt/mcumgr/grp/img_mgmt/img_mgmt_priv.h"
          ,98);
  _ASSERT("\tImpossible slot number\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


