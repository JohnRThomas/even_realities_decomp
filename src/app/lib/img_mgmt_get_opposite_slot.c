/*
 * Function: img_mgmt_get_opposite_slot
 * Entry:    00054ee4
 * Prototype: int __stdcall img_mgmt_get_opposite_slot(int slot)
 */


/* exclude_from_export_ai */

int img_mgmt_get_opposite_slot(int slot)

{
  char *test;
  char *file;
  int line;
  
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","slot >= 0 && slot < (2 << 1)",
          "WEST_TOPDIR/zephyr/subsys/mgmt/mcumgr/grp/img_mgmt/include/mgmt/mcumgr/grp/img_mgmt/img_mgmt_priv.h"
          ,0x71);
  _ASSERT("\tImpossible slot number\n",test,file,line);
                    /* WARNING: Subroutine does not return */
  k_panic();
}


